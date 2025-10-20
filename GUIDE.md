# Mathematics Learning Through Code

## 🎯 Project Overview

This repository combines **theoretical mathematics education** with **practical programming implementations**. Learn mathematics by both studying the theory and implementing the concepts in code!

### Repository Structure

```
Math/
├── README.md                      # Main introduction to calculus concepts
├── calc_1.md                      # Calculus I (Differential Calculus)
├── Calculus_2.md                  # Calculus II
├── Calculus3.md                   # Calculus III
├── College_Algebra.md             # Algebra fundamentals
├── Differential_equations.md      # Differential equations
├── Differential_Geometry.md       # Differential geometry
├── Statistics.md                  # Statistical concepts
├── Trigonometrylatex.md          # Trigonometry
├── Geometry_latex.md             # Geometry
└── calculators/                   # 🆕 Programming implementations
    ├── README.md                  # Calculator overview
    ├── USAGE.md                   # Detailed usage guide
    ├── Makefile                   # Build automation (C/C++)
    ├── run_tests.sh              # Test all implementations
    ├── python/                    # Python implementations
    │   ├── calculus_calculator.py
    │   ├── algebra_calculator.py
    │   └── statistics_calculator.py
    ├── rust/                      # Rust implementations
    │   ├── Cargo.toml
    │   ├── calculus_calculator.rs
    │   ├── algebra_calculator.rs
    │   └── statistics_calculator.rs
    ├── cpp/                       # C++ implementations
    │   ├── calculus_calculator.cpp
    │   └── algebra_calculator.cpp
    └── c/                         # C implementations
        ├── calculus_calculator.c
        └── algebra_calculator.c
```

## 📚 Learning Paths

### Path 1: Theory First
1. Read the markdown files for mathematical concepts
2. Study the formulas and examples
3. Run the corresponding calculator to see the concepts in action
4. Modify the code to experiment with different values

### Path 2: Code First
1. Run a calculator and observe the output
2. Read the code comments to understand the algorithm
3. Refer to the markdown files for theoretical background
4. Implement your own variations

### Path 3: Comparative Learning
1. Study a concept in the markdown (e.g., derivatives)
2. Run the same calculation in all four languages
3. Compare the implementations
4. Understand language-specific features

## 🧮 Calculator Features

### Calculus Calculator
Implements core differential and integral calculus:

- **Derivatives**: Numerical approximation using central difference
  ```
  f'(x) ≈ (f(x+h) - f(x-h)) / (2h)
  ```

- **Integrals**: Simpson's Rule for definite integrals
  ```
  ∫[a,b] f(x)dx ≈ (h/3)[f(a) + 4Σf(x_odd) + 2Σf(x_even) + f(b)]
  ```

- **Second Derivatives**: Concavity analysis
- **Critical Points**: Finding local extrema
- **Limits**: Numerical limit evaluation

### Algebra Calculator
Polynomial and sequence operations:

- **Quadratic Formula**: Solving ax² + bx + c = 0 (real and complex roots)
- **Polynomial Evaluation**: Efficient Horner's method
- **Polynomial Derivatives**: Symbolic differentiation
- **GCD/LCM**: Euclidean algorithm
- **Sequences**: Arithmetic and geometric sequences with sums

### Statistics Calculator
Statistical analysis tools:

- **Central Tendency**: Mean, median, mode
- **Dispersion**: Variance, standard deviation
- **Standardization**: Z-scores
- **Correlation**: Pearson correlation coefficient
- **Regression**: Linear regression (least squares)
- **Combinatorics**: Permutations, combinations, factorials

## 🚀 Quick Start Guide

### Run Everything (Test Suite)
```bash
cd calculators
./run_tests.sh
```

### Python (Easiest to Start)
```bash
cd calculators/python
python3 calculus_calculator.py
python3 algebra_calculator.py
python3 statistics_calculator.py
```

### Rust (Modern & Safe)
```bash
cd calculators/rust
cargo run --bin calculus_calculator
cargo run --bin algebra_calculator
cargo run --bin statistics_calculator
```

### C++ (Object-Oriented)
```bash
cd calculators
make cpp
./build/calculus_calculator_cpp
./build/algebra_calculator_cpp
```

### C (Low-Level Understanding)
```bash
cd calculators
make c
./build/calculus_calculator_c
./build/algebra_calculator_c
```

## 💡 Educational Value

### What You'll Learn

#### Mathematics
- **Numerical Methods**: How computers approximate continuous mathematics
- **Algorithm Design**: Efficient ways to compute mathematical operations
- **Error Analysis**: Understanding precision and approximation
- **Real-World Applications**: How calculus is used in computing

#### Programming
- **Multi-Language Comparison**: See the same algorithm in different paradigms
- **Functional Programming**: Higher-order functions, lambdas (Python, Rust)
- **Systems Programming**: Memory management, pointers (C, C++)
- **Type Safety**: Rust's ownership system vs C's manual management
- **Object-Oriented Design**: Classes and encapsulation (C++, Python)

