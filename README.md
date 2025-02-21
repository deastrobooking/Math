# 

# Introduction to Calculus

Calculus is a branch of mathematics that studies how things change. It provides a framework for modeling systems in which change occurs and is fundamental to many areas of science, engineering, and economics. The two main branches of calculus are **differential calculus** and **integral calculus**.

## 1. The Big Ideas of Calculus
Calculus is built on two fundamental ideas:
- **Derivatives**: Measure how a function changes at a given point (rate of change).
- **Integrals**: Measure the accumulation of quantities (such as area under a curve).

These two concepts are connected through the **Fundamental Theorem of Calculus**, which states that differentiation and integration are inverse processes.

## 2. Limits: The Foundation of Calculus
Calculus relies on the concept of a **limit**, which describes what happens to a function as its input approaches a particular value. Formally, the limit of a function \( f(x) \) as \( x \) approaches a value \( a \) is written as:

## $$\lim\limits_{x \to a} f(x)$$

If the function approaches a specific value, the limit exists. Limits allow us to define derivatives and integrals rigorously.

## 3. Derivatives: Understanding Rates of Change
The derivative of a function represents the rate at which it changes. The derivative of $\( f(x) \)$ at a point $\( x = a \)$ is defined as:

 ## $$f'(a) = \lim\limits_{h \to 0} \frac{f(a+h) - f(a)}{h}$$

This measures the slope of the tangent line to the function at that point. Common derivative rules include:
- Power rule: $$\( \frac{d}{dx} x^n = n x^{n-1} \)$$
- Product rule:$$\( (uv)' = u'v + uv' \)$$
- Quotient rule: $$\( \left(\frac{u}{v}\right)' = \frac{u'v - uv'}{v^2} \)$$
- Chain rule: $\( (f(g(x)))' = f'(g(x))g'(x) \)$

## 4. Integrals: Accumulation and Area
Integration is the process of finding the **antiderivative** of a function or calculating the **area under a curve**. The **definite integral** from \( a \) to \( b \) is written as:

 # $$\int_a^b f(x)dx$$

This represents the total accumulation of the function between \( a \) and \( b \). Common integration rules include:
- Power rule: \( \int x^n dx = \frac{x^{n+1}}{n+1} + C \) (for \( n \neq -1 \))
- Substitution method: Used to simplify complex integrals
- Integration by parts: \( \int u dv = uv - \int v du \)

## 5. Fundamental Theorem of Calculus
The **Fundamental Theorem of Calculus** links derivatives and integrals:
1. If $\( F(x) \)$ is an antiderivative of $\( f(x) \)$, then:

 # $$\int_a^b f(x)dx = F(b) - F(a)$$

2. Differentiation and integration are inverse operations:

 # $$\frac{d}{dx} \int_a^x f(t)dt = f(x)$$


## 6. Applications of Calculus
Calculus is used in various fields to model and solve problems involving change and accumulation:
- **Physics**: Motion, forces, energy, and electromagnetism
- **Engineering**: Signal processing, fluid dynamics, and structural analysis
- **Economics**: Optimization, marginal cost, and revenue analysis
- **Biology**: Population growth and reaction rates in chemistry

# Lesson: Differentiation Rules in Calculus

## Introduction
Differentiation is a fundamental concept in calculus that deals with the rate at which a function changes. In this lesson, we will cover the essential differentiation rules that simplify the process of finding derivatives.

---

## 1. Power Rule
If a function is given by:
## $$\[ f(x) = x^n \]$$
where $$\( n \)$$ is any real number, its derivative is:
## $$\[ \frac{d}{dx} x^n = n x^{n-1} \]$$

**Example:**
### $$\[ \frac{d}{dx} x^5 = 5x^4 \]$$

---

## 2. Constant Rule
If $$\( f(x) = c \)$$ where $$\( c \)$$ is a constant, then:
### $$\[ \frac{d}{dx} c = 0 \]$$

**Example:**
### $$\[ \frac{d}{dx} 7 = 0 \]$$

---

## 3. Constant Multiple Rule
If **$$\( f(x) = c g(x) \)$$**, where **$$\( c \)$$** is a constant, then:
## $$\[ \frac{d}{dx} (c g(x)) = c \frac{d}{dx} g(x) \]$$

**Example:**
### **$$\[ \frac{d}{dx} (3x^4) = 3 \cdot 4x^3 = 12x^3 \]$$**

---

## 4. Sum and Difference Rule
If **$$\( f(x) = g(x) \pm h(x) \)$$**, then:
## $$\[ \frac{d}{dx} (g(x) \pm h(x)) = \frac{d}{dx} g(x) \pm \frac{d}{dx} h(x) \]$$

**Example:**
### $$\[ \frac{d}{dx} (x^3 + x^2) = 3x^2 + 2x \]$$

---

## 5. Product Rule
If **$$\( f(x) = g(x)h(x) \)$$**, then:
## **$$\[ \frac{d}{dx} [g(x)h(x)] = g(x) \frac{d}{dx} h(x) + h(x) \frac{d}{dx} g(x) \]$$** 

**Example:**
### $$\[ \frac{d}{dx} (x^2 \cdot \sin x) = x^2 \cos x + 2x \sin x \]$$

---

## 6. Quotient Rule
If **$$\( f(x) = \frac{g(x)}{h(x)} \$$**, then:
## $$\[ \frac{d}{dx} \left( \frac{g(x)}{h(x)} \right) = \frac{g'(x) h(x) - g(x) h'(x)}{[h(x)]^2} \]$$

**Example:**
### $$\[ \frac{d}{dx} \left( \frac{x^2}{x+1} \right) = \frac{2x(x+1) - x^2(1)}{(x+1)^2} = \frac{x^2 + 2x}{(x+1)^2} \]$$

---

## 7. Chain Rule
If **$$\( y = f(g(x)) \)$$**, then:
## $$\[ \frac{d}{dx} f(g(x)) = f'(g(x)) \cdot g'(x) \]$$

**Example:**
### $$\[ \frac{d}{dx} (\sin(x^2)) = \cos(x^2) \cdot 2x = 2x \cos(x^2) \]$$

---

## 8. Special Derivatives
**- $$\( \frac{d}{dx} e^x = e^x \)$$**
**- $$\( \frac{d}{dx} a^x = a^x \ln a \)$$**
**- $$\( \frac{d}{dx} \ln x = \frac{1}{x} \)$$**
- \( \frac{d}{dx} \sin x = \cos x \)
- \( \frac{d}{dx} \cos x = -\sin x \)
- \( \frac{d}{dx} \tan x = \sec^2 x \)

---

## Conclusion
These differentiation rules provide the foundation for solving calculus problems efficiently. Mastering these rules allows for easier computation of derivatives in more complex mathematical and real-world applications.


