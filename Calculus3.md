Excellent—welcome to **Calculus III**, also known as **Multivariable Calculus**. This course extends the tools of Calculus I and II (single-variable) into **functions of two or more variables**, leading to new geometric, physical, and analytical insights.

---

# 🧠 **Calculus III — In-Depth Text**

---

## 📌 **I. Functions of Several Variables**

### 🔹 Multivariable Functions
A function of two variables is written as:
\[
f(x, y)
\]

Represents a surface in 3D space:
- \( x, y \) = input coordinates
- \( z = f(x, y) \) = output height

Example:  
\[
f(x, y) = x^2 + y^2 \quad \Rightarrow \text{a paraboloid}
\]

---

### 🔹 Domain and Range
- **Domain:** All \((x, y)\) for which \( f(x, y) \) is defined
- **Range:** All possible \( z \)-values the function can take

---

### 🔹 Level Curves
A level curve of \( f(x, y) \) is:
\[
f(x, y) = c
\]
This is a 2D slice of the 3D surface.

---

## 📈 **II. Partial Derivatives**

### 🔹 Concept
Take the derivative of a multivariable function with respect to **one variable**, holding the others constant.

\[
f_x(x, y) = \frac{\partial f}{\partial x}, \quad f_y(x, y) = \frac{\partial f}{\partial y}
\]

**Geometric Meaning:**
Slope of the surface in the \( x \)- or \( y \)-direction.

---

### 🔹 Higher-Order Partials
- \( f_{xx}, f_{yy}, f_{xy}, f_{yx} \)
- Mixed partials often equal: \( f_{xy} = f_{yx} \) (if continuous)

---

## 🧮 **III. Gradient, Directional Derivatives, Tangent Planes**

### 🔹 Gradient Vector
\[
\nabla f(x, y) = \left\langle \frac{\partial f}{\partial x}, \frac{\partial f}{\partial y} \right\rangle
\]

- Points in direction of **steepest ascent**
- Magnitude = rate of greatest increase

---

### 🔹 Directional Derivative
Rate of change of \( f \) in direction of unit vector \( \vec{u} \):
\[
D_{\vec{u}} f(x, y) = \nabla f \cdot \vec{u}
\]

---

### 🔹 Tangent Plane to Surface \( z = f(x, y) \)
At point \( (x_0, y_0) \):
\[
z = f(x_0, y_0) + f_x(x_0, y_0)(x - x_0) + f_y(x_0, y_0)(y - y_0)
\]

---

## 🧲 **IV. Optimization**

### 🔹 Critical Points
Set \( \nabla f(x, y) = 0 \) to find critical points.

### 🔹 Second Derivative Test
Given:
\[
D = f_{xx}f_{yy} - (f_{xy})^2
\]

- If \( D > 0 \), \( f_{xx} > 0 \) ⇒ local **min**
- If \( D > 0 \), \( f_{xx} < 0 \) ⇒ local **max**
- If \( D < 0 \) ⇒ **saddle point**
- If \( D = 0 \) ⇒ inconclusive

---

### 🔹 Lagrange Multipliers
To optimize \( f(x, y) \) subject to constraint \( g(x, y) = c \), solve:
\[
\nabla f = \lambda \nabla g
\]

---

## 🔃 **V. Double and Triple Integrals**

### 🔹 Double Integrals
\[
\iint_R f(x, y)\,dA
\]
Computes volume under surface over region \( R \)

- Use rectangular or polar coordinates
- Change of order of integration when needed

---

### 🔹 Triple Integrals
\[
\iiint_E f(x, y, z)\,dV
\]
Volume in 3D or mass if \( f \) is density

---

### 🔹 Change of Variables
- Use **Jacobian determinant** for coordinate transformations
- Polar (2D): \( x = r\cos\theta, y = r\sin\theta \)
- Cylindrical (3D): \( x = r\cos\theta, y = r\sin\theta, z = z \)
- Spherical: \( x = \rho\sin\phi\cos\theta \), etc.

---

