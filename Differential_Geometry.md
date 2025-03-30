# Introduction to Differential Geometry

Differential Geometry is the field of mathematics that uses the tools of calculus and linear algebra to study problems in geometry. It primarily concerns the properties of curves, surfaces, and more generally, differentiable manifolds. It forms the mathematical foundation for modern physics, especially general relativity and gauge theory, and finds applications in robotics, computer vision, and more.

---

## 1. Curves in Euclidean Space

### 1.1 Parametrized Curves
A curve in \( \mathbb{R}^n \) is a smooth function:
\[
\gamma: I \rightarrow \mathbb{R}^n
\]
where \( I \subset \mathbb{R} \) is an interval.

### 1.2 Tangent Vector
The tangent vector to a curve \( \gamma(t) \) is given by:
\[
\gamma'(t) = \frac{d\gamma}{dt}
\]

### 1.3 Arc Length
\[
L = \int_a^b \|\gamma'(t)\| dt
\]

### 1.4 Curvature and Torsion (\( \mathbb{R}^3 \))
- Curvature measures how sharply a curve bends:
\[
\kappa(t) = \frac{\|\gamma'(t) \times \gamma''(t)\|}{\|\gamma'(t)\|^3}
\]
- Torsion measures how the curve twists out of the plane of curvature:
\[
\tau(t) = \frac{(\gamma'(t) \times \gamma''(t)) \cdot \gamma'''(t)}{\|\gamma'(t) \times \gamma''(t)\|^2}
\]

---

## 2. Surfaces in \( \mathbb{R}^3 \)

### 2.1 Parametrized Surfaces
A surface is a map:
\[
\mathbf{x}(u,v): U \subset \mathbb{R}^2 \rightarrow \mathbb{R}^3
\]

### 2.2 Tangent Plane
Defined by the partial derivatives:
\[
T_pS = \text{span}\left\{ \frac{\partial \mathbf{x}}{\partial u}, \frac{\partial \mathbf{x}}{\partial v} \right\}
\]

### 2.3 First Fundamental Form
Encodes the inner product structure:
\[
I = E\,du^2 + 2F\,du\,dv + G\,dv^2
\]
where:
\[
E = \mathbf{x}_u \cdot \mathbf{x}_u, \quad F = \mathbf{x}_u \cdot \mathbf{x}_v, \quad G = \mathbf{x}_v \cdot \mathbf{x}_v
\]

### 2.4 Second Fundamental Form
Captures extrinsic curvature:
\[
II = L\,du^2 + 2M\,du\,dv + N\,dv^2
\]
where:
\[
L = \mathbf{x}_{uu} \cdot \mathbf{n}, \quad M = \mathbf{x}_{uv} \cdot \mathbf{n}, \quad N = \mathbf{x}_{vv} \cdot \mathbf{n}
\]
and \( \mathbf{n} \) is the unit normal vector.

### 2.5 Gaussian and Mean Curvature
- **Gaussian Curvature**:
\[
K = \frac{LN - M^2}{EG - F^2}
\]
- **Mean Curvature**:
\[
H = \frac{EN + GL - 2FM}{2(EG - F^2)}
\]

---

## 3. Differentiable Manifolds

### 3.1 Definition
An \( n \)-dimensional differentiable manifold is a topological space locally homeomorphic to \( \mathbb{R}^n \) with a differentiable structure.

### 3.2 Charts and Atlases
- A **chart**: \( (U, \varphi) \) where \( \varphi: U \rightarrow \mathbb{R}^n \)
- An **atlas** is a collection of charts covering the manifold

### 3.3 Tangent Space
The tangent space at a point \( p \) is the vector space of derivations:
\[
T_pM = \left\{ v: C^\infty(M) \rightarrow \mathbb{R} \mid v(fg) = f(p)v(g) + g(p)v(f) \right\}
\]

### 3.4 Differential Forms and Exterior Derivative
- Differential \( k \)-forms: antisymmetric tensor fields
- Exterior derivative: \( d: \Omega^k(M) \rightarrow \Omega^{k+1}(M) \) satisfying \( d^2 = 0 \)

---

## 4. Connections and Curvature

### 4.1 Affine Connections
A connection defines a way to differentiate vector fields along curves:
\[
\nabla_X Y
\]

### 4.2 Riemannian Geometry
- Riemannian metric: smoothly varying inner product on each tangent space
- Levi-Civita connection: unique torsion-free metric-compatible connection

### 4.3 Riemann Curvature Tensor
\[
R(X, Y)Z = \nabla_X \nabla_Y Z - \nabla_Y \nabla_X Z - \nabla_{[X, Y]}Z
\]
Measures noncommutativity of covariant derivatives.

---

## 5. Applications
- General Relativity (Einstein's equations involve Ricci curvature)
- Geodesics (shortest paths generalizing straight lines)
- Robotics (configuration spaces as manifolds)
- Computer Graphics and Vision (surface modeling)
- Optimization on manifolds (machine learning, signal processing)

---

Differential Geometry blends algebra, analysis, and topology into a powerful toolkit for understanding the geometric structure of mathematical and physical systems.

