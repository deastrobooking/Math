#!/usr/bin/env python3
"""
Algebra Calculator - Python Implementation
Demonstrates polynomial operations, equation solving, and factoring
"""

import math
from typing import List, Tuple, Optional


class AlgebraCalculator:
    """Calculator for algebraic operations"""
    
    @staticmethod
    def quadratic_formula(a: float, b: float, c: float) -> Tuple[Optional[complex], Optional[complex]]:
        """
        Solve ax² + bx + c = 0 using the quadratic formula
        x = (-b ± √(b² - 4ac)) / (2a)
        
        Returns:
            Tuple of two solutions (may be complex)
        """
        discriminant = b**2 - 4*a*c
        
        if discriminant >= 0:
            x1 = (-b + math.sqrt(discriminant)) / (2*a)
            x2 = (-b - math.sqrt(discriminant)) / (2*a)
            return (x1, x2)
        else:
            real_part = -b / (2*a)
            imag_part = math.sqrt(abs(discriminant)) / (2*a)
            x1 = complex(real_part, imag_part)
            x2 = complex(real_part, -imag_part)
            return (x1, x2)
    
    @staticmethod
    def evaluate_polynomial(coefficients: List[float], x: float) -> float:
        """
        Evaluate polynomial using Horner's method
        P(x) = a_n*x^n + a_(n-1)*x^(n-1) + ... + a_1*x + a_0
        
        Args:
            coefficients: [a_0, a_1, ..., a_n] (constant term first)
            x: Value at which to evaluate
        
        Returns:
            P(x)
        """
        result = 0
        for i in range(len(coefficients) - 1, -1, -1):
            result = result * x + coefficients[i]
        return result
    
    @staticmethod
    def polynomial_derivative(coefficients: List[float]) -> List[float]:
        """
        Compute derivative of polynomial
        If P(x) = a_n*x^n + ... + a_1*x + a_0
        Then P'(x) = n*a_n*x^(n-1) + ... + 2*a_2*x + a_1
        
        Args:
            coefficients: [a_0, a_1, ..., a_n]
        
        Returns:
            Coefficients of derivative polynomial
        """
        if len(coefficients) <= 1:
            return [0]
        
        return [i * coefficients[i] for i in range(1, len(coefficients))]
    
    @staticmethod
    def gcd(a: int, b: int) -> int:
        """
        Greatest Common Divisor using Euclidean algorithm
        """
        while b:
            a, b = b, a % b
        return abs(a)
    
    @staticmethod
    def lcm(a: int, b: int) -> int:
        """
        Least Common Multiple
        """
        return abs(a * b) // AlgebraCalculator.gcd(a, b)
    
    @staticmethod
    def factor_quadratic(a: int, b: int, c: int) -> Optional[Tuple[Tuple[int, int], Tuple[int, int]]]:
        """
        Factor quadratic ax² + bx + c into (mx + n)(px + q)
        Only works for integer factorizations
        
        Returns:
            ((m, n), (p, q)) if factorizable, None otherwise
        """
        # Find two numbers that multiply to a*c and add to b
        ac = a * c
        
        for i in range(-abs(ac), abs(ac) + 1):
            if i == 0:
                continue
            if ac % i == 0:
                j = ac // i
                if i + j == b:
                    # Found the pair!
                    # Now construct factors
                    gcd_val = AlgebraCalculator.gcd(a, i)
                    m = a // gcd_val if gcd_val != 0 else a
                    n = i // gcd_val if gcd_val != 0 else i
                    p = gcd_val
                    q = j
                    return ((m, n), (p, q))
        
        return None
    
    @staticmethod
    def arithmetic_sequence(a1: float, d: float, n: int) -> List[float]:
        """
        Generate arithmetic sequence
        a_n = a_1 + (n-1)d
        
        Args:
            a1: First term
            d: Common difference
            n: Number of terms
        """
        return [a1 + i*d for i in range(n)]
    
    @staticmethod
    def geometric_sequence(a1: float, r: float, n: int) -> List[float]:
        """
        Generate geometric sequence
        a_n = a_1 * r^(n-1)
        
        Args:
            a1: First term
            r: Common ratio
            n: Number of terms
        """
        return [a1 * (r ** i) for i in range(n)]
    
    @staticmethod
    def arithmetic_sum(a1: float, an: float, n: int) -> float:
        """
        Sum of arithmetic sequence
        S_n = n(a_1 + a_n) / 2
        """
        return n * (a1 + an) / 2
    
    @staticmethod
    def geometric_sum(a1: float, r: float, n: int) -> float:
        """
        Sum of geometric sequence
        S_n = a_1(1 - r^n) / (1 - r) for r ≠ 1
        """
        if abs(r - 1) < 1e-10:
            return a1 * n
        return a1 * (1 - r**n) / (1 - r)


