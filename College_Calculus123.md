Awesome! Here's a structured overview of the **fundamental equations and core concepts of Calculus**, typically split into **Calculus I (Differential Calculus), Calculus II (Integral Calculus),** and **Calculus III (Multivariable Calculus)**:

---

## 📘 **Calculus I – Differential Calculus**

### 🔹 1. Limits and Continuity
- **Definition of a limit:**
  \[
  \lim_{x \to a} f(x) = L
  \]
- **One-sided limits**  
- **Limit Laws**  
- **Continuity:**
  \[
  \text{A function is continuous at } x = a \text{ if } \lim_{x \to a} f(x) = f(a)
  \]

### 🔹 2. Derivatives (Basic Rules)
- **Definition:**
  \[
  f'(x) = \lim_{h \to 0} \frac{f(x+h) - f(x)}{h}
  \]
- **Power Rule:**  
  \[
  \frac{d}{dx}(x^n) = nx^{n-1}
  \]
- **Product Rule:**  
  \[
  (fg)' = f'g + fg'
  \]
- **Quotient Rule:**
  \[
  \left(\frac{f}{g}\right)' = \frac{f'g - fg'}{g^2}
  \]
- **Chain Rule:**
  \[
  \frac{d}{dx}[f(g(x))] = f'(g(x)) \cdot g'(x)
  \]

### 🔹 3. Derivatives of Trig, Exponential, Log Functions
- \( \frac{d}{dx}(\sin x) = \cos x \)
- \( \frac{d}{dx}(\cos x) = -\sin x \)
- \( \frac{d}{dx}(e^x) = e^x \)
- \( \frac{d}{dx}(\ln x) = \frac{1}{x} \)

### 🔹 4. Applications of Derivatives
- **Critical points:** \( f'(x) = 0 \) or undefined
- **Maxima/Minima (First and Second Derivative Tests)**
- **Inflection points:** \( f''(x) = 0 \)
- **Concavity:**
  - \( f''(x) > 0 \Rightarrow \) Concave up
  - \( f''(x) < 0 \Rightarrow \) Concave down
- **Related rates problems**
- **Optimization problems**

---

## 📗 **Calculus II – Integral Calculus**

### 🔹 1. Indefinite Integrals (Antiderivatives)
- **Definition:**
  \[
  \int f(x)\, dx = F(x) + C
  \]
- **Power Rule:**
  \[
  \int x^n\, dx = \frac{x^{n+1}}{n+1} + C \quad (n \ne -1)
  \]

### 🔹 2. Definite Integrals
- **Definition:**
  \[
  \int_a^b f(x)\, dx = \text{net area under } f(x)
  \]
- **Fundamental Theorem of Calculus:**
  \[
  \frac{d}{dx} \left( \int_a^x f(t)\,dt \right) = f(x)
  \]
  \[
  \int_a^b f(x)\,dx = F(b) - F(a)
  \]

### 🔹 3. Techniques of Integration
- Substitution:
  \[
  \int f(g(x))g'(x)\,dx = \int f(u)\,du
  \]
- Integration by Parts:
  \[
  \int u\,dv = uv - \int v\,du
  \]
- Trigonometric identities
- Partial fractions
- Trig substitution

### 🔹 4. Applications of Integrals
- **Area between curves:**
  \[
  A = \int_a^b [f(x) - g(x)]\,dx
  \]
- **Volume (disk/washer method):**
  \[
  V = \pi \int_a^b [f(x)]^2\,dx
  \]
- **Arc length:**
  \[
  L = \int_a^b \sqrt{1 + \left(f'(x)\right)^2}\,dx
  \]
- **Surface area, work, fluid force (advanced topics)**

### 🔹 5. Infinite Series
- Geometric Series:
  \[
  \sum_{n=0}^\infty ar^n = \frac{a}{1 - r}, \quad |r| < 1
  \]
- **Convergence Tests:**
  - nth-Term Test
  - Ratio Test
  - Root Test
  - Integral Test
  - Comparison Test
- **Taylor and Maclaurin Series:**
  \[
  f(x) = \sum_{n=0}^{\infty} \frac{f^{(n)}(a)}{n!}(x - a)^n
  \]

---

## 📙 **Calculus III – Multivariable Calculus**

### 🔹 1. Functions of Several Variables
- \( f(x, y), f(x, y, z) \)
- **Partial derivatives:**
  \[
  \frac{\partial f}{\partial x}, \quad \frac{\partial f}{\partial y}
  \]
- **Gradient vector:**
  \[
  \nabla f = \left\langle \frac{\partial f}{\partial x}, \frac{\partial f}{\partial y} \right\rangle
  \]

### 🔹 2. Multivariable Limits & Continuity
- Limit along paths
- Nonexistence of limits (path dependence)

### 🔹 3. Optimization
- Critical points of \( f(x, y) \)
- Second derivative test for multivariable functions
- Lagrange multipliers for constrained optimization

### 🔹 4. Multiple Integrals
- Double integrals:
  \[
  \iint_R f(x, y)\,dA
  \]
- Triple integrals
- Change of variables: **Polar, cylindrical, spherical coordinates**

### 🔹 5. Vector Calculus
- Vector fields: \( \vec{F}(x, y, z) \)
- Line integrals:
  \[
  \int_C \vec{F} \cdot d\vec{r}
  \]
- Green’s Theorem
- Divergence & Curl
- Surface integrals
- **Stokes' Theorem** and **Divergence Theorem**

---

Would you like a **cheat sheet**, **problem sets**, or visual diagrams** for any of these sections? I can also go deeper into any specific equation or technique!
