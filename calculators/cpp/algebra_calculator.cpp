// Algebra Calculator - C++ Implementation
// Demonstrates polynomial operations, equation solving

#include <iostream>
#include <cmath>
#include <vector>
#include <complex>
#include <iomanip>
#include <string>
#include <algorithm>

class AlgebraCalculator {
public:
    // Solve ax² + bx + c = 0 using the quadratic formula
    static std::pair<std::complex<double>, std::complex<double>> 
    quadraticFormula(double a, double b, double c) {
        double discriminant = b * b - 4.0 * a * c;

        if (discriminant >= 0) {
            double x1 = (-b + std::sqrt(discriminant)) / (2.0 * a);
            double x2 = (-b - std::sqrt(discriminant)) / (2.0 * a);
            return {std::complex<double>(x1, 0), std::complex<double>(x2, 0)};
        } else {
            double realPart = -b / (2.0 * a);
            double imagPart = std::sqrt(std::abs(discriminant)) / (2.0 * a);
            return {std::complex<double>(realPart, imagPart), 
                    std::complex<double>(realPart, -imagPart)};
        }
    }

    // Evaluate polynomial using Horner's method
    // coefficients: [a_0, a_1, ..., a_n] (constant term first)
    static double evaluatePolynomial(const std::vector<double>& coefficients, double x) {
        double result = 0.0;
        for (int i = coefficients.size() - 1; i >= 0; i--) {
            result = result * x + coefficients[i];
        }
        return result;
    }

    // Compute derivative of polynomial
    static std::vector<double> polynomialDerivative(const std::vector<double>& coefficients) {
        if (coefficients.size() <= 1) {
            return {0.0};
        }

        std::vector<double> derivative;
        for (size_t i = 1; i < coefficients.size(); i++) {
            derivative.push_back(i * coefficients[i]);
        }
        return derivative;
    }

