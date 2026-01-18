#include "dna_matcher.h"
#include <iostream>
#include <chrono>

using namespace std;
using namespace dna;

int main() {
    string sequence, pattern;
    cin >> sequence >> pattern;

    size_t nPacked, mPacked;
    uint8_t* seq = encodeDNA(sequence, nPacked);
    uint8_t* pat = encodeDNA(pattern, mPacked);

    vector<Index> matches;

    auto start = chrono::high_resolution_clock::now();
    kmp(seq, pat, sequence.size(), pattern.size(), matches);
    auto end = chrono::high_resolution_clock::now();

    cout << "Matches: " << matches.size() << endl;
    cout << "Time(ns): "
         << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
         << endl;

    freeDNA(seq);
    freeDNA(pat);
}
