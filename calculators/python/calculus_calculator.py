#!/usr/bin/env python3
"""
Calculus Calculator - Python Implementation
Demonstrates derivatives, integrals, and limits
"""

import math
from typing import Callable


class CalculusCalculator:
    """Calculator for basic calculus operations"""
    
    def __init__(self, epsilon: float = 1e-7):
        """Initialize with numerical precision"""
        self.epsilon = epsilon
    
    def derivative(self, f: Callable[[float], float], x: float, h: float = 1e-5) -> float:
        """
        Compute numerical derivative using central difference method
        f'(x) ≈ (f(x+h) - f(x-h)) / (2h)
        
        Args:
            f: Function to differentiate
            x: Point at which to compute derivative
            h: Step size (smaller = more accurate but numerical instability)
        
        Returns:
            Approximate derivative at x
        """
        return (f(x + h) - f(x - h)) / (2 * h)
    
    def integral(self, f: Callable[[float], float], a: float, b: float, n: int = 1000) -> float:
        """
        Compute definite integral using Simpson's Rule
        More accurate than trapezoidal or midpoint methods
        
        Args:
            f: Function to integrate
            a: Lower bound
            b: Upper bound
            n: Number of subdivisions (must be even)
        
        Returns:
            Approximate integral from a to b
        """
        if n % 2 == 1:
            n += 1  # Simpson's rule requires even number of intervals
        
        h = (b - a) / n
        s = f(a) + f(b)
        
        for i in range(1, n):
            x = a + i * h
            if i % 2 == 0:
                s += 2 * f(x)
            else:
                s += 4 * f(x)
        
        return (h / 3) * s
    
    def limit(self, f: Callable[[float], float], x: float, direction: str = 'both') -> float:
        """
        Compute limit as x approaches a value
        
        Args:
            f: Function
            x: Point to approach
            direction: 'left', 'right', or 'both'
        
        Returns:
            Limit value
        """
        h = 1e-6
        
        if direction == 'left':
            return f(x - h)
        elif direction == 'right':
            return f(x + h)
        else:  # both
            left_limit = f(x - h)
            right_limit = f(x + h)
            if abs(left_limit - right_limit) < self.epsilon:
                return (left_limit + right_limit) / 2
            else:
                raise ValueError(f"Limit does not exist: left={left_limit}, right={right_limit}")
    
    def second_derivative(self, f: Callable[[float], float], x: float, h: float = 1e-5) -> float:
        """
        Compute second derivative f''(x)
        Used for concavity analysis
        """
        return (f(x + h) - 2 * f(x) + f(x - h)) / (h ** 2)
    
    def find_critical_points(self, f: Callable[[float], float], a: float, b: float, n: int = 100) -> list:
        """
        Find critical points where f'(x) = 0 in interval [a, b]
        
        Returns:
            List of x values where derivative is approximately zero
        """
        critical_points = []
        step = (b - a) / n
        
        for i in range(n + 1):
            x = a + i * step
            deriv = self.derivative(f, x)
            if abs(deriv) < 0.01:  # Threshold for "close to zero"
                critical_points.append(x)
        
        return critical_points


# Example usage and demonstrations
def main():
    calc = CalculusCalculator()
    
    print("=" * 60)
    print("CALCULUS CALCULATOR - PYTHON")
    print("=" * 60)
    
    # Example 1: Derivative of f(x) = x^2
    print("\n1. DERIVATIVES")
    print("-" * 60)
    f1 = lambda x: x**2
    x = 3
    derivative = calc.derivative(f1, x)
    print(f"f(x) = x²")
    print(f"f'({x}) ≈ {derivative:.6f}")
    print(f"Analytical: f'({x}) = 2x = {2*x} ✓")
    
    # Example 2: Derivative of sin(x)
    f2 = lambda x: math.sin(x)
    x = math.pi / 4
    derivative = calc.derivative(f2, x)
    print(f"\nf(x) = sin(x)")
    print(f"f'(π/4) ≈ {derivative:.6f}")
    print(f"Analytical: f'(π/4) = cos(π/4) = {math.cos(x):.6f} ✓")
    
    # Example 3: Integral of x^2 from 0 to 1
    print("\n2. INTEGRALS")
    print("-" * 60)
    f3 = lambda x: x**2
    integral = calc.integral(f3, 0, 1)
    print(f"∫₀¹ x² dx ≈ {integral:.6f}")
    print(f"Analytical: [x³/3]₀¹ = 1/3 = {1/3:.6f} ✓")
    
    # Example 4: Integral of sin(x) from 0 to π
    f4 = lambda x: math.sin(x)
    integral = calc.integral(f4, 0, math.pi)
    print(f"\n∫₀^π sin(x) dx ≈ {integral:.6f}")
    print(f"Analytical: [-cos(x)]₀^π = 2.000000 ✓")
    
    # Example 5: Second derivative (concavity)
    print("\n3. SECOND DERIVATIVES (Concavity)")
    print("-" * 60)
    f5 = lambda x: x**3 - 3*x**2
    x = 1
    second_deriv = calc.second_derivative(f5, x)
    print(f"f(x) = x³ - 3x²")
    print(f"f''({x}) ≈ {second_deriv:.6f}")
    print(f"Analytical: f''(x) = 6x - 6, f''(1) = 0 ✓")
    print(f"Concavity at x={x}: {'Inflection Point' if abs(second_deriv) < 0.1 else 'Curved'}")
    
    # Example 6: Critical points
    print("\n4. CRITICAL POINTS")
    print("-" * 60)
    f6 = lambda x: x**3 - 3*x
    critical = calc.find_critical_points(f6, -2, 2)
    print(f"f(x) = x³ - 3x")
    print(f"Critical points in [-2, 2]: {[round(x, 2) for x in critical]}")
    print(f"Analytical: f'(x) = 3x² - 3 = 0 → x = ±1 ✓")
    
    # Example 7: Product rule demonstration
    print("\n5. PRODUCT RULE VERIFICATION")
    print("-" * 60)
    # f(x) = x * sin(x), f'(x) = sin(x) + x*cos(x)
    f7 = lambda x: x * math.sin(x)
    x = 2.0
    numerical = calc.derivative(f7, x)
    analytical = math.sin(x) + x * math.cos(x)
    print(f"f(x) = x·sin(x)")
    print(f"f'({x}) numerical ≈ {numerical:.6f}")
    print(f"f'({x}) analytical = {analytical:.6f} ✓")
    
    print("\n" + "=" * 60)


if __name__ == "__main__":
    main()