### Example: Computing a Derivative

**Theory (from calc_1.md)**:
```
f'(x) = lim[h→0] (f(x+h) - f(x))/h
```

**Python Implementation**:
```python
def derivative(f, x, h=1e-5):
    return (f(x + h) - f(x - h)) / (2 * h)
```

**Rust Implementation**:
```rust
pub fn derivative<F>(f: F, x: f64, h: f64) -> f64
where F: Fn(f64) -> f64
{
    (f(x + h) - f(x - h)) / (2.0 * h)
}
```

**C Implementation**:
```c
double derivative(double (*f)(double), double x, double h) {
    return (f(x + h) - f(x - h)) / (2.0 * h);
}
```

## 🔬 Experimentation Ideas

### Beginner
1. Change the function being differentiated
2. Modify the step size (h) and observe accuracy changes
3. Calculate derivatives at different points
4. Verify results against analytical solutions

### Intermediate
1. Implement additional integration methods (trapezoidal, midpoint)
2. Add error estimation functions
3. Create timing comparisons between languages
4. Implement symbolic differentiation for polynomials

### Advanced
1. Implement adaptive step size algorithms
2. Add multi-variable calculus support
3. Create Taylor series approximations
4. Build a graphing calculator with output visualization
5. Implement differential equation solvers

## 📊 Practical Examples

### Example 1: Find the Maximum of a Function

**Problem**: Find the maximum of f(x) = -x² + 4x on [0, 5]

**Approach**:
1. Use calculus calculator to find where f'(x) = 0
2. Evaluate f at critical points and endpoints
3. Compare values

```bash
# Modify the calculus calculator to use f(x) = -x² + 4x
# Run critical point finder
# Expected: critical point at x = 2, maximum value = 4
```

### Example 2: Solve a Real Equation

**Problem**: Solve 2x² - 7x + 3 = 0

```bash
# Use algebra calculator
# Input: a=2, b=-7, c=3
# Output: x₁ = 3, x₂ = 0.5
```

### Example 3: Statistical Analysis

**Problem**: Analyze test scores [85, 90, 78, 92, 88, 76, 95, 89]

```bash
# Use statistics calculator
# Find: mean, median, standard deviation
# Identify outliers using z-scores
```

## 🎓 Curriculum Integration

This project aligns with standard mathematics curricula:

### High School
- **Algebra II**: Quadratic equations, sequences
- **Pre-Calculus**: Functions, limits, trigonometry
- **AP Calculus**: Derivatives, integrals, optimization
- **AP Statistics**: Descriptive statistics, correlation

### College
- **Calculus I**: Limits, derivatives, applications
- **Calculus II**: Integration techniques, series
- **Calculus III**: Multivariable calculus
- **Linear Algebra**: Systems of equations, matrices
- **Numerical Analysis**: Approximation methods
- **Introduction to Computer Science**: Algorithm implementation

## 🛠️ Development Setup

### Install All Tools

#### Ubuntu/Debian
```bash
# Python
sudo apt-get install python3

# Rust
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh

# C/C++
sudo apt-get install build-essential

# Verify installations
python3 --version
cargo --version
gcc --version
g++ --version
```

#### macOS
```bash
# Install Homebrew if not already installed
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# Install tools
brew install python rust gcc

# Verify
python3 --version
cargo --version
gcc --version
```

#### Windows
- Python: https://www.python.org/downloads/
- Rust: https://rustup.rs/
- C/C++: Install MinGW or MSVC

## 🤝 Contributing

Ideas for contributions:
- Add more calculator types (trigonometry, linear algebra, complex analysis)
- Implement in additional languages (Java, JavaScript, Go, Julia)
- Add visualization capabilities (matplotlib, plotters)
- Create interactive Jupyter notebooks
- Add more sophisticated numerical methods
- Improve documentation and examples

## 📖 Additional Resources

### Mathematical Background
- Khan Academy: https://www.khanacademy.org/math
- MIT OpenCourseWare: https://ocw.mit.edu/
- Paul's Online Math Notes: https://tutorial.math.lamar.edu/

### Programming Resources
- Python Tutorial: https://docs.python.org/3/tutorial/
- Rust Book: https://doc.rust-lang.org/book/
- C++ Reference: https://en.cppreference.com/
- C Programming: https://www.learn-c.org/

### Numerical Methods
- Numerical Recipes: http://numerical.recipes/
- SciPy Documentation: https://docs.scipy.org/doc/scipy/

## 📝 License

This project is for educational purposes. Feel free to use, modify, and share!

## 🎯 Next Steps

1. **Start Learning**: Pick a calculator and run it
2. **Read the Code**: Understand the implementation
3. **Study the Theory**: Review the markdown files
4. **Experiment**: Modify and extend the calculators
5. **Compare**: See how different languages approach the same problem
6. **Create**: Build your own mathematical calculators!

---

**Happy Learning! 📚✨**

For questions or suggestions, refer to the individual README and USAGE files in the calculators directory.