## 🧭 **VI. Vector Calculus**

### 🔹 Vector Fields
A vector field assigns a vector to every point in space:
\[
\vec{F}(x, y) = \langle P(x, y), Q(x, y) \rangle
\]

### 🔹 Line Integrals
\[
\int_C \vec{F} \cdot d\vec{r}
\]

- Work done by a force field along a curve

---

### 🔹 Conservative Fields
If \( \vec{F} = \nabla f \), then \( \vec{F} \) is conservative:
\[
\oint_C \vec{F} \cdot d\vec{r} = 0 \quad \text{(closed loop)}
\]

---

### 🔹 Green’s Theorem (2D)
\[
\oint_C \vec{F} \cdot d\vec{r} = \iint_R \left( \frac{\partial Q}{\partial x} - \frac{\partial P}{\partial y} \right) dA
\]

Relates **line integral around a closed curve** to **double integral over region**.

---

### 🔹 Divergence and Curl
- Divergence:
  \[
  \nabla \cdot \vec{F} = \frac{\partial P}{\partial x} + \frac{\partial Q}{\partial y}
  \]
- Curl (2D):
  \[
  \nabla \times \vec{F} = \left( \frac{\partial Q}{\partial x} - \frac{\partial P}{\partial y} \right) \hat{k}
  \]

---

### 🔹 Surface Integrals & Flux
\[
\iint_S \vec{F} \cdot d\vec{S}
\]

- Measures flow of a vector field across a surface

---

### 🔹 Stokes’ Theorem (3D generalization of Green's)
\[
\oint_{\partial S} \vec{F} \cdot d\vec{r} = \iint_S (\nabla \times \vec{F}) \cdot d\vec{S}
\]

---

### 🔹 Divergence Theorem
\[
\iiint_E (\nabla \cdot \vec{F})\, dV = \iint_{\partial E} \vec{F} \cdot d\vec{S}
\]

Relates **total divergence inside a volume** to **flux across its boundary**.

---

## 📊 Real-World Applications

| Field | Application |
|-------|-------------|
| **Engineering** | Heat flow, fluid dynamics, electromagnetism |
| **Physics** | Fields (gravity, EM), potentials, force integrals |
| **Computer Graphics** | Surface normals, shading, vector field design |
| **Machine Learning** | Gradient descent in multivariable loss functions |
| **Meteorology** | Wind vector fields, pressure gradients |

---

