#pragma once

#if defined(_MSC_VER)
#define ALIGNED(x) __declspec(align(x))
#else
#if defined(__GNUC__)
#define ALIGNED(x) __attribute__((aligned(x)))
#endif
#endif

#define AVX512_ALIGNEMENT ALIGNED(64)

namespace dyrs::avx512::tables {

// used by node128
static const int64_t update_8_64[8 * 8 * 2] AVX512_ALIGNEMENT = {

    0, +1, +1, +1, +1, +1, +1, +1, 0, 0, +1, +1, +1, +1, +1, +1, 0,
    0, 0,  +1, +1, +1, +1, +1, 0,  0, 0, 0,  +1, +1, +1, +1, 0,  0,
    0, 0,  0,  +1, +1, +1, 0,  0,  0, 0, 0,  0,  +1, +1, 0,  0,  0,
    0, 0,  0,  0,  +1, 0,  0,  0,  0, 0, 0,  0,  0,

    0, -1, -1, -1, -1, -1, -1, -1, 0, 0, -1, -1, -1, -1, -1, -1, 0,
    0, 0,  -1, -1, -1, -1, -1, 0,  0, 0, 0,  -1, -1, -1, -1, 0,  0,
    0, 0,  0,  -1, -1, -1, 0,  0,  0, 0, 0,  0,  -1, -1, 0,  0,  0,
    0, 0,  0,  0,  -1, 0,  0,  0,  0, 0, 0,  0,  0

};

// used by node512, node256, node128
static const int32_t update_16_32[(16 + 1) * 16 * 2] AVX512_ALIGNEMENT = {

    +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, 0,  +1, +1,
    +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, 0,  0,  +1, +1, +1, +1,
    +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, 0,  0,  0,  +1, +1, +1, +1, +1, +1,
    +1, +1, +1, +1, +1, +1, +1, 0,  0,  0,  0,  +1, +1, +1, +1, +1, +1, +1, +1,
    +1, +1, +1, +1, 0,  0,  0,  0,  0,  +1, +1, +1, +1, +1, +1, +1, +1, +1, +1,
    +1, 0,  0,  0,  0,  0,  0,  +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, 0,  0,
    0,  0,  0,  0,  0,  +1, +1, +1, +1, +1, +1, +1, +1, +1, 0,  0,  0,  0,  0,
    0,  0,  0,  +1, +1, +1, +1, +1, +1, +1, +1, 0,  0,  0,  0,  0,  0,  0,  0,
    0,  +1, +1, +1, +1, +1, +1, +1, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  +1,
    +1, +1, +1, +1, +1, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  +1, +1, +1,
    +1, +1, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  +1, +1, +1, +1, 0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  +1, +1, +1, 0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  +1, +1, 0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  +1, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,

    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0,  -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0,  0,  -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0,  0,  0,  -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, 0,  0,  0,  0,  -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, 0,  0,  0,  0,  0,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, 0,  0,  0,  0,  0,  0,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0,  0,
    0,  0,  0,  0,  0,  -1, -1, -1, -1, -1, -1, -1, -1, -1, 0,  0,  0,  0,  0,
    0,  0,  0,  -1, -1, -1, -1, -1, -1, -1, -1, 0,  0,  0,  0,  0,  0,  0,  0,
    0,  -1, -1, -1, -1, -1, -1, -1, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,
    -1, -1, -1, -1, -1, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1, -1, -1,
    -1, -1, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1, -1, -1, -1, 0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1, -1, -1, 0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1, -1, 0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  -1, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0

};

// used by node512
static const int16_t update_32_16[32 * 32 * 2] AVX512_ALIGNEMENT = {

    +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1,
    +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, 0,  +1, +1, +1, +1, +1,
    +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1,
    +1, +1, +1, +1, +1, +1, +1, 0,  0,  +1, +1, +1, +1, +1, +1, +1, +1, +1, +1,
    +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1,
    +1, 0,  0,  0,  +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1,
    +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, 0,  0,  0,  0,  +1,
    +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1,
    +1, +1, +1, +1, +1, +1, +1, +1, 0,  0,  0,  0,  0,  +1, +1, +1, +1, +1, +1,
    +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1,
    +1, +1, 0,  0,  0,  0,  0,  0,  +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1,
    +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, 0,  0,  0,  0,
    0,  0,  0,  +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1,
    +1, +1, +1, +1, +1, +1, +1, +1, +1, 0,  0,  0,  0,  0,  0,  0,  0,  +1, +1,
    +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1,
    +1, +1, +1, 0,  0,  0,  0,  0,  0,  0,  0,  0,  +1, +1, +1, +1, +1, +1, +1,
    +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, 0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1,
    +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, 0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1,
    +1, +1, +1, +1, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  +1, +1, +1,
    +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, 0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  +1, +1, +1, +1, +1, +1, +1, +1,
    +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, 0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1,
    +1, +1, +1, +1, +1, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, 0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  +1, +1, +1, +1,
    +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, 0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  +1, +1, +1, +1, +1, +1, +1, +1, +1,
    +1, +1, +1, +1, +1, +1, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, 0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  +1, +1, +1, +1, +1,
    +1, +1, +1, +1, +1, +1, +1, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  +1, +1, +1, +1, +1, +1, +1, +1, +1, +1,
    +1, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  +1, +1, +1, +1, +1, +1, +1, +1, +1, +1, 0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  +1,
    +1, +1, +1, +1, +1, +1, +1, +1, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  +1, +1, +1, +1, +1, +1,
    +1, +1, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  +1, +1, +1, +1, +1, +1, +1, 0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  +1, +1, +1, +1, +1, +1, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  +1, +1,
    +1, +1, +1, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  +1, +1, +1, +1, 0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  +1, +1, +1, 0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  +1, +1, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  +1,

    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0,  -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, 0,  0,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, 0,  0,  0,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0,  0,  0,  0,  -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, 0,  0,  0,  0,  0,  -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, 0,  0,  0,  0,  0,  0,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0,  0,  0,  0,
    0,  0,  0,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, 0,  0,  0,  0,  0,  0,  0,  0,  -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, 0,  0,  0,  0,  0,  0,  0,  0,  0,  -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1,
    -1, -1, -1, -1, -1, -1, -1, -1, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1, -1, -1, -1, -1, -1,
    -1, -1, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  -1, -1, -1, -1, -1, -1, -1, 0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  -1, -1, -1, -1, -1, -1, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1, -1,
    -1, -1, -1, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1, -1, -1, -1, 0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  -1, -1, -1, 0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  -1, -1, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  -1

};

}  // namespace dyrs::avx512::tables