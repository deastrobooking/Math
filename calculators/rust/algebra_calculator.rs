//! Algebra Calculator - Rust Implementation
//! Demonstrates polynomial operations, equation solving

use std::f64;

/// Calculator for algebraic operations
pub struct AlgebraCalculator;

impl AlgebraCalculator {
    /// Solve ax² + bx + c = 0 using the quadratic formula
    /// Returns (x1, x2) which may be complex numbers represented as (real, imaginary)
    pub fn quadratic_formula(a: f64, b: f64, c: f64) -> (Complex, Complex) {
        let discriminant = b * b - 4.0 * a * c;

        if discriminant >= 0.0 {
            let x1 = (-b + discriminant.sqrt()) / (2.0 * a);
            let x2 = (-b - discriminant.sqrt()) / (2.0 * a);
            (Complex::new(x1, 0.0), Complex::new(x2, 0.0))
        } else {
            let real_part = -b / (2.0 * a);
            let imag_part = discriminant.abs().sqrt() / (2.0 * a);
            (
                Complex::new(real_part, imag_part),
                Complex::new(real_part, -imag_part),
            )
        }
    }

    /// Evaluate polynomial using Horner's method
    /// coefficients: [a_0, a_1, ..., a_n] (constant term first)
    pub fn evaluate_polynomial(coefficients: &[f64], x: f64) -> f64 {
        let mut result = 0.0;
        for &coef in coefficients.iter().rev() {
            result = result * x + coef;
        }
        result
    }

    /// Compute derivative of polynomial
    /// Returns coefficients of derivative polynomial
    pub fn polynomial_derivative(coefficients: &[f64]) -> Vec<f64> {
        if coefficients.len() <= 1 {
            return vec![0.0];
        }

        coefficients
            .iter()
            .enumerate()
            .skip(1)
            .map(|(i, &coef)| i as f64 * coef)
            .collect()
    }

    /// Greatest Common Divisor using Euclidean algorithm
    pub fn gcd(mut a: i64, mut b: i64) -> i64 {
        while b != 0 {
            let temp = b;
            b = a % b;
            a = temp;
        }
        a.abs()
    }

    /// Least Common Multiple
    pub fn lcm(a: i64, b: i64) -> i64 {
        (a * b).abs() / Self::gcd(a, b)
    }

    /// Generate arithmetic sequence: a_n = a_1 + (n-1)d
    pub fn arithmetic_sequence(a1: f64, d: f64, n: usize) -> Vec<f64> {
        (0..n).map(|i| a1 + i as f64 * d).collect()
    }

    /// Generate geometric sequence: a_n = a_1 * r^(n-1)
    pub fn geometric_sequence(a1: f64, r: f64, n: usize) -> Vec<f64> {
        (0..n).map(|i| a1 * r.powi(i as i32)).collect()
    }

    /// Sum of arithmetic sequence: S_n = n(a_1 + a_n) / 2
    pub fn arithmetic_sum(a1: f64, an: f64, n: usize) -> f64 {
        n as f64 * (a1 + an) / 2.0
    }

    /// Sum of geometric sequence: S_n = a_1(1 - r^n) / (1 - r)
    pub fn geometric_sum(a1: f64, r: f64, n: usize) -> f64 {
        if (r - 1.0).abs() < 1e-10 {
            a1 * n as f64
        } else {
            a1 * (1.0 - r.powi(n as i32)) / (1.0 - r)
        }
    }
}

/// Simple complex number representation
#[derive(Debug, Clone, Copy)]
pub struct Complex {
    real: f64,
    imag: f64,
}

impl Complex {
    pub fn new(real: f64, imag: f64) -> Self {
        Complex { real, imag }
    }
}

