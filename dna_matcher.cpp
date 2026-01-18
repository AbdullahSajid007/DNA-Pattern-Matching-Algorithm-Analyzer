#include "dna_matcher.h"
#include <cstring>
#include <algorithm>

namespace dna {

inline uint8_t encodeBase(char c) {
    switch (c) {
        case 'A': return 0;
        case 'C': return 1;
        case 'G': return 2;
        case 'T': return 3;
        default:  return 0;
    }
}

uint8_t* encodeDNA(const std::string& s, size_t& packedSize) {
    packedSize = (s.size() + 3) / 4;
    uint8_t* data = new uint8_t[packedSize]{0};

    for (size_t i = 0; i < s.size(); ++i) {
        data[i / 4] |= encodeBase(s[i]) << (6 - 2 * (i % 4));
    }
    return data;
}

void freeDNA(uint8_t* dna) {
    delete[] dna;
}

inline uint8_t getBase(const uint8_t* dna, size_t i) {
    return (dna[i / 4] >> (6 - 2 * (i % 4))) & 0x03;
}

void naive(
    const uint8_t* text,
    const uint8_t* pattern,
    size_t n,
    size_t m,
    std::vector<Index>& matches
) {
    for (size_t i = 0; i + m <= n; ++i) {
        size_t j = 0;
        while (j < m && getBase(text, i + j) == getBase(pattern, j)) {
            ++j;
        }
        if (j == m) matches.push_back(i);
    }
}

void kmp(
    const uint8_t* text,
    const uint8_t* pattern,
    size_t n,
    size_t m,
    std::vector<Index>& matches
) {
    std::vector<size_t> lps(m, 0);
    for (size_t i = 1, len = 0; i < m;) {
        if (getBase(pattern, i) == getBase(pattern, len))
            lps[i++] = ++len;
        else if (len)
            len = lps[len - 1];
        else
            lps[i++] = 0;
    }

    for (size_t i = 0, j = 0; i < n;) {
        if (getBase(text, i) == getBase(pattern, j)) {
            ++i; ++j;
        }
        if (j == m) {
            matches.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && getBase(text, i) != getBase(pattern, j)) {
            j ? j = lps[j - 1] : ++i;
        }
    }
}

}
