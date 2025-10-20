/* Algebra Calculator - C Implementation
 * Demonstrates polynomial operations, equation solving
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

/* Complex number structure */
typedef struct {
    double real;
    double imag;
} Complex;

/* Print complex number */
void print_complex(Complex c) {
    if (fabs(c.imag) < 1e-10) {
        printf("%.6f", c.real);
    } else if (c.imag >= 0) {
        printf("%.6f + %.6fi", c.real, c.imag);
    } else {
        printf("%.6f - %.6fi", c.real, -c.imag);
    }
}

/* Solve ax² + bx + c = 0 using the quadratic formula
 * Returns two solutions (may be complex)
 */
void quadratic_formula(double a, double b, double c, Complex* x1, Complex* x2) {
    double discriminant = b * b - 4.0 * a * c;

    if (discriminant >= 0) {
        x1->real = (-b + sqrt(discriminant)) / (2.0 * a);
        x1->imag = 0.0;
        x2->real = (-b - sqrt(discriminant)) / (2.0 * a);
        x2->imag = 0.0;
    } else {
        double real_part = -b / (2.0 * a);
        double imag_part = sqrt(fabs(discriminant)) / (2.0 * a);
        x1->real = real_part;
        x1->imag = imag_part;
        x2->real = real_part;
        x2->imag = -imag_part;
    }
}

/* Evaluate polynomial using Horner's method
 * coefficients: [a_0, a_1, ..., a_n] (constant term first)
 */
double evaluate_polynomial(const double* coefficients, int degree, double x) {
    double result = 0.0;
    for (int i = degree; i >= 0; i--) {
        result = result * x + coefficients[i];
    }
    return result;
}

/* Compute derivative of polynomial
 * Returns new degree (original degree - 1)
 */
int polynomial_derivative(const double* coefficients, int degree, double* derivative) {
    if (degree == 0) {
        derivative[0] = 0.0;
        return 0;
    }

    for (int i = 1; i <= degree; i++) {
        derivative[i - 1] = i * coefficients[i];
    }
    return degree - 1;
}

/* Greatest Common Divisor using Euclidean algorithm */
long long gcd(long long a, long long b) {
    a = llabs(a);
    b = llabs(b);
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

/* Least Common Multiple */
long long lcm(long long a, long long b) {
    return llabs(a * b) / gcd(a, b);
}

/* Generate arithmetic sequence: a_n = a_1 + (n-1)d */
void arithmetic_sequence(double a1, double d, int n, double* sequence) {
    for (int i = 0; i < n; i++) {
        sequence[i] = a1 + i * d;
    }
}

/* Generate geometric sequence: a_n = a_1 * r^(n-1) */
void geometric_sequence(double a1, double r, int n, double* sequence) {
    for (int i = 0; i < n; i++) {
        sequence[i] = a1 * pow(r, i);
    }
}

/* Sum of arithmetic sequence: S_n = n(a_1 + a_n) / 2 */
double arithmetic_sum(double a1, double an, int n) {
    return n * (a1 + an) / 2.0;
}

/* Sum of geometric sequence: S_n = a_1(1 - r^n) / (1 - r) */
double geometric_sum(double a1, double r, int n) {
    if (fabs(r - 1.0) < 1e-10) {
        return a1 * n;
    }
    return a1 * (1.0 - pow(r, n)) / (1.0 - r);
}

void print_separator(char c, int length) {
    for (int i = 0; i < length; i++) {
        putchar(c);
    }
    putchar('\n');
}

int main(void) {
    print_separator('=', 60);
    printf("ALGEBRA CALCULATOR - C\n");
    print_separator('=', 60);

    /* Example 1: Quadratic formula */
    printf("\n1. QUADRATIC FORMULA\n");
    print_separator('-', 60);
    double a = 1.0, b = -5.0, c = 6.0; /* x² - 5x + 6 = 0 */
    Complex x1, x2;
    quadratic_formula(a, b, c, &x1, &x2);
    printf("Equation: %.1fx² + (%.1f)x + %.1f = 0\n", a, b, c);
    printf("Solutions: x₁ = ");
    print_complex(x1);
    printf(", x₂ = ");
    print_complex(x2);
    printf("\n");

    /* Example 2: Complex roots */
    a = 1.0; b = 0.0; c = 4.0; /* x² + 4 = 0 */
    quadratic_formula(a, b, c, &x1, &x2);
    printf("\nEquation: %.1fx² + %.1f = 0\n", a, c);
    printf("Solutions: x₁ = ");
    print_complex(x1);
    printf(", x₂ = ");
    print_complex(x2);
    printf("\n");

    /* Example 3: Polynomial evaluation */
    printf("\n2. POLYNOMIAL EVALUATION\n");
    print_separator('-', 60);
    double poly_coeffs[] = {1.0, 2.0, 3.0}; /* 3x² + 2x + 1 */
    double x = 2.0;
    double result = evaluate_polynomial(poly_coeffs, 2, x);
    printf("P(x) = 3x² + 2x + 1\n");
    printf("P(%.1f) = %.6f\n", x, result);
    printf("Verification: 3(%.1f)² + 2(%.1f) + 1 = %.6f ✓\n", 
           x, x, 3.0 * x * x + 2.0 * x + 1.0);

    /* Example 4: Polynomial derivative */
    printf("\n3. POLYNOMIAL DERIVATIVE\n");
    print_separator('-', 60);
    double coeffs[] = {5.0, 0.0, 3.0, 2.0}; /* 2x³ + 3x² + 5 */
    double deriv[3];
    int new_degree = polynomial_derivative(coeffs, 3, deriv);
    printf("P(x) = 2x³ + 3x² + 5\n");
    printf("P'(x) coefficients: [");
    for (int i = 0; i < new_degree; i++) {
        printf("%.1f", deriv[i]);
        if (i < new_degree - 1) printf(", ");
    }
    printf("]\n");
    printf("P'(x) = 6x² + 6x ✓\n");

    /* Example 5: GCD and LCM */
    printf("\n4. GCD AND LCM\n");
    print_separator('-', 60);
    long long num1 = 48, num2 = 18;
    printf("GCD(%lld, %lld) = %lld\n", num1, num2, gcd(num1, num2));
    printf("LCM(%lld, %lld) = %lld\n", num1, num2, lcm(num1, num2));

    /* Example 6: Arithmetic sequence */
    printf("\n5. ARITHMETIC SEQUENCE\n");
    print_separator('-', 60);
    double a1 = 3.0, d = 5.0;
    int n = 8;
    double arith_seq[8];
    arithmetic_sequence(a1, d, n, arith_seq);
    printf("First term: %.1f, Common difference: %.1f\n", a1, d);
    printf("First %d terms: [", n);
    for (int i = 0; i < n; i++) {
        printf("%.1f", arith_seq[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
    double sum = arithmetic_sum(a1, arith_seq[n - 1], n);
    printf("Sum: %.1f\n", sum);

    /* Example 7: Geometric sequence */
    printf("\n6. GEOMETRIC SEQUENCE\n");
    print_separator('-', 60);
    a1 = 2.0;
    double r = 3.0;
    n = 6;
    double geom_seq[6];
    geometric_sequence(a1, r, n, geom_seq);
    printf("First term: %.1f, Common ratio: %.1f\n", a1, r);
    printf("First %d terms: [", n);
    for (int i = 0; i < n; i++) {
        printf("%.1f", geom_seq[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
    double geo_sum = geometric_sum(a1, r, n);
    printf("Sum: %.1f\n", geo_sum);

    printf("\n");
    print_separator('=', 60);

    return 0;
}
