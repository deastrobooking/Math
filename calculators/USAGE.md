# Calculator Examples - Compilation and Usage Guide

This directory contains mathematical calculator implementations in four programming languages: Python, Rust, C++, and C.

## 📋 Prerequisites

### Python
- Python 3.6 or higher
- No external dependencies required (uses standard library)

### Rust
- Rust 1.50 or higher
- Cargo (Rust package manager)

### C++
- C++17 compatible compiler (GCC 7+, Clang 5+, MSVC 2017+)
- Standard library with `<functional>` and `<complex>` support

### C
- C99 compatible compiler (GCC, Clang)
- Math library (`-lm` flag required)

## 🚀 Quick Start

### Python Examples

```bash
# Navigate to python directory
cd calculators/python

# Run calculus calculator
python3 calculus_calculator.py

# Run algebra calculator
python3 algebra_calculator.py

# Run statistics calculator
python3 statistics_calculator.py

# Make executable (optional)
chmod +x *.py
./calculus_calculator.py
```

### Rust Examples

```bash
# Navigate to rust directory
cd calculators/rust

# Build all binaries
cargo build --release

# Run specific calculator
cargo run --bin calculus_calculator
cargo run --bin algebra_calculator
cargo run --bin statistics_calculator

# Or run compiled binaries directly
./target/release/calculus_calculator
```

### C++ Examples

```bash
# Navigate to cpp directory
cd calculators/cpp

# Compile calculus calculator
g++ -std=c++17 -O2 calculus_calculator.cpp -o calculus_calc

# Compile algebra calculator
g++ -std=c++17 -O2 algebra_calculator.cpp -o algebra_calc

# Run
./calculus_calc
./algebra_calc

# Using Clang (alternative)
clang++ -std=c++17 -O2 calculus_calculator.cpp -o calculus_calc
```

### C Examples

```bash
# Navigate to c directory
cd calculators/c

# Compile with math library
gcc -std=c99 -O2 -lm calculus_calculator.c -o calculus_calc
gcc -std=c99 -O2 -lm algebra_calculator.c -o algebra_calc

# Run
./calculus_calc
./algebra_calc

# With debugging symbols (optional)
gcc -std=c99 -g -lm calculus_calculator.c -o calculus_calc_debug
```

## 📚 What Each Calculator Teaches

### Calculus Calculator
**Mathematical Concepts:**
- Numerical derivatives (central difference method)
- Definite integrals (Simpson's Rule)
- Second derivatives (concavity analysis)
- Critical points (finding local extrema)
- Limits
- Product rule verification

**Programming Concepts:**
- Function pointers (C) / Lambdas (C++, Rust) / Higher-order functions (Python)
- Numerical methods and approximation
- Error handling

### Algebra Calculator
**Mathematical Concepts:**
- Quadratic formula (real and complex roots)
- Polynomial evaluation (Horner's method)
- Polynomial derivatives
- GCD and LCM (Euclidean algorithm)
- Arithmetic and geometric sequences
- Series summation

**Programming Concepts:**
- Complex number handling
- Recursive algorithms (factorial, GCD)
- Array/vector manipulation
- Structured data types

### Statistics Calculator
**Mathematical Concepts:**
- Central tendency (mean, median, mode)
- Dispersion (variance, standard deviation)
- Z-scores (standardization)
- Correlation coefficients
- Linear regression
- Combinatorics (permutations, combinations)

**Programming Concepts:**
- Statistical algorithms
- Data aggregation
- List/array operations
- Factorial computation

## 🎓 Learning Progression

### Beginner Path
1. **Start with Python** - Easiest syntax, fastest to experiment
   - Run `algebra_calculator.py` to understand basic operations
   - Modify values and see results immediately

2. **Try C** - Learn fundamental concepts
   - See how math operations work at a lower level
   - Understand memory and pointers

### Intermediate Path
3. **Move to C++** - Object-oriented approach
   - Learn about classes and templates
   - See how C++ improves upon C

4. **Explore Rust** - Modern systems programming
   - Type safety and ownership
   - Functional programming patterns

## 🔬 Experimentation Ideas

### Modify Examples
1. Change the functions being evaluated
2. Adjust precision parameters (epsilon, step size)
3. Test edge cases (division by zero, complex numbers)

### Add Features
1. Implement new integration methods (trapezoidal, Monte Carlo)
2. Add Taylor series expansion
3. Create graphing output (using plotting libraries)

### Performance Comparison
1. Time the calculations across languages
2. Compare numerical accuracy
3. Test with larger datasets

## 🐛 Common Issues and Solutions

### Python
```bash
# Issue: Permission denied
chmod +x calculator.py

# Issue: Python not found
python3 calculator.py  # Use python3 explicitly
```

### Rust
```bash
# Issue: Cargo not found
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh

# Issue: Compilation fails
cargo clean && cargo build
```

### C++
```bash
# Issue: C++17 not supported
g++ --version  # Check version (need 7+)

# Issue: Undefined reference to std::...
# Use -std=c++17 flag

# Issue: Math functions not found
# Include -lm flag (though usually not needed for C++)
```

### C
```bash
# Issue: Undefined reference to `sin`, `cos`, etc.
# Always use -lm flag to link math library
gcc -lm program.c -o program

# Issue: Complex numbers not working
# C99 required for complex.h
gcc -std=c99 -lm program.c -o program
```

## 📖 Additional Resources

### Documentation
- Python math module: https://docs.python.org/3/library/math.html
- Rust std library: https://doc.rust-lang.org/std/
- C++ reference: https://en.cppreference.com/
- C math library: https://en.cppreference.com/w/c/numeric/math

### Learning Resources
- Numerical Methods: "Numerical Recipes" by Press et al.
- Algorithms: "Introduction to Algorithms" by CLRS
- Calculus refresher: Khan Academy, MIT OCW

## 💡 Tips

1. **Start Simple**: Run the examples as-is before modifying
2. **Read the Code**: Each implementation is heavily commented
3. **Compare Languages**: See how the same algorithm differs across languages
4. **Verify Results**: Cross-check outputs between implementations
5. **Use Debuggers**: gdb (C/C++), lldb (Rust), pdb (Python)

## 🤝 Contributing

Feel free to:
- Add new calculators (differential equations, linear algebra, etc.)
- Improve numerical accuracy
- Add visualization capabilities
- Translate to other languages (Java, JavaScript, Go, etc.)

## 📝 License

These examples are for educational purposes. Feel free to use and modify them as needed.
