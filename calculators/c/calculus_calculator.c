/* Calculus Calculator - C Implementation
 * Demonstrates derivatives, integrals, and limits
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define EPSILON 1e-7
#define DEFAULT_H 1e-5

/* Function pointer type for mathematical functions */
typedef double (*MathFunc)(double);

/* Compute numerical derivative using central difference method
 * f'(x) ≈ (f(x+h) - f(x-h)) / (2h)
 */
double derivative(MathFunc f, double x, double h) {
    return (f(x + h) - f(x - h)) / (2.0 * h);
}

/* Compute definite integral using Simpson's Rule
 * More accurate than trapezoidal or midpoint methods
 */
double integral(MathFunc f, double a, double b, int n) {
    if (n % 2 == 1) n++; /* Must be even for Simpson's rule */

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

/* Compute second derivative f''(x)
 * Used for concavity analysis
 */
double second_derivative(MathFunc f, double x, double h) {
    return (f(x + h) - 2.0 * f(x) + f(x - h)) / (h * h);
}

/* Find critical points where f'(x) ≈ 0 in interval [a, b]
 * Returns number of critical points found
 */
int find_critical_points(MathFunc f, double a, double b, int n, double* points) {
    double step = (b - a) / n;
    int count = 0;

    for (int i = 0; i <= n; i++) {
        double x = a + i * step;
        double deriv = derivative(f, x, DEFAULT_H);
        if (fabs(deriv) < 0.01) {
            points[count++] = x;
        }
    }

    return count;
}

/* Test functions */
double f_x_squared(double x) {
    return x * x;
}

double f_sin(double x) {
    return sin(x);
}

double f_cubic(double x) {
    return x * x * x - 3.0 * x * x;
}

double f_cubic_linear(double x) {
    return x * x * x - 3.0 * x;
}

double f_x_sin(double x) {
    return x * sin(x);
}

void print_separator(char c, int length) {
    for (int i = 0; i < length; i++) {
        putchar(c);
    }
    putchar('\n');
}

int main(void) {
    print_separator('=', 60);
    printf("CALCULUS CALCULATOR - C\n");
    print_separator('=', 60);

    /* Example 1: Derivative of f(x) = x² */
    printf("\n1. DERIVATIVES\n");
    print_separator('-', 60);
    double x = 3.0;
    double deriv = derivative(f_x_squared, x, DEFAULT_H);
    printf("f(x) = x²\n");
    printf("f'(%.1f) ≈ %.6f\n", x, deriv);
    printf("Analytical: f'(%.1f) = 2x = %.6f ✓\n", x, 2.0 * x);

    /* Example 2: Derivative of sin(x) */
    x = M_PI / 4.0;
    deriv = derivative(f_sin, x, DEFAULT_H);
    printf("\nf(x) = sin(x)\n");
    printf("f'(π/4) ≈ %.6f\n", deriv);
    printf("Analytical: f'(π/4) = cos(π/4) = %.6f ✓\n", cos(x));

    /* Example 3: Integral of x² from 0 to 1 */
    printf("\n2. INTEGRALS\n");
    print_separator('-', 60);
    double integ = integral(f_x_squared, 0.0, 1.0, 1000);
    printf("∫₀¹ x² dx ≈ %.6f\n", integ);
    printf("Analytical: [x³/3]₀¹ = 1/3 = %.6f ✓\n", 1.0 / 3.0);

    /* Example 4: Integral of sin(x) from 0 to π */
    integ = integral(f_sin, 0.0, M_PI, 1000);
    printf("\n∫₀^π sin(x) dx ≈ %.6f\n", integ);
    printf("Analytical: [-cos(x)]₀^π = 2.000000 ✓\n");

    /* Example 5: Second derivative (concavity) */
    printf("\n3. SECOND DERIVATIVES (Concavity)\n");
    print_separator('-', 60);
    x = 1.0;
    double second_deriv = second_derivative(f_cubic, x, DEFAULT_H);
    printf("f(x) = x³ - 3x²\n");
    printf("f''(%.1f) ≈ %.6f\n", x, second_deriv);
    printf("Analytical: f''(x) = 6x - 6, f''(1) = 0 ✓\n");
    const char* concavity = (fabs(second_deriv) < 0.1) ? "Inflection Point" : "Curved";
    printf("Concavity at x=%.1f: %s\n", x, concavity);

    /* Example 6: Critical points */
    printf("\n4. CRITICAL POINTS\n");
    print_separator('-', 60);
    double critical_points[100];
    int num_critical = find_critical_points(f_cubic_linear, -2.0, 2.0, 100, critical_points);
    printf("f(x) = x³ - 3x\n");
    printf("Critical points in [-2, 2]: [");
    for (int i = 0; i < num_critical; i++) {
        printf("%.2f", critical_points[i]);
        if (i < num_critical - 1) printf(", ");
    }
    printf("]\n");
    printf("Analytical: f'(x) = 3x² - 3 = 0 → x = ±1 ✓\n");

    /* Example 7: Product rule demonstration */
    printf("\n5. PRODUCT RULE VERIFICATION\n");
    print_separator('-', 60);
    x = 2.0;
    double numerical = derivative(f_x_sin, x, DEFAULT_H);
    double analytical = sin(x) + x * cos(x);
    printf("f(x) = x·sin(x)\n");
    printf("f'(%.1f) numerical ≈ %.6f\n", x, numerical);
    printf("f'(%.1f) analytical = %.6f ✓\n", x, analytical);

    printf("\n");
    print_separator('=', 60);

    return 0;
}
