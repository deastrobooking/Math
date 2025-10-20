#!/usr/bin/env python3
"""
Statistics Calculator - Python Implementation
Demonstrates statistical analysis and probability distributions
"""

import math
from typing import List


class StatisticsCalculator:
    """Calculator for statistical operations"""
    
    @staticmethod
    def mean(data: List[float]) -> float:
        """Calculate arithmetic mean (average)"""
        return sum(data) / len(data)
    
    @staticmethod
    def median(data: List[float]) -> float:
        """Calculate median (middle value)"""
        sorted_data = sorted(data)
        n = len(sorted_data)
        
        if n % 2 == 0:
            return (sorted_data[n//2 - 1] + sorted_data[n//2]) / 2
        else:
            return sorted_data[n//2]
    
    @staticmethod
    def mode(data: List[float]) -> List[float]:
        """Calculate mode (most frequent value)"""
        frequency = {}
        for value in data:
            frequency[value] = frequency.get(value, 0) + 1
        
        max_freq = max(frequency.values())
        return [k for k, v in frequency.items() if v == max_freq]
    
    @staticmethod
    def variance(data: List[float], sample: bool = True) -> float:
        """
        Calculate variance
        Sample variance (n-1) or population variance (n)
        """
        mean_val = StatisticsCalculator.mean(data)
        n = len(data)
        
        sum_squared_diff = sum((x - mean_val) ** 2 for x in data)
        
        if sample:
            return sum_squared_diff / (n - 1)
        else:
            return sum_squared_diff / n
    
    @staticmethod
    def std_dev(data: List[float], sample: bool = True) -> float:
        """Calculate standard deviation"""
        return math.sqrt(StatisticsCalculator.variance(data, sample))
    
    @staticmethod
    def z_score(value: float, mean: float, std_dev: float) -> float:
        """
        Calculate z-score (standard score)
        z = (x - μ) / σ
        """
        return (value - mean) / std_dev
    
    @staticmethod
    def correlation(x: List[float], y: List[float]) -> float:
        """
        Calculate Pearson correlation coefficient
        r = Σ((x - x̄)(y - ȳ)) / √(Σ(x - x̄)² * Σ(y - ȳ)²)
        """
        if len(x) != len(y):
            raise ValueError("Lists must have same length")
        
        n = len(x)
        mean_x = StatisticsCalculator.mean(x)
        mean_y = StatisticsCalculator.mean(y)
        
        numerator = sum((x[i] - mean_x) * (y[i] - mean_y) for i in range(n))
        
        sum_x_sq = sum((xi - mean_x) ** 2 for xi in x)
        sum_y_sq = sum((yi - mean_y) ** 2 for yi in y)
        
        denominator = math.sqrt(sum_x_sq * sum_y_sq)
        
        return numerator / denominator if denominator != 0 else 0
    
    @staticmethod
    def linear_regression(x: List[float], y: List[float]) -> tuple:
        """
        Calculate linear regression y = mx + b
        Returns (slope, intercept)
        """
        if len(x) != len(y):
            raise ValueError("Lists must have same length")
        
        n = len(x)
        mean_x = StatisticsCalculator.mean(x)
        mean_y = StatisticsCalculator.mean(y)
        
        numerator = sum((x[i] - mean_x) * (y[i] - mean_y) for i in range(n))
        denominator = sum((xi - mean_x) ** 2 for xi in x)
        
        slope = numerator / denominator
        intercept = mean_y - slope * mean_x
        
        return (slope, intercept)
    
    @staticmethod
    def factorial(n: int) -> int:
        """Calculate n!"""
        if n < 0:
            raise ValueError("Factorial undefined for negative numbers")
        if n == 0 or n == 1:
            return 1
        return n * StatisticsCalculator.factorial(n - 1)
    
    @staticmethod
    def combination(n: int, r: int) -> int:
        """
        Calculate C(n,r) = n! / (r!(n-r)!)
        Number of ways to choose r items from n
        """
        if r > n or r < 0:
            return 0
        return StatisticsCalculator.factorial(n) // (
            StatisticsCalculator.factorial(r) * StatisticsCalculator.factorial(n - r)
        )
    
    @staticmethod
    def permutation(n: int, r: int) -> int:
        """
        Calculate P(n,r) = n! / (n-r)!
        Number of ways to arrange r items from n
        """
        if r > n or r < 0:
            return 0
        return StatisticsCalculator.factorial(n) // StatisticsCalculator.factorial(n - r)


def main():
    calc = StatisticsCalculator()
    
    print("=" * 60)
    print("STATISTICS CALCULATOR - PYTHON")
    print("=" * 60)
    
    # Sample data
    data = [12, 15, 18, 20, 22, 25, 28, 30, 15, 18]
    
    # Example 1: Central tendency
    print("\n1. CENTRAL TENDENCY")
    print("-" * 60)
    print(f"Data: {data}")
    print(f"Mean: {calc.mean(data):.2f}")
    print(f"Median: {calc.median(data):.2f}")
    print(f"Mode: {calc.mode(data)}")
    
    # Example 2: Dispersion
    print("\n2. MEASURES OF DISPERSION")
    print("-" * 60)
    variance = calc.variance(data, sample=True)
    std = calc.std_dev(data, sample=True)
    print(f"Sample Variance: {variance:.2f}")
    print(f"Sample Standard Deviation: {std:.2f}")
    
    # Example 3: Z-scores
    print("\n3. Z-SCORES")
    print("-" * 60)
    mean_val = calc.mean(data)
    std_val = calc.std_dev(data)
    value = 25
    z = calc.z_score(value, mean_val, std_val)
    print(f"Value: {value}")
    print(f"Z-score: {z:.2f}")
    print(f"Interpretation: {value} is {abs(z):.2f} standard deviations {'above' if z > 0 else 'below'} the mean")
    
    # Example 4: Correlation
    print("\n4. CORRELATION")
    print("-" * 60)
    x = [1, 2, 3, 4, 5]
    y = [2, 4, 5, 4, 5]
    r = calc.correlation(x, y)
    print(f"X: {x}")
    print(f"Y: {y}")
    print(f"Pearson correlation coefficient: {r:.4f}")
    
    if abs(r) > 0.7:
        strength = "strong"
    elif abs(r) > 0.3:
        strength = "moderate"
    else:
        strength = "weak"
    
    direction = "positive" if r > 0 else "negative"
    print(f"Interpretation: {strength} {direction} correlation")
    
    # Example 5: Linear regression
    print("\n5. LINEAR REGRESSION")
    print("-" * 60)
    slope, intercept = calc.linear_regression(x, y)
    print(f"Regression line: y = {slope:.2f}x + {intercept:.2f}")
    print(f"Predicted y when x=6: {slope * 6 + intercept:.2f}")
    
    # Example 6: Combinatorics
    print("\n6. COMBINATORICS")
    print("-" * 60)
    n, r = 10, 3
    print(f"Combination C({n},{r}): {calc.combination(n, r)}")
    print(f"(Choosing {r} items from {n})")
    print(f"\nPermutation P({n},{r}): {calc.permutation(n, r)}")
    print(f"(Arranging {r} items from {n})")
    
    # Example 7: Factorial
    print("\n7. FACTORIAL")
    print("-" * 60)
    for i in [0, 1, 5, 10]:
        print(f"{i}! = {calc.factorial(i)}")
    
    print("\n" + "=" * 60)


if __name__ == "__main__":
    main()
