//! Calculus Calculator - Rust Implementation
//! Demonstrates derivatives, integrals, and limits

use std::f64::consts::PI;

/// Calculator for basic calculus operations
pub struct CalculusCalculator {
    epsilon: f64,
}

impl CalculusCalculator {
    /// Create a new calculator with specified precision
    pub fn new(epsilon: f64) -> Self {
        CalculusCalculator { epsilon }
    }

    /// Compute numerical derivative using central difference method
    /// f'(x) ≈ (f(x+h) - f(x-h)) / (2h)
    pub fn derivative<F>(&self, f: F, x: f64, h: f64) -> f64
    where
        F: Fn(f64) -> f64,
    {
        (f(x + h) - f(x - h)) / (2.0 * h)
    }

    /// Compute definite integral using Simpson's Rule
    /// More accurate than trapezoidal or midpoint methods
    pub fn integral<F>(&self, f: F, a: f64, b: f64, n: usize) -> f64
    where
        F: Fn(f64) -> f64,
    {
        let n = if n % 2 == 1 { n + 1 } else { n }; // Must be even
        let h = (b - a) / n as f64;
        let mut sum = f(a) + f(b);

        for i in 1..n {
            let x = a + i as f64 * h;
            if i % 2 == 0 {
                sum += 2.0 * f(x);
            } else {
                sum += 4.0 * f(x);
            }
        }

        (h / 3.0) * sum
    }

    /// Compute second derivative f''(x)
    /// Used for concavity analysis
    pub fn second_derivative<F>(&self, f: F, x: f64, h: f64) -> f64
    where
        F: Fn(f64) -> f64,
    {
        (f(x + h) - 2.0 * f(x) + f(x - h)) / (h * h)
    }

    /// Find critical points where f'(x) ≈ 0 in interval [a, b]
    pub fn find_critical_points<F>(&self, f: F, a: f64, b: f64, n: usize) -> Vec<f64>
    where
        F: Fn(f64) -> f64,
    {
        let mut critical_points = Vec::new();
        let step = (b - a) / n as f64;

        for i in 0..=n {
            let x = a + i as f64 * step;
            let deriv = self.derivative(&f, x, 1e-5);
            if deriv.abs() < 0.01 {
                critical_points.push(x);
            }
        }

        critical_points
    }

    /// Compute limit as x approaches a value
    pub fn limit<F>(&self, f: F, x: f64) -> f64
    where
        F: Fn(f64) -> f64,
    {
        let h = 1e-6;
        let left_limit = f(x - h);
        let right_limit = f(x + h);

        if (left_limit - right_limit).abs() < self.epsilon {
            (left_limit + right_limit) / 2.0
        } else {
            panic!(
                "Limit does not exist: left={}, right={}",
                left_limit, right_limit
            );
        }
    }
}

fn main() {
    let calc = CalculusCalculator::new(1e-7);

    println!("{}", "=".repeat(60));
    println!("CALCULUS CALCULATOR - RUST");
    println!("{}", "=".repeat(60));

    // Example 1: Derivative of f(x) = x²
    println!("\n1. DERIVATIVES");
    println!("{}", "-".repeat(60));
    let f1 = |x: f64| x.powi(2);
    let x = 3.0;
    let derivative = calc.derivative(f1, x, 1e-5);
    println!("f(x) = x²");
    println!("f'({}) ≈ {:.6}", x, derivative);
    println!("Analytical: f'({}) = 2x = {} ✓", x, 2.0 * x);

    // Example 2: Derivative of sin(x)
    let f2 = |x: f64| x.sin();
    let x = PI / 4.0;
    let derivative = calc.derivative(f2, x, 1e-5);
    println!("\nf(x) = sin(x)");
    println!("f'(π/4) ≈ {:.6}", derivative);
    println!("Analytical: f'(π/4) = cos(π/4) = {:.6} ✓", x.cos());

    // Example 3: Integral of x² from 0 to 1
    println!("\n2. INTEGRALS");
    println!("{}", "-".repeat(60));
    let f3 = |x: f64| x.powi(2);
    let integral = calc.integral(f3, 0.0, 1.0, 1000);
    println!("∫₀¹ x² dx ≈ {:.6}", integral);
    println!("Analytical: [x³/3]₀¹ = 1/3 = {:.6} ✓", 1.0 / 3.0);

    // Example 4: Integral of sin(x) from 0 to π
    let f4 = |x: f64| x.sin();
    let integral = calc.integral(f4, 0.0, PI, 1000);
    println!("\n∫₀^π sin(x) dx ≈ {:.6}", integral);
    println!("Analytical: [-cos(x)]₀^π = 2.000000 ✓");

    // Example 5: Second derivative (concavity)
    println!("\n3. SECOND DERIVATIVES (Concavity)");
    println!("{}", "-".repeat(60));
    let f5 = |x: f64| x.powi(3) - 3.0 * x.powi(2);
    let x = 1.0;
    let second_deriv = calc.second_derivative(f5, x, 1e-5);
    println!("f(x) = x³ - 3x²");
    println!("f''({}) ≈ {:.6}", x, second_deriv);
    println!("Analytical: f''(x) = 6x - 6, f''(1) = 0 ✓");
    let concavity = if second_deriv.abs() < 0.1 {
        "Inflection Point"
    } else {
        "Curved"
    };
    println!("Concavity at x={}: {}", x, concavity);

    // Example 6: Critical points
    println!("\n4. CRITICAL POINTS");
    println!("{}", "-".repeat(60));
    let f6 = |x: f64| x.powi(3) - 3.0 * x;
    let critical = calc.find_critical_points(f6, -2.0, 2.0, 100);
    println!("f(x) = x³ - 3x");
    let critical_rounded: Vec<f64> = critical.iter().map(|&x| (x * 100.0).round() / 100.0).collect();
    println!("Critical points in [-2, 2]: {:?}", critical_rounded);
    println!("Analytical: f'(x) = 3x² - 3 = 0 → x = ±1 ✓");

    // Example 7: Product rule demonstration
    println!("\n5. PRODUCT RULE VERIFICATION");
    println!("{}", "-".repeat(60));
    let f7 = |x: f64| x * x.sin();
    let x = 2.0;
    let numerical = calc.derivative(f7, x, 1e-5);
    let analytical = x.sin() + x * x.cos();
    println!("f(x) = x·sin(x)");
    println!("f'({}) numerical ≈ {:.6}", x, numerical);
    println!("f'({}) analytical = {:.6} ✓", x, analytical);

    println!("\n{}", "=".repeat(60));
}