def main():
    calc = AlgebraCalculator()
    
    print("=" * 60)
    print("ALGEBRA CALCULATOR - PYTHON")
    print("=" * 60)
    
    # Example 1: Quadratic formula
    print("\n1. QUADRATIC FORMULA")
    print("-" * 60)
    a, b, c = 1, -5, 6  # x² - 5x + 6 = 0
    x1, x2 = calc.quadratic_formula(a, b, c)
    print(f"Equation: {a}x² + ({b})x + {c} = 0")
    print(f"Solutions: x₁ = {x1}, x₂ = {x2}")
    print(f"Factored form: (x - {x1})(x - {x2}) = 0 ✓")
    
    # Example 2: Complex roots
    a, b, c = 1, 0, 4  # x² + 4 = 0
    x1, x2 = calc.quadratic_formula(a, b, c)
    print(f"\nEquation: {a}x² + {c} = 0")
    print(f"Solutions: x₁ = {x1}, x₂ = {x2}")
    
    # Example 3: Polynomial evaluation
    print("\n2. POLYNOMIAL EVALUATION")
    print("-" * 60)
    coeffs = [1, 2, 3]  # 3x² + 2x + 1
    x = 2
    result = calc.evaluate_polynomial(coeffs, x)
    print(f"P(x) = 3x² + 2x + 1")
    print(f"P({x}) = {result}")
    print(f"Verification: 3({x})² + 2({x}) + 1 = {3*x**2 + 2*x + 1} ✓")
    
    # Example 4: Polynomial derivative
    print("\n3. POLYNOMIAL DERIVATIVE")
    print("-" * 60)
    coeffs = [5, 0, 3, 2]  # 2x³ + 3x² + 5
    deriv_coeffs = calc.polynomial_derivative(coeffs)
    print(f"P(x) = 2x³ + 3x² + 5")
    print(f"P'(x) coefficients: {deriv_coeffs}")
    print(f"P'(x) = 6x² + 6x ✓")
    
    # Example 5: GCD and LCM
    print("\n4. GCD AND LCM")
    print("-" * 60)
    a, b = 48, 18
    print(f"GCD({a}, {b}) = {calc.gcd(a, b)}")
    print(f"LCM({a}, {b}) = {calc.lcm(a, b)}")
    
    # Example 6: Arithmetic sequence
    print("\n5. ARITHMETIC SEQUENCE")
    print("-" * 60)
    a1, d, n = 3, 5, 8
    seq = calc.arithmetic_sequence(a1, d, n)
    print(f"First term: {a1}, Common difference: {d}")
    print(f"First {n} terms: {seq}")
    sum_seq = calc.arithmetic_sum(a1, seq[-1], n)
    print(f"Sum: {sum_seq}")
    
    # Example 7: Geometric sequence
    print("\n6. GEOMETRIC SEQUENCE")
    print("-" * 60)
    a1, r, n = 2, 3, 6
    seq = calc.geometric_sequence(a1, r, n)
    print(f"First term: {a1}, Common ratio: {r}")
    print(f"First {n} terms: {seq}")
    sum_seq = calc.geometric_sum(a1, r, n)
    print(f"Sum: {sum_seq}")
    
    print("\n" + "=" * 60)


if __name__ == "__main__":
    main()
