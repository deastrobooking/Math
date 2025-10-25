Perfect. Let’s dive deep into **Calculus I (Differential Calculus)**—not just formulas, but the "why" and "how" behind the core ideas. We’ll break it into essential topics, building from limits to the applications of derivatives.

---

## 🧭 **1. Limits and Continuity**

### 🔹 What is a Limit?
A **limit** describes the behavior of a function as the input gets close to a value—even if the function isn’t defined there.

**Example:**
$$
\lim_{x \to 2} (x^2 - 1) = 3
$$
Because as $x$ gets closer to $2$, $x^2 - 1$ gets closer to $3$.

### 🔹 Formal Definition (Epsilon-Delta):
We say:
$$
\lim_{x \to a} f(x) = L
$$
if, for every $\epsilon > 0$, there exists a $\delta > 0$ such that:
$$
0 < |x - a| < \delta \Rightarrow |f(x) - L| < \epsilon
$$

### 🔹 Types of Limits:
- **One-sided limits:** $\lim_{x \to a^-} f(x), \lim_{x \to a^+} f(x)$
- **Infinite limits:** Function grows without bound near a point
- **Limits at infinity:** Behavior as $x \to \infty$

### 🔹 Continuity:
A function $f$ is **continuous at $x = a$** if:
$$
\lim_{x \to a} f(x) = f(a)
$$

---

## ⚡ **2. The Derivative: Rate of Change**

### 🔹 The Core Idea
The derivative measures how fast a function is changing at any point—its **instantaneous rate of change** or the **slope of the tangent line**.

### 🔹 Formal Definition:
$$
f'(x) = \lim_{h \to 0} \frac{f(x+h) - f(x)}{h}
$$

This is the foundation of all differential calculus.

---

## 🧰 **3. Basic Derivative Rules**

### Power Rule:
$$
\frac{d}{dx}(x^n) = nx^{n-1}
$$

### Constant Rule:
$$
\frac{d}{dx}(c) = 0
$$

### Constant Multiple Rule:
$$
\frac{d}{dx}(cf(x)) = c \cdot f'(x)
$$

### Sum/Difference Rule:
$$
\frac{d}{dx}[f(x) \pm g(x)] = f'(x) \pm g'(x)
$$

### Product Rule:
$$
\frac{d}{dx}[f(x)g(x)] = f'(x)g(x) + f(x)g'(x)
$$

### Quotient Rule:
$$
\frac{d}{dx}\left[\frac{f(x)}{g(x)}\right] = \frac{f'(x)g(x) - f(x)g'(x)}{g(x)^2}
$$

### Chain Rule:
$$
\frac{d}{dx}f(g(x)) = f'(g(x)) \cdot g'(x)
$$

---

## 🧪 **4. Derivatives of Special Functions**

### Trigonometric:
- $\frac{d}{dx}(\sin x) = \cos x$
- $\frac{d}{dx}(\cos x) = -\sin x$
- $\frac{d}{dx}(\tan x) = \sec^2 x$

### Exponential & Logs:
- $\frac{d}{dx}(e^x) = e^x$
- $\frac{d}{dx}(a^x) = a^x \ln a$
- $\frac{d}{dx}(\ln x) = \frac{1}{x}$

---

## 📈 **5. Applications of Derivatives**

### 🔹 Finding Tangent Lines:
The derivative gives you the slope:
$$
y - f(a) = f'(a)(x - a)
$$

### 🔹 Increasing/Decreasing Behavior:
- $f'(x) > 0 \Rightarrow f$ is increasing
- $f'(x) < 0 \Rightarrow f$ is decreasing
### 🔹 Critical Points:
Points where $f'(x) = 0$ or undefined.

### 🔹 First Derivative Test:
Used to find **local maxima and minima**.

### 🔹 Second Derivative Test:
- $f''(x) > 0 \Rightarrow$ local **min**
- $f''(x) < 0 \Rightarrow$ local **max**

### 🔹 Concavity:
- $f''(x) > 0 \Rightarrow$ concave **up**
- $f''(x) < 0 \Rightarrow$ concave **down**

### 🔹 Inflection Points:
Where $f''(x) = 0$ and concavity changes