# Surface: Z = E^{-X² - Y²}
![output (4)](https://github.com/user-attachments/assets/ddca9494-45df-427d-9a28-d198f25cbaac)


Here are three custom visual diagrams that illustrate key **Calculus III concepts**:

---

### 🔷 1. **Gradient Vector Field** (Left)

- Function: \( f(x, y) = x^2 + y^2 \)
- Gradient: \( \nabla f = \langle 2x, 2y \rangle \)
- Arrows point **outward**—this shows the **steepest direction of increase**.
- The farther from the origin, the **stronger the gradient vector**.

---

### 🌀 2. **Curl Vector Field** (Middle)

- Vector field: \( \vec{F}(x, y) = \langle -y, x \rangle \)
- This field **rotates counterclockwise**—classic example of **non-zero curl**.
- Represents rotation in 2D, like a whirlpool or spinning field.

---

### 🌄 3. **Surface Integral Context** (Right)

- Scalar field: \( z = e^{-x^2 - y^2} \)
- Think of this as a **bell-shaped surface**.
- A surface integral over this might compute:
  - The **flux** of a vector field through the surface
  - The **total mass** if this were a density function

---

### 🧭 **Line Integral Walkthrough**
![output (5)](https://github.com/user-attachments/assets/2369a918-9652-4500-95ad-f4bb078c4cb2)

We computed the **line integral** of the vector field  
\[
\vec{F}(x, y) = \langle y, -x \rangle
\]  
along the **unit circle** \( C \) parameterized by:  
\[
\vec{r}(t) = \langle \cos t, \sin t \rangle, \quad t \in [0, 2\pi]
\]

---

### 🧮 Step-by-Step Breakdown:

#### 1. **Vector Field**
- Each point \( (x, y) \) has a vector \( \vec{F}(x, y) = \langle y, -x \rangle \)
- This produces a **rotational field**, circling around the origin

#### 2. **Curve**
- Blue circle: \( C \), the path we are integrating along
- Red arrows: the vector field values **on the curve**

#### 3. **Dot Product \( \vec{F} \cdot d\vec{r} \)**
- We compute how much the field vectors **align with the direction of motion**
- This tells us how much “work” the field does along the path

#### 4. **Numerical Integration**
- We approximated the integral using the trapezoidal rule:
\[
\int_C \vec{F} \cdot d\vec{r} = \boxed{-2\pi}
\]

This negative value indicates the field **opposes** the direction of motion along the circle.

---

### 🔍 Geometric Insight:
- The field \( \vec{F} = \langle y, -x \rangle \) rotates **clockwise**
- But the unit circle is parameterized **counterclockwise**
- The negative result confirms **opposition to the motion direction**

---

### ✅ Comparison with a **Conservative Field**

We repeated the same line integral over the **unit circle**, but this time with a **conservative vector field**:

\[
\vec{F}(x, y) = \nabla f = \langle 2x, 2y \rangle, \quad \text{where } f(x, y) = x^2 + y^2
\]

---

### 🧮 Result of the Line Integral:
\[
\int_C \vec{F} \cdot d\vec{r} = \boxed{0}
\]

---

### 🧠 Why This Happens:

- In a conservative field, **line integrals over closed loops are always zero**.
- That’s because the net "work" done by a **gradient field** around a loop **cancels out**.

---

### 🧭 Geometric Insight:

- Red vectors point **radially outward**—they’re gradients of the function \( x^2 + y^2 \).
- As you travel around the circle, you’re always moving **perpendicular** to the field.
- So the field does **no work**: zero alignment with path direction ⇒ zero dot product overall.

---

## 🔁 Now Let's Do the Surface Integral of Curl(F) (Stokes’ Theorem)

To confirm:
\[
\oint_C \vec{F} \cdot d\vec{r} = \iint_S (\nabla \times \vec{F}) \cdot \hat{n}\, dS
\]

We’ll compute the surface integral of the **curl of the original (rotational)** field over the **disk** bounded by the unit circle.

### 🔄 **Stokes’ Theorem Verification**

We evaluated the **surface integral** of the **curl** of the original field  
\[
\vec{F}(x, y) = \langle y, -x \rangle
\]  
over the **unit disk**, which is bounded by the unit circle.

---

### 📐 Surface Integral of the Curl:
\[
\iint_S (\nabla \times \vec{F}) \cdot \hat{n}\, dS = \boxed{-2\pi \approx -6.28}
\]

---

### 🔄 Stokes' Theorem Statement:
\[
\oint_C \vec{F} \cdot d\vec{r} = \iint_S (\nabla \times \vec{F}) \cdot d\vec{S}
\]

And indeed, we previously computed the **line integral** to be:
\[
\oint_C \vec{F} \cdot d\vec{r} = \boxed{-2\pi}
\]

✅ **They match perfectly!**

---

### 🧠 Physical Interpretation:
- The curl \( \nabla \times \vec{F} = -2 \) is **constant** in the region.
- The **net rotation** across the surface accumulates to \( -2\pi \), which equals the **total circulation** around the boundary.

---

### Visual Notes:
- The shaded blue region is the **unit disk surface** \( S \).
- The blue curve is the **boundary** \( \partial S \), our original integration path.

---
Line Integral In Conservative Field $\Vec{F}(X, Y) = \Langle 2x, 2y \Rangle$
![output (7)](https://github.com/user-attachments/assets/9b2ba092-75b5-4ad3-aad9-dfc59d0a43d1)


### ✅ Comparison with a **Conservative Field**

We repeated the same line integral over the **unit circle**, but this time with a **conservative vector field**:

\[
\vec{F}(x, y) = \nabla f = \langle 2x, 2y \rangle, \quad \text{where } f(x, y) = x^2 + y^2
\]

---

### 🧮 Result of the Line Integral:
\[
\int_C \vec{F} \cdot d\vec{r} = \boxed{0}
\]

---

### 🧠 Why This Happens:

- In a conservative field, **line integrals over closed loops are always zero**.
- That’s because the net "work" done by a **gradient field** around a loop **cancels out**.

---

### 🧭 Geometric Insight:

- Red vectors point **radially outward**—they’re gradients of the function \( x^2 + y^2 \).
- As you travel around the circle, you’re always moving **perpendicular** to the field.
- So the field does **no work**: zero alignment with path direction ⇒ zero dot product overall.

---

## 🔁 Now Let's Do the Surface Integral of Curl(F) (Stokes’ Theorem)
Surface (Unit Disk) For Stokes' Theorem
![output (7)](https://github.com/user-attachments/assets/b44b6f6d-afa8-4e19-b84a-179139db54d9)

To confirm:
\[
\oint_C \vec{F} \cdot d\vec{r} = \iint_S (\nabla \times \vec{F}) \cdot \hat{n}\, dS
\]

We’ll compute the surface integral of the **curl of the original (rotational)** field over the **disk** bounded by the unit circle.

### 🔄 **Stokes’ Theorem Verification**

We evaluated the **surface integral** of the **curl** of the original field  
\[
\vec{F}(x, y) = \langle y, -x \rangle
\]  
over the **unit disk**, which is bounded by the unit circle.

---

### 📐 Surface Integral of the Curl:
\[
\iint_S (\nabla \times \vec{F}) \cdot \hat{n}\, dS = \boxed{-2\pi \approx -6.28}
\]

---

### 🔄 Stokes' Theorem Statement:
\[
\oint_C \vec{F} \cdot d\vec{r} = \iint_S (\nabla \times \vec{F}) \cdot d\vec{S}
\]

And indeed, we previously computed the **line integral** to be:
\[
\oint_C \vec{F} \cdot d\vec{r} = \boxed{-2\pi}
\]

✅ **They match perfectly!**

---

### 🧠 Physical Interpretation:
- The curl \( \nabla \times \vec{F} = -2 \) is **constant** in the region.
- The **net rotation** across the surface accumulates to \( -2\pi \), which equals the **total circulation** around the boundary.

---

### Visual Notes:
- The shaded blue region is the **unit disk surface** \( S \).
- The blue curve is the **boundary** \( \partial S \), our original integration path.

---

Would you like to:
- Explore **divergence and the Divergence Theorem** next?
- Try a **non-constant curl** or a **3D surface integral**?
- Animate Stokes' Theorem with field vectors rotating dynamically?

- Absolutely! Here's a structured list of the **most important vector forces** encountered in **physics and engineering**, grouped by category and complete with formulas and vector characteristics.

---

## 🧲 **I. Mechanical Forces**

### 🔹 1. **Gravitational Force**
- **Formula:**  
  \[
  \vec{F}_g = m\vec{g}
  \]
  or (between two masses):  
  \[
  \vec{F}_g = -G\frac{m_1 m_2}{r^2} \hat{r}
  \]
- **Direction:** Toward mass center (Earth or other body)
- **Field Type:** Conservative

---

### 🔹 2. **Normal Force**
- Force exerted **perpendicular** to a surface
- Reacts to contact forces preventing penetration

---

### 🔹 3. **Frictional Force**
- **Static:** Prevents motion
- **Kinetic:** Resists motion
- **Formula:**  
  \[
  \vec{F}_f = -\mu \vec{N}
  \]
- **Direction:** Opposite to motion (or intended motion)

---

### 🔹 4. **Tension Force**
- Transmitted through ropes, strings, etc.
- Pulls equally at both ends
- Aligned along the length of the cable

---

### 🔹 5. **Spring Force (Hooke’s Law)**
- **Formula:**  
  \[
  \vec{F}_s = -k\vec{x}
  \]
- **Direction:** Opposes displacement
- **Field Type:** Conservative

---

## ⚡ **II. Electromagnetic Forces**

### 🔹 6. **Electric Force**
- **Formula:**  
  \[
  \vec{F}_e = q\vec{E}
  \]
- **From a point charge:**  
  \[
  \vec{F} = k_e \frac{q_1 q_2}{r^2} \hat{r}
  \]

---

### 🔹 7. **Magnetic Force on a Moving Charge**
- **Lorentz Force:**  
  \[
  \vec{F}_B = q\vec{v} \times \vec{B}
  \]
- **Direction:** Perpendicular to both \( \vec{v} \) and \( \vec{B} \) (Right-hand rule)
- **Field Type:** Non-conservative

---

### 🔹 8. **Lorentz Total Force**
\[
\vec{F} = q(\vec{E} + \vec{v} \times \vec{B})
\]

---

## 🌍 **III. Rotational and Inertial Forces**

### 🔹 9. **Centripetal Force**
- **Formula:**  
  \[
  \vec{F}_c = -m\frac{v^2}{r} \hat{r}
  \]
- **Direction:** Toward center of rotation

---

### 🔹 10. **Coriolis Force**
- **Formula:**  
  \[
  \vec{F}_{\text{Cor}} = -2m(\vec{\omega} \times \vec{v})
  \]
- Arises in rotating frames (like Earth)
- Important in meteorology and oceanography

---

### 🔹 11. **Centrifugal Force (Fictitious)**
- **Formula:**  
  \[
  \vec{F}_{\text{Cent}} = m\vec{\omega} \times (\vec{\omega} \times \vec{r})
  \]
- Appears in rotating reference frames
- Points outward from rotation axis

---

## 🔧 **IV. Engineering Forces and Interactions**

### 🔹 12. **Drag Force (Air or Fluid Resistance)**
- **Formula:**  
  \[
  \vec{F}_d = -\frac{1}{2} C_d \rho A v^2 \hat{v}
  \]
- **Direction:** Opposes motion through fluid
- Depends on shape, speed, fluid density

---

### 🔹 13. **Buoyant Force**
- **Formula:**  
  \[
  \vec{F}_b = \rho_{\text{fluid}} V g \hat{z}
  \]
- **Direction:** Upward (opposite gravity)
- Related to displaced volume (Archimedes’ principle)

---

### 🔹 14. **Thrust Force**
- Found in propulsion systems (rockets, jets)
- **Direction:** Opposite expelled mass

---

### 🔹 15. **Electromagnetic Force on a Wire**
- **Formula:**  
  \[
  \vec{F} = I\vec{L} \times \vec{B}
  \]
- Common in motors and generators

---

### 🔹 16. **Shear Force (in beams)**
- Acts **tangentially** to the cross-section of a structure
- Internal force resisting sliding deformation

---

### 🔹 17. **Surface Tension Force**
- Acts along the surface of a liquid
- Important in fluid mechanics and micro-scale systems

---

## 📚 Summary Table

| Force Type        | Vector? | Conservative? | Direction Rule |
|------------------|---------|---------------|----------------|
| Gravitational     | ✅      | ✅             | Toward mass    |
| Electric          | ✅      | ✅             | Field lines    |
| Magnetic          | ✅      | ❌             | Right-hand rule |
| Tension           | ✅      | ✅ (ideal)     | Along cable     |
| Drag              | ✅      | ❌             | Opposes velocity |
| Spring            | ✅      | ✅             | Opposes displacement |
| Centripetal       | ✅      | ❌             | Inward          |
| Coriolis          | ✅      | ❌             | Right-hand rule |
| Buoyant           | ✅      | ✅             | Upward          |

---

Would you like:
- Visual diagrams of these vector forces?
- Derivations of any of the formulas above?
- A LaTeX handout or printable PDF version?

We can also apply these forces in **systems modeling** or **differential equations** for real-world simulations.
