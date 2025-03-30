**Calculus II**—which centers around **integration**, **applications of integrals**, **techniques of integration**, and **infinite series**.

---

## 📘 **1. Indefinite Integrals (Antiderivatives)**

### 🔹 The Goal:
Find a function \( F(x) \) such that \( F'(x) = f(x) \)

### 🔹 Basic Rules:
- $$ \int x^n dx = \frac{x^{n+1}}{n+1} + C \quad (n \ne -1) $$
- $$ \int e^x dx = e^x + C $$
- $$ \int \sin x dx = -\cos x + C $$
- $$ \int \cos x dx = \sin x + C $$

### 🔹 EE Application:
Total **charge** from **current**:
$$
Q(t) = \int_0^t i(t)\,dt
$$

---

## 📗 **2. Definite Integrals and the Fundamental Theorem**

### 🔹 Fundamental Theorem of Calculus (Part 1)
If $$ F(x) $$ is an antiderivative of $$ f(x) $$, then:
$$
\frac{d}{dx} \left( \int_a^x f(t) dt \right) = f(x)
$$

### 🔹 Fundamental Theorem (Part 2)
$$
\int_a^b f(x)\,dx = F(b) - F(a)
$$

### 🔹 Interpretation:
The definite integral is the **net signed area** under the curve.

### 🔹 EE Example:
Power consumption:
$$
\text{Energy } E = \int_0^T P(t)\,dt \quad \text{where } P(t) = V(t) \cdot i(t)
$$

---

## 🧰 **3. Techniques of Integration**

### 🔸 a. **u-Substitution (Reverse Chain Rule):**
$$
\int f(g(x))g'(x)\,dx = \int f(u)\,du
$$

**Example:**
$$
\int x \cos(x^2) dx \quad \text{Let } u = x^2
$$

---

### 🔸 b. **Integration by Parts:**
$$
\int u\,dv = uv - \int v\,du
$$

Useful for:
- Products of polynomial and trig/exp/log
- Deriving formulas (e.g., Laplace transforms)

**EE Example:**
Solving time-domain convolutions in Laplace space.

---

### 🔸 c. **Trigonometric Integrals:**
$$
\int \sin^n x \cos^m x dx
$$

Use identities like:
$$
\sin^2 x = \frac{1 - \cos(2x)}{2}, \quad \cos^2 x = \frac{1 + \cos(2x)}{2}
$$

---

### 🔸 d. **Partial Fractions:**
Decompose rational expressions:
$$
\frac{P(x)}{Q(x)} = \sum \frac{A}{x-a} + \frac{Bx + C}{(x^2 + bx + c)}
$$

**EE Example:** Inverse Laplace transforms.

---

### 🔸 e. **Trigonometric Substitution:**
Great for integrals like:
$$
\int \frac{1}{\sqrt{a^2 - x^2}} dx \Rightarrow x = a \sin \theta
$$

---

## 📐 **4. Applications of Integrals**

### 🔹 a. **Area Between Curves**
$$
A = \int_a^b [f(x) - g(x)] dx
$$

---

### 🔹 b. **Volume of Solids of Revolution**

#### Disk Method:
$$
V = \pi \int_a^b [f(x)]^2 dx
$$

#### Washer Method:
$$
V = \pi \int_a^b \left([R(x)]^2 - [r(x)]^2\right) dx
$$

---

### 🔹 c. **Arc Length**
$$
L = \int_a^b \sqrt{1 + (f'(x))^2} dx
$$

---

### 🔹 d. **Work**
$$
W = \int_a^b F(x) dx
$$

---

### 🔹 e. **Center of Mass, Pressure, Force**
- Centroid of lamina
- Hydrostatic force on submerged objects

---

## 🔁 **5. Improper Integrals**

When:
- One or both bounds are infinite
- Function is undefined on the interval

**Example:**
$$
\int_1^\infty \frac{1}{x^2} dx = \lim_{b \to \infty} \int_1^b \frac{1}{x^2} dx = 1
$$

---

## 🔗 **6. Infinite Sequences and Series**

### 🔸 a. **Geometric Series**
$$
\sum_{n=0}^{\infty} ar^n = \frac{a}{1 - r}, \quad |r| < 1
$$

### 🔸 b. **Tests for Convergence**
- **Divergence Test**: If $$ \lim a_n \ne 0 $$, diverges
- **Integral Test**
- **Comparison Test**
- **Limit Comparison Test**
- **Ratio Test**
- **Root Test**
- **Alternating Series Test**

---

### 🔸 c. **Power Series**
$$
\sum_{n=0}^\infty c_n(x - a)^n
$$

Has **radius of convergence** $$ R $$

---

### 🔸 d. **Taylor and Maclaurin Series**
$$
f(x) = \sum_{n=0}^{\infty} \frac{f^{(n)}(a)}{n!}(x - a)^n
$$

**Example (Maclaurin):**
$$
e^x = \sum_{n=0}^{\infty} \frac{x^n}{n!}
$$

Used in signal processing, circuit design (approximating functions).

---

### A. **Area Between Curves**

Consider two functions:  
$$
f(x) = \sqrt{x}, \quad g(x) = x^2
$$

The area between them from $$ x = 0 $$ to $$ x = 1 $$ is:
$$
A = \int_0^1 (\sqrt{x} - x^2)\, dx
$$

**Diagram Insight:**
- The **upper curve** is $$ \sqrt{x} $$
- The **lower curve** is $$ x^2 $$
- The **shaded region** between them is the area we compute

---

### B. **Solids of Revolution – Disk & Washer Method**

Imagine rotating $$ f(x) = \sqrt{x} $$ around the x-axis from $$ x = 0 $$ to $$ x = 4 $$.

**Disk Method Volume**:
$$
V = \pi \int_0^4 (f(x))^2 dx = \pi \int_0^4 x\, dx
$$

Diagram: The region between the curve and the x-axis gets **swept out**, forming a **solid bowl** shape.

---

### C. **Converging Geometric Series**

The series:
$$
1 + \frac{1}{2} + \frac{1}{4} + \frac{1}{8} + \dots
$$

Diagram: Each term is a **successive slice** of a unit square. You’ll see that the full area **approaches 1**, visually demonstrating convergence.

---

## 🧩 PART 2: **Problem Walkthroughs**

---

### 🧮 **Problem 1: Work Done to Compress a Spring**

By Hooke’s Law:
$$
F(x) = kx
$$

The work to compress a spring from $$ x = 0 $$ to $$ x = a $$ is:
$$
W = \int_0^a kx\, dx = \frac{1}{2}ka^2
$$

**Step-by-step:**
1. Recognize force depends on distance
2. Integrate force over distance
3. Result: work grows quadratically

---

### 🧮 **Problem 2: Arc Length**

Find the arc length of $$ f(x) = \ln x $$ from $$ x = 1 $$ to $$ x = e $$.

$$
L = \int_1^e \sqrt{1 + \left(\frac{d}{dx} \ln x \right)^2} dx
= \int_1^e \sqrt{1 + \left(\frac{1}{x} \right)^2} dx
= \int_1^e \sqrt{1 + \frac{1}{x^2}} dx
$$

This integral has no elementary solution, but it’s solvable numerically or approximated.

---

### 🧮 **Problem 3: Volume – Washer Method**

Region between:
- Outer: $$ R(x) = \sqrt{x} $$
- Inner: $$ r(x) = x/2 $$

Rotated around x-axis from $$ x = 0 $$ to $$ x = 4 $$

$$
V = \pi \int_0^4 \left[ (\sqrt{x})^2 - \left(\frac{x}{2}\right)^2 \right] dx = \pi \int_0^4 \left( x - \frac{x^2}{4} \right) dx
$$

Step-by-step:
1. Square both radii
2. Subtract inner from outer
3. Integrate the difference
4. Multiply by $$ \pi $$

---

## 🎛️ PART 3: **Laplace and Fourier Tie-Ins**

### 🔂 **Laplace Transform: The Calculus II Supertool**

For functions defined piecewise or involving exponential decay, the Laplace transform turns derivatives into **algebra**:

$$
\mathcal{L}\{f(t)\} = \int_0^\infty e^{-st} f(t)\,dt
$$

#### Example:
$$
\mathcal{L}\{e^{-at}\} = \frac{1}{s + a}
$$

This is used in EE to:
- Solve differential equations without integration tricks
- Handle **discontinuous** inputs like step functions

---

### 🎶 **Fourier Series & Transforms**

Used to **decompose periodic functions** into sines and cosines:

$$
f(x) = a_0 + \sum_{n=1}^\infty \left( a_n \cos(nx) + b_n \sin(nx) \right)
$$

#### Key Use Cases in EE:
- Representing signals (square waves, sawtooth, etc.)
- Analyzing frequency content
- Signal filtering and synthesis

---

### 👨‍🏫 EE Tie-In Summary:

| Technique | Purpose |
|----------|---------|
| **Laplace** | Solves DEs, handles switches/decay |
| **Fourier Series** | Represents repeating signals |
| **Fourier Transform** | Handles aperiodic signals in frequency domain |
| **Integration** | Quantities like energy, work, area |
| **Series** | Approximations, convergence of signals |

---

# Fourier Series Approximation: Sawtooth Wave (10 Terms)
![output (2)](https://github.com/user-attachments/assets/33bf9bfc-e06d-4953-9c8a-ba3f699bb4f5)

Here are visualizations of **Fourier series approximations** for both a **square wave** and a **sawtooth wave** using the first 10 harmonics:

---

### 🔷 **Square Wave Approximation** (Top)
- Constructed using only **odd sine harmonics**:  
  $$
  f(t) = \sum_{n=1,3,5,\dots}^{2N-1} \frac{4}{\pi n} \sin(n t)
  $$
- As \( N \) increases, the waveform gets closer to a true square wave.
- Notice the **Gibbs phenomenon**: overshoot near jump discontinuities.

---

### 🟢 **Sawtooth Wave Approximation** (Bottom)
- Uses **all harmonics** with alternating sign:
  $$
  f(t) = \sum_{n=1}^{N} \frac{-2}{\pi n} \sin(n t)
  $$
- Converges more smoothly, but still shows visible ripple at lower \( N \).

---

### 🧠 Why This Matters in EE:
- **Any periodic signal** can be reconstructed using sines and cosines.
- Essential for:
  - **Signal synthesis**
  - **Filtering**
  - **Fourier transforms**
  - **Modulation techniques (AM, FM)**
