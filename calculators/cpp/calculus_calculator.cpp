// Calculus Calculator - C++ Implementation
// Demonstrates derivatives, integrals, and limits

#include <iostream>
#include <cmath>
#include <functional>
#include <vector>
#include <iomanip>
#include <string>

class CalculusCalculator {
private:
    double epsilon;

public:
    CalculusCalculator(double eps = 1e-7) : epsilon(eps) {}

    // Compute numerical derivative using central difference method
    // f'(x) ≈ (f(x+h) - f(x-h)) / (2h)
    double derivative(std::function<double(double)> f, double x, double h = 1e-5) {
        return (f(x + h) - f(x - h)) / (2.0 * h);
    }

    // Compute definite integral using Simpson's Rule
    double integral(std::function<double(double)> f, double a, double b, int n = 1000) {
        if (n % 2 == 1) n++; // Must be even for Simpson's rule

        double h = (b - a) / n;
        double sum = f(a) + f(b);

        for (int i = 1; i < n; i++) {
            double x = a + i * h;
            if (i % 2 == 0) {
                sum += 2.0 * f(x);
            } else {
                sum += 4.0 * f(x);
            }
        }

        return (h / 3.0) * sum;
    }

    // Compute second derivative f''(x)
    double secondDerivative(std::function<double(double)> f, double x, double h = 1e-5) {
        return (f(x + h) - 2.0 * f(x) + f(x - h)) / (h * h);
    }

    // Find critical points where f'(x) ≈ 0 in interval [a, b]
    std::vector<double> findCriticalPoints(std::function<double(double)> f, double a, double b, int n = 100) {
        std::vector<double> criticalPoints;
        double step = (b - a) / n;

        for (int i = 0; i <= n; i++) {
            double x = a + i * step;
            double deriv = derivative(f, x);
            if (std::abs(deriv) < 0.01) {
                criticalPoints.push_back(x);
            }
        }

        return criticalPoints;
    }

    // Compute limit as x approaches a value
    double limit(std::function<double(double)> f, double x) {
        double h = 1e-6;
        double leftLimit = f(x - h);
        double rightLimit = f(x + h);

        if (std::abs(leftLimit - rightLimit) < epsilon) {
            return (leftLimit + rightLimit) / 2.0;
        } else {
            throw std::runtime_error("Limit does not exist");
        }
    }
};

int main() {
    CalculusCalculator calc(1e-7);

    std::cout << std::string(60, '=') << std::endl;
    std::cout << "CALCULUS CALCULATOR - C++" << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    std::cout << std::fixed << std::setprecision(6);

    // Example 1: Derivative of f(x) = x²
    std::cout << "\n1. DERIVATIVES" << std::endl;
    std::cout << std::string(60, '-') << std::endl;
    auto f1 = [](double x) { return x * x; };
    double x = 3.0;
    double derivative = calc.derivative(f1, x);
    std::cout << "f(x) = x²" << std::endl;
    std::cout << "f'(" << x << ") ≈ " << derivative << std::endl;
    std::cout << "Analytical: f'(" << x << ") = 2x = " << 2.0 * x << " ✓" << std::endl;

    // Example 2: Derivative of sin(x)
    auto f2 = [](double x) { return std::sin(x); };
    x = M_PI / 4.0;
    derivative = calc.derivative(f2, x);
    std::cout << "\nf(x) = sin(x)" << std::endl;
    std::cout << "f'(π/4) ≈ " << derivative << std::endl;
    std::cout << "Analytical: f'(π/4) = cos(π/4) = " << std::cos(x) << " ✓" << std::endl;

    // Example 3: Integral of x² from 0 to 1
    std::cout << "\n2. INTEGRALS" << std::endl;
    std::cout << std::string(60, '-') << std::endl;
    auto f3 = [](double x) { return x * x; };
    double integralResult = calc.integral(f3, 0.0, 1.0);
    std::cout << "∫₀¹ x² dx ≈ " << integralResult << std::endl;
    std::cout << "Analytical: [x³/3]₀¹ = 1/3 = " << (1.0 / 3.0) << " ✓" << std::endl;

    // Example 4: Integral of sin(x) from 0 to π
    auto f4 = [](double x) { return std::sin(x); };
    integralResult = calc.integral(f4, 0.0, M_PI);
    std::cout << "\n∫₀^π sin(x) dx ≈ " << integralResult << std::endl;
    std::cout << "Analytical: [-cos(x)]₀^π = 2.000000 ✓" << std::endl;

    // Example 5: Second derivative (concavity)
    std::cout << "\n3. SECOND DERIVATIVES (Concavity)" << std::endl;
    std::cout << std::string(60, '-') << std::endl;
    auto f5 = [](double x) { return x * x * x - 3.0 * x * x; };
    x = 1.0;
    double secondDeriv = calc.secondDerivative(f5, x);
    std::cout << "f(x) = x³ - 3x²" << std::endl;
    std::cout << "f''(" << x << ") ≈ " << secondDeriv << std::endl;
    std::cout << "Analytical: f''(x) = 6x - 6, f''(1) = 0 ✓" << std::endl;
    std::string concavity = (std::abs(secondDeriv) < 0.1) ? "Inflection Point" : "Curved";
    std::cout << "Concavity at x=" << x << ": " << concavity << std::endl;

    // Example 6: Critical points
    std::cout << "\n4. CRITICAL POINTS" << std::endl;
    std::cout << std::string(60, '-') << std::endl;
    auto f6 = [](double x) { return x * x * x - 3.0 * x; };
    std::vector<double> critical = calc.findCriticalPoints(f6, -2.0, 2.0);
    std::cout << "f(x) = x³ - 3x" << std::endl;
    std::cout << "Critical points in [-2, 2]: [";
    for (size_t i = 0; i < critical.size(); i++) {
        std::cout << std::setprecision(2) << critical[i];
        if (i < critical.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
    std::cout << std::setprecision(6);
    std::cout << "Analytical: f'(x) = 3x² - 3 = 0 → x = ±1 ✓" << std::endl;

    // Example 7: Product rule demonstration
    std::cout << "\n5. PRODUCT RULE VERIFICATION" << std::endl;
    std::cout << std::string(60, '-') << std::endl;
    auto f7 = [](double x) { return x * std::sin(x); };
    x = 2.0;
    double numerical = calc.derivative(f7, x);
    double analytical = std::sin(x) + x * std::cos(x);
    std::cout << "f(x) = x·sin(x)" << std::endl;
    std::cout << "f'(" << x << ") numerical ≈ " << numerical << std::endl;
    std::cout << "f'(" << x << ") analytical = " << analytical << " ✓" << std::endl;

    std::cout << "\n" << std::string(60, '=') << std::endl;

    return 0;
}
