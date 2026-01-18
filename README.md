# 🧬 DNA Pattern Matching Algorithm Analyzer

A **memory-efficient and time-optimized C++ implementation** of classical string matching algorithms for DNA sequence analysis, using **bit-level encoding** and **modular software design**. Created for CSE246 course.

---

## 🚀 Features

- 2-bit DNA encoding (A, C, G, T) for reduced memory footprint
- Naive and Knuth–Morris–Pratt (KMP) pattern matching algorithms
- Header-based modular architecture
- Manual memory allocation and deallocation
- High-precision performance benchmarking using `std::chrono`
- Suitable for algorithms, systems, and bioinformatics projects

---

## 🧠 DNA Encoding Strategy

Each nucleotide is encoded using **2 bits**, allowing **4 DNA bases per byte**:

| Nucleotide | Binary |
|-----------|--------|
| A | 00 |
| C | 01 |
| G | 10 |
| T | 11 |

This approach reduces memory usage by **75%** compared to traditional character-based storage.

---

## 📁 Project Structure

```

dna-pattern-matching/
│
├── dna_matcher.h      # Public API and declarations
├── dna_matcher.cpp    # Core algorithm implementations
├── main.cpp           # Program entry point and benchmarking
└── README.md

````

---

## 🧪 Algorithms Implemented

### 1. Naive String Matching
- **Time Complexity:** O(n × m)
- **Space Complexity:** O(1)
- Performs direct character-by-character comparison

### 2. Knuth–Morris–Pratt (KMP)
- **Time Complexity:** O(n + m)
- **Space Complexity:** O(m)
- Uses Longest Prefix Suffix (LPS) preprocessing to avoid redundant comparisons

---

## ⚙️ Compilation & Execution

### 🔧 Requirements
- C++17 or later
- GCC / Clang / MSVC

### ▶️ Compile

```bash
g++ -std=c++17 main.cpp dna_matcher.cpp -O2 -o dna_matcher
````

### ▶️ Run

```bash
./dna_matcher
```

---

## 📊 Sample Output

```
Matches found: 3
Execution time: 12430 ns
```

---

## 📈 Performance Highlights

* No repeated memory allocation during algorithm execution
* Cache-friendly contiguous memory layout
* Bitwise DNA encoding improves CPU cache utilization
* Accurate and reproducible benchmarking

---

## 🧩 Design Principles

* **Separation of Concerns:** Interface and implementation split using headers
* **Low-Level Optimization:** Bit manipulation instead of character processing
* **Deterministic Memory Management:** Explicit allocation and deallocation
* **Algorithmic Clarity:** Clean and readable implementations

---

## 🎓 Academic Relevance

This project is suitable for:

* Data Structures and Algorithms
* Systems Programming
* Bioinformatics
* Competitive Programming
* Undergraduate and graduate-level computer science projects

---

## 🔮 Future Enhancements

* Boyer–Moore algorithm with full heuristic optimization
* Parallel execution using OpenMP
* SIMD acceleration (AVX / NEON)
* FASTA file input support
* Performance visualization and analysis


---

## 👤 Author

**Abdullah**
Computer Science & Engineering
GitHub: [https://github.com/your-username](https://github.com/your-username)

```
Just tell me 👍
```
