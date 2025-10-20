//! Statistics Calculator - Rust Implementation
//! Demonstrates statistical analysis and probability

/// Calculator for statistical operations
pub struct StatisticsCalculator;

impl StatisticsCalculator {
    /// Calculate arithmetic mean (average)
    pub fn mean(data: &[f64]) -> f64 {
        data.iter().sum::<f64>() / data.len() as f64
    }

    /// Calculate median (middle value)
    pub fn median(data: &[f64]) -> f64 {
        let mut sorted = data.to_vec();
        sorted.sort_by(|a, b| a.partial_cmp(b).unwrap());
        let n = sorted.len();

        if n % 2 == 0 {
            (sorted[n / 2 - 1] + sorted[n / 2]) / 2.0
        } else {
            sorted[n / 2]
        }
    }

    /// Calculate variance (sample or population)
    pub fn variance(data: &[f64], sample: bool) -> f64 {
        let mean_val = Self::mean(data);
        let n = data.len();

        let sum_squared_diff: f64 = data.iter().map(|&x| (x - mean_val).powi(2)).sum();

        if sample {
            sum_squared_diff / (n - 1) as f64
        } else {
            sum_squared_diff / n as f64
        }
    }

    /// Calculate standard deviation
    pub fn std_dev(data: &[f64], sample: bool) -> f64 {
        Self::variance(data, sample).sqrt()
    }

    /// Calculate z-score (standard score)
    /// z = (x - μ) / σ
    pub fn z_score(value: f64, mean: f64, std_dev: f64) -> f64 {
        (value - mean) / std_dev
    }

    /// Calculate Pearson correlation coefficient
    pub fn correlation(x: &[f64], y: &[f64]) -> f64 {
        assert_eq!(x.len(), y.len(), "Lists must have same length");

        let n = x.len();
        let mean_x = Self::mean(x);
        let mean_y = Self::mean(y);

        let numerator: f64 = (0..n).map(|i| (x[i] - mean_x) * (y[i] - mean_y)).sum();

        let sum_x_sq: f64 = x.iter().map(|&xi| (xi - mean_x).powi(2)).sum();
        let sum_y_sq: f64 = y.iter().map(|&yi| (yi - mean_y).powi(2)).sum();

        let denominator = (sum_x_sq * sum_y_sq).sqrt();

        if denominator != 0.0 {
            numerator / denominator
        } else {
            0.0
        }
    }

    /// Calculate linear regression y = mx + b
    /// Returns (slope, intercept)
    pub fn linear_regression(x: &[f64], y: &[f64]) -> (f64, f64) {
        assert_eq!(x.len(), y.len(), "Lists must have same length");

        let n = x.len();
        let mean_x = Self::mean(x);
        let mean_y = Self::mean(y);

        let numerator: f64 = (0..n).map(|i| (x[i] - mean_x) * (y[i] - mean_y)).sum();
        let denominator: f64 = x.iter().map(|&xi| (xi - mean_x).powi(2)).sum();

        let slope = numerator / denominator;
        let intercept = mean_y - slope * mean_x;

        (slope, intercept)
    }

    /// Calculate factorial n!
    pub fn factorial(n: u64) -> u64 {
        match n {
            0 | 1 => 1,
            _ => n * Self::factorial(n - 1),
        }
    }

    /// Calculate combination C(n,r) = n! / (r!(n-r)!)
    pub fn combination(n: u64, r: u64) -> u64 {
        if r > n {
            return 0;
        }
        Self::factorial(n) / (Self::factorial(r) * Self::factorial(n - r))
    }

    /// Calculate permutation P(n,r) = n! / (n-r)!
    pub fn permutation(n: u64, r: u64) -> u64 {
        if r > n {
            return 0;
        }
        Self::factorial(n) / Self::factorial(n - r)
    }
}

fn main() {
    println!("{}", "=".repeat(60));
    println!("STATISTICS CALCULATOR - RUST");
    println!("{}", "=".repeat(60));

    // Sample data
    let data = vec![12.0, 15.0, 18.0, 20.0, 22.0, 25.0, 28.0, 30.0, 15.0, 18.0];

    // Example 1: Central tendency
    println!("\n1. CENTRAL TENDENCY");
    println!("{}", "-".repeat(60));
    println!("Data: {:?}", data);
    println!("Mean: {:.2}", StatisticsCalculator::mean(&data));
    println!("Median: {:.2}", StatisticsCalculator::median(&data));

    // Example 2: Dispersion
    println!("\n2. MEASURES OF DISPERSION");
    println!("{}", "-".repeat(60));
    let variance = StatisticsCalculator::variance(&data, true);
    let std = StatisticsCalculator::std_dev(&data, true);
    println!("Sample Variance: {:.2}", variance);
    println!("Sample Standard Deviation: {:.2}", std);

    // Example 3: Z-scores
    println!("\n3. Z-SCORES");
    println!("{}", "-".repeat(60));
    let mean_val = StatisticsCalculator::mean(&data);
    let std_val = StatisticsCalculator::std_dev(&data, true);
    let value = 25.0;
    let z = StatisticsCalculator::z_score(value, mean_val, std_val);
    println!("Value: {}", value);
    println!("Z-score: {:.2}", z);
    let direction = if z > 0.0 { "above" } else { "below" };
    println!(
        "Interpretation: {} is {:.2} standard deviations {} the mean",
        value,
        z.abs(),
        direction
    );

    // Example 4: Correlation
    println!("\n4. CORRELATION");
    println!("{}", "-".repeat(60));
    let x = vec![1.0, 2.0, 3.0, 4.0, 5.0];
    let y = vec![2.0, 4.0, 5.0, 4.0, 5.0];
    let r = StatisticsCalculator::correlation(&x, &y);
    println!("X: {:?}", x);
    println!("Y: {:?}", y);
    println!("Pearson correlation coefficient: {:.4}", r);

    let strength = if r.abs() > 0.7 {
        "strong"
    } else if r.abs() > 0.3 {
        "moderate"
    } else {
        "weak"
    };
    let direction = if r > 0.0 { "positive" } else { "negative" };
    println!("Interpretation: {} {} correlation", strength, direction);

    // Example 5: Linear regression
    println!("\n5. LINEAR REGRESSION");
    println!("{}", "-".repeat(60));
    let (slope, intercept) = StatisticsCalculator::linear_regression(&x, &y);
    println!("Regression line: y = {:.2}x + {:.2}", slope, intercept);
    println!(
        "Predicted y when x=6: {:.2}",
        slope * 6.0 + intercept
    );

    // Example 6: Combinatorics
    println!("\n6. COMBINATORICS");
    println!("{}", "-".repeat(60));
    let (n, r) = (10, 3);
    println!("Combination C({},{}) : {}", n, r, StatisticsCalculator::combination(n, r));
    println!("(Choosing {} items from {})", r, n);
    println!("\nPermutation P({},{}): {}", n, r, StatisticsCalculator::permutation(n, r));
    println!("(Arranging {} items from {})", r, n);

    // Example 7: Factorial
    println!("\n7. FACTORIAL");
    println!("{}", "-".repeat(60));
    for i in [0, 1, 5, 10] {
        println!("{}! = {}", i, StatisticsCalculator::factorial(i));
    }

    println!("\n{}", "=".repeat(60));
}
