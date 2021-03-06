#pragma once

#include <cassert>

#include "immintrin.h"
#include "tables.hpp"
#include "search_common.hpp"
#include "util.hpp"

namespace dyrs::avx2 {

struct node128 {
    typedef uint16_t key_type;
    typedef uint32_t summary_type;
    static constexpr uint64_t fanout = 128;
    static constexpr uint64_t segment_size = 16;
    static constexpr uint64_t num_segments = 8;
    static constexpr uint64_t bytes =
        fanout * sizeof(key_type) + num_segments * sizeof(summary_type);

    node128() {}

    static void build(key_type const* input, uint8_t* out) {
        build_node_prefix_sums<summary_type, key_type>(input, out, segment_size,
                                                       num_segments, bytes);
    }

    static std::string name() {
        return "avx2::node128";
    }

    node128(uint8_t* ptr) {
        at(ptr);
    }

    inline void at(uint8_t* ptr) {
        summary = reinterpret_cast<summary_type*>(ptr);
        keys = reinterpret_cast<key_type*>(ptr +
                                           num_segments * sizeof(summary_type));
    }

    void update(uint64_t i, bool sign) {
        if (i == fanout) return;
        assert(i < fanout);
        uint64_t j = i / segment_size;
        uint64_t k = i % segment_size;
#ifdef DISABLE_AVX
        int8_t delta = sign ? -1 : +1;
        for (uint64_t z = j + 1; z != num_segments; ++z) summary[z] += delta;
        for (uint64_t z = k, base = j * segment_size; z != segment_size; ++z) {
            keys[base + z] += delta;
        }
#else
        __m256i s1 = _mm256_load_si256((__m256i const*)tables::update_8_32 + j +
                                       1 + sign * (num_segments + 1));
        __m256i r1 =
            _mm256_add_epi32(_mm256_load_si256((__m256i const*)summary), s1);
        _mm256_storeu_si256((__m256i*)summary, r1);
        __m256i s2 = _mm256_load_si256((__m256i const*)tables::update_16_16 +
                                       k + sign * segment_size);
        __m256i r2 = _mm256_add_epi16(
            _mm256_loadu_si256((__m256i const*)(keys + j * segment_size)), s2);
        _mm256_storeu_si256((__m256i*)(keys + j * segment_size), r2);
#endif
    }

    uint64_t sum(uint64_t i) const {
        assert(i < fanout);
        return summary[i / segment_size] + keys[i];
    }

    /* return the smallest i in [0,fanout-1] such that sum(i) > x;
       in this case x is always < sum(fanout-1) by assumption */
    search_result search(uint64_t x) const {
        assert(x < sum(fanout - 1));
        uint64_t i = 0;
#ifdef DISABLE_AVX
        for (uint64_t z = 1; z != num_segments; ++z, ++i) {
            if (summary[z] > x) break;
        }
        assert(i < num_segments);
        x -= summary[i];
        i *= segment_size;
        for (uint64_t z = 0; z != segment_size; ++z, ++i) {
            if (keys[i] > x) break;
        }
#else
        __m256i cmp1 = _mm256_cmpgt_epi32(
            _mm256_loadu_si256((__m256i const*)summary), _mm256_set1_epi32(x));
        i = index_fs<32>(cmp1) - 1;
        assert(i < num_segments);
        x -= summary[i];
        i *= segment_size;
        __m256i cmp2 =
            _mm256_cmpgt_epi16(_mm256_loadu_si256((__m256i const*)(keys + i)),
                               _mm256_set1_epi16(x));
        i += index_fs<16>(cmp2);
#endif
        assert(i < fanout);
        return {i, i ? sum(i - 1) : 0};
    }

private:
    summary_type* summary;
    key_type* keys;
};

}  // namespace dyrs::avx2