    // Greatest Common Divisor using Euclidean algorithm
    static long long gcd(long long a, long long b) {
        a = std::abs(a);
        b = std::abs(b);
        while (b != 0) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Least Common Multiple
    static long long lcm(long long a, long long b) {
        return std::abs(a * b) / gcd(a, b);
    }

    // Generate arithmetic sequence: a_n = a_1 + (n-1)d
    static std::vector<double> arithmeticSequence(double a1, double d, int n) {
        std::vector<double> sequence;
        for (int i = 0; i < n; i++) {
            sequence.push_back(a1 + i * d);
        }
        return sequence;
    }

    // Generate geometric sequence: a_n = a_1 * r^(n-1)
    static std::vector<double> geometricSequence(double a1, double r, int n) {
        std::vector<double> sequence;
        for (int i = 0; i < n; i++) {
            sequence.push_back(a1 * std::pow(r, i));
        }
        return sequence;
    }

    // Sum of arithmetic sequence: S_n = n(a_1 + a_n) / 2
    static double arithmeticSum(double a1, double an, int n) {
        return n * (a1 + an) / 2.0;
    }

    // Sum of geometric sequence: S_n = a_1(1 - r^n) / (1 - r)
    static double geometricSum(double a1, double r, int n) {
        if (std::abs(r - 1.0) < 1e-10) {
            return a1 * n;
        }
        return a1 * (1.0 - std::pow(r, n)) / (1.0 - r);
    }
};

int main() {
    std::cout << std::string(60, '=') << std::endl;
    std::cout << "ALGEBRA CALCULATOR - C++" << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    std::cout << std::fixed << std::setprecision(6);

    // Example 1: Quadratic formula
    std::cout << "\n1. QUADRATIC FORMULA" << std::endl;
    std::cout << std::string(60, '-') << std::endl;
    double a = 1.0, b = -5.0, c = 6.0; // x² - 5x + 6 = 0
    auto [x1, x2] = AlgebraCalculator::quadraticFormula(a, b, c);
    std::cout << "Equation: " << a << "x² + (" << b << ")x + " << c << " = 0" << std::endl;
    std::cout << "Solutions: x₁ = " << x1 << ", x₂ = " << x2 << std::endl;

    // Example 2: Complex roots
    a = 1.0; b = 0.0; c = 4.0; // x² + 4 = 0
    auto [x3, x4] = AlgebraCalculator::quadraticFormula(a, b, c);
    std::cout << "\nEquation: " << a << "x² + " << c << " = 0" << std::endl;
    std::cout << "Solutions: x₁ = " << x3 << ", x₂ = " << x4 << std::endl;

    // Example 3: Polynomial evaluation
    std::cout << "\n2. POLYNOMIAL EVALUATION" << std::endl;
    std::cout << std::string(60, '-') << std::endl;
    std::vector<double> coeffs = {1.0, 2.0, 3.0}; // 3x² + 2x + 1
    double x = 2.0;
    double result = AlgebraCalculator::evaluatePolynomial(coeffs, x);
    std::cout << "P(x) = 3x² + 2x + 1" << std::endl;
    std::cout << "P(" << x << ") = " << result << std::endl;
    std::cout << "Verification: 3(" << x << ")² + 2(" << x << ") + 1 = " 
              << (3.0 * x * x + 2.0 * x + 1.0) << " ✓" << std::endl;

    // Example 4: Polynomial derivative
    std::cout << "\n3. POLYNOMIAL DERIVATIVE" << std::endl;
    std::cout << std::string(60, '-') << std::endl;
    std::vector<double> coeffs2 = {5.0, 0.0, 3.0, 2.0}; // 2x³ + 3x² + 5
    auto derivCoeffs = AlgebraCalculator::polynomialDerivative(coeffs2);
    std::cout << "P(x) = 2x³ + 3x² + 5" << std::endl;
    std::cout << "P'(x) coefficients: [";
    for (size_t i = 0; i < derivCoeffs.size(); i++) {
        std::cout << derivCoeffs[i];
        if (i < derivCoeffs.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
    std::cout << "P'(x) = 6x² + 6x ✓" << std::endl;

    // Example 5: GCD and LCM
    std::cout << "\n4. GCD AND LCM" << std::endl;
    std::cout << std::string(60, '-') << std::endl;
    long long num1 = 48, num2 = 18;
    std::cout << "GCD(" << num1 << ", " << num2 << ") = " 
              << AlgebraCalculator::gcd(num1, num2) << std::endl;
    std::cout << "LCM(" << num1 << ", " << num2 << ") = " 
              << AlgebraCalculator::lcm(num1, num2) << std::endl;

    // Example 6: Arithmetic sequence
    std::cout << "\n5. ARITHMETIC SEQUENCE" << std::endl;
    std::cout << std::string(60, '-') << std::endl;
    double a1 = 3.0, d = 5.0;
    int n = 8;
    auto seq = AlgebraCalculator::arithmeticSequence(a1, d, n);
    std::cout << "First term: " << a1 << ", Common difference: " << d << std::endl;
    std::cout << "First " << n << " terms: [";
    for (size_t i = 0; i < seq.size(); i++) {
        std::cout << seq[i];
        if (i < seq.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
    double sumSeq = AlgebraCalculator::arithmeticSum(a1, seq.back(), n);
    std::cout << "Sum: " << sumSeq << std::endl;

    // Example 7: Geometric sequence
    std::cout << "\n6. GEOMETRIC SEQUENCE" << std::endl;
    std::cout << std::string(60, '-') << std::endl;
    a1 = 2.0;
    double r = 3.0;
    n = 6;
    auto geoSeq = AlgebraCalculator::geometricSequence(a1, r, n);
    std::cout << "First term: " << a1 << ", Common ratio: " << r << std::endl;
    std::cout << "First " << n << " terms: [";
    for (size_t i = 0; i < geoSeq.size(); i++) {
        std::cout << geoSeq[i];
        if (i < geoSeq.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
    double geoSum = AlgebraCalculator::geometricSum(a1, r, n);
    std::cout << "Sum: " << geoSum << std::endl;

    std::cout << "\n" << std::string(60, '=') << std::endl;

    return 0;
}