impl std::fmt::Display for Complex {
    fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
        if self.imag.abs() < 1e-10 {
            write!(f, "{:.6}", self.real)
        } else if self.imag >= 0.0 {
            write!(f, "{:.6} + {:.6}i", self.real, self.imag)
        } else {
            write!(f, "{:.6} - {:.6}i", self.real, -self.imag)
        }
    }
}

fn main() {
    println!("{}", "=".repeat(60));
    println!("ALGEBRA CALCULATOR - RUST");
    println!("{}", "=".repeat(60));

    // Example 1: Quadratic formula
    println!("\n1. QUADRATIC FORMULA");
    println!("{}", "-".repeat(60));
    let (a, b, c) = (1.0, -5.0, 6.0); // x² - 5x + 6 = 0
    let (x1, x2) = AlgebraCalculator::quadratic_formula(a, b, c);
    println!("Equation: {}x² + ({})x + {} = 0", a, b, c);
    println!("Solutions: x₁ = {}, x₂ = {}", x1, x2);

    // Example 2: Complex roots
    let (a, b, c) = (1.0, 0.0, 4.0); // x² + 4 = 0
    let (x1, x2) = AlgebraCalculator::quadratic_formula(a, b, c);
    println!("\nEquation: {}x² + {} = 0", a, c);
    println!("Solutions: x₁ = {}, x₂ = {}", x1, x2);

    // Example 3: Polynomial evaluation
    println!("\n2. POLYNOMIAL EVALUATION");
    println!("{}", "-".repeat(60));
    let coeffs = vec![1.0, 2.0, 3.0]; // 3x² + 2x + 1
    let x = 2.0;
    let result = AlgebraCalculator::evaluate_polynomial(&coeffs, x);
    println!("P(x) = 3x² + 2x + 1");
    println!("P({}) = {}", x, result);
    println!(
        "Verification: 3({})² + 2({}) + 1 = {} ✓",
        x,
        x,
        3.0 * x * x + 2.0 * x + 1.0
    );

    // Example 4: Polynomial derivative
    println!("\n3. POLYNOMIAL DERIVATIVE");
    println!("{}", "-".repeat(60));
    let coeffs = vec![5.0, 0.0, 3.0, 2.0]; // 2x³ + 3x² + 5
    let deriv_coeffs = AlgebraCalculator::polynomial_derivative(&coeffs);
    println!("P(x) = 2x³ + 3x² + 5");
    println!("P'(x) coefficients: {:?}", deriv_coeffs);
    println!("P'(x) = 6x² + 6x ✓");

    // Example 5: GCD and LCM
    println!("\n4. GCD AND LCM");
    println!("{}", "-".repeat(60));
    let (a, b) = (48, 18);
    println!("GCD({}, {}) = {}", a, b, AlgebraCalculator::gcd(a, b));
    println!("LCM({}, {}) = {}", a, b, AlgebraCalculator::lcm(a, b));

    // Example 6: Arithmetic sequence
    println!("\n5. ARITHMETIC SEQUENCE");
    println!("{}", "-".repeat(60));
    let (a1, d, n) = (3.0, 5.0, 8);
    let seq = AlgebraCalculator::arithmetic_sequence(a1, d, n);
    println!("First term: {}, Common difference: {}", a1, d);
    println!("First {} terms: {:?}", n, seq);
    let sum_seq = AlgebraCalculator::arithmetic_sum(a1, seq[seq.len() - 1], n);
    println!("Sum: {}", sum_seq);

    // Example 7: Geometric sequence
    println!("\n6. GEOMETRIC SEQUENCE");
    println!("{}", "-".repeat(60));
    let (a1, r, n) = (2.0, 3.0, 6);
    let seq = AlgebraCalculator::geometric_sequence(a1, r, n);
    println!("First term: {}, Common ratio: {}", a1, r);
    println!("First {} terms: {:?}", n, seq);
    let sum_seq = AlgebraCalculator::geometric_sum(a1, r, n);
    println!("Sum: {}", sum_seq);

    println!("\n{}", "=".repeat(60));
}
