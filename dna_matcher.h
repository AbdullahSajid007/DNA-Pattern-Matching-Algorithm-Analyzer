#ifndef DNA_MATCHER_H
#define DNA_MATCHER_H

#include <cstdint>
#include <string>
#include <vector>

namespace dna {

    using Index = uint32_t;

    // Encode DNA string into 2-bit packed format
    uint8_t* encodeDNA(const std::string& s, size_t& packedSize);

    // Free allocated DNA
    void freeDNA(uint8_t* dna);

    // Naive pattern matching (bit-aware)
    void naive(
        const uint8_t* text,
        const uint8_t* pattern,
        size_t n,
        size_t m,
        std::vector<Index>& matches
    );

    // KMP
    void kmp(
        const uint8_t* text,
        const uint8_t* pattern,
        size_t n,
        size_t m,
        std::vector<Index>& matches
    );

}

#endif
