# Statistics Calculator - Multi-Paradigm Implementation

This project implements a statistics calculator in three different programming languages, each demonstrating a different programming paradigm:
- C (Procedural)
- OCaml (Functional)
- Python (Object-Oriented)

## Features

Each implementation calculates the following statistics for a list of integers:
- Mean (average)
- Median (middle value)
- Mode (most frequent value(s))

## Directory Structure

```
.
├── c/              # C implementation (Procedural)
│   └── stats.c
├── ocaml/          # OCaml implementation (Functional)
│   └── stats.ml
└── python/         # Python implementation (Object-Oriented)
    └── stats.py
```

## Requirements

### C Implementation
- GCC compiler
- Standard C library

### OCaml Implementation
- OCaml compiler (ocamlc)
- OCaml standard library

### Python Implementation
- Python 3.6 or higher
- Standard Python library

## Building and Running

### C Implementation
```bash
cd c
gcc stats.c -o stats
./stats
```

### OCaml Implementation
```bash
cd ocaml
ocamlc -o stats stats.ml
./stats
```

### Python Implementation
```bash
cd python
python stats.py
```

## Implementation Details

### C (Procedural)
- Uses arrays and pointers for data storage
- Implements manual memory management
- Features:
  - Bubble sort for median calculation
  - Direct array manipulation
  - Explicit memory handling for mode calculation

### OCaml (Functional)
- Uses immutable lists and functional programming concepts
- Features:
  - Pattern matching
  - Higher-order functions (fold_left)
  - Recursive counting
  - Pure functions with no side effects

### Python (Object-Oriented)
- Uses classes and methods for organization
- Features:
  - Encapsulation of statistics calculations
  - Type hints for better code clarity
  - Built-in collections (Counter)
  - Method-based organization

## Example Output

All implementations will produce the same output for the test data [1, 2, 3, 4, 5, 5, 6, 7, 8, 9]:
```
Numbers: 1 2 3 4 5 5 6 7 8 9
Mean: 5.00
Median: 5.00
Mode: 5
```

## Paradigm Comparison

Each implementation demonstrates different programming paradigms:

1. **Procedural (C)**
   - Focus on step-by-step execution
   - Explicit state management
   - Manual memory control

2. **Functional (OCaml)**
   - Immutable data structures
   - Function composition
   - No side effects

3. **Object-Oriented (Python)**
   - Encapsulation of data and methods
   - Class-based organization
   - Method-based operations

