### **Review of Trigonometry Notation in LaTeX**

LaTeX provides powerful tools for writing **trigonometric notation**, including symbols for angles, trigonometric functions, identities, and equations. Below is a detailed review with proper formatting.

---

### **1. Trigonometric Functions**
The six primary trigonometric functions are written using `\sin`, `\cos`, `\tan`, `\csc`, `\sec`, and `\cot`:

```latex
$$\sin x, \quad \cos x, \quad \tan x, \quad \csc x, \quad \sec x, \quad \cot x$$
```
**Rendered as:**
$$\sin x, \quad \cos x, \quad \tan x, \quad \csc x, \quad \sec x, \quad \cot x$$

For inverse trigonometric functions:
```latex
$$\sin^{-1} x, \quad \cos^{-1} x, \quad \tan^{-1} x$$
```
**Rendered as:**
$$\sin^{-1} x, \quad \cos^{-1} x, \quad \tan^{-1} x$$

---

### **2. Right Triangle Trigonometry**
For a right triangle with hypotenuse \( c \), opposite side \( a \), and adjacent side \( b \):

#### **Sine, Cosine, and Tangent Ratios**
```latex
$$\sin \theta = \frac{\text{opposite}}{\text{hypotenuse}} = \frac{a}{c}$$
$$\cos \theta = \frac{\text{adjacent}}{\text{hypotenuse}} = \frac{b}{c}$$
$$\tan \theta = \frac{\text{opposite}}{\text{adjacent}} = \frac{a}{b}$$
```
**Rendered as:**
$$\sin \theta = \frac{\text{opposite}}{\text{hypotenuse}} = \frac{a}{c}$$
$$\cos \theta = \frac{\text{adjacent}}{\text{hypotenuse}} = \frac{b}{c}$$
$$\tan \theta = \frac{\text{opposite}}{\text{adjacent}} = \frac{a}{b}$$

#### **Cosecant, Secant, and Cotangent**
```latex
$$\csc \theta = \frac{1}{\sin \theta} = \frac{c}{a}$$
$$\sec \theta = \frac{1}{\cos \theta} = \frac{c}{b}$$
$$\cot \theta = \frac{1}{\tan \theta} = \frac{b}{a}$$
```
**Rendered as:**
$$\csc \theta = \frac{1}{\sin \theta} = \frac{c}{a}$$
$$\sec \theta = \frac{1}{\cos \theta} = \frac{c}{b}$$
$$\cot \theta = \frac{1}{\tan \theta} = \frac{b}{a}$$

---

### **3. Pythagorean Theorem and Identities**
#### **Pythagorean Theorem**
```latex
$$a^2 + b^2 = c^2$$
```
**Rendered as:**
$$a^2 + b^2 = c^2$$

#### **Pythagorean Identities**
```latex
$$\sin^2 \theta + \cos^2 \theta = 1$$
$$1 + \tan^2 \theta = \sec^2 \theta$$
$$1 + \cot^2 \theta = \csc^2 \theta$$
```
**Rendered as:**
$$\sin^2 \theta + \cos^2 \theta = 1$$
$$1 + \tan^2 \theta = \sec^2 \theta$$
$$1 + \cot^2 \theta = \csc^2 \theta$$

---

### **4. Unit Circle Definitions**
The unit circle is a key concept in trigonometry:

```latex
$$(\cos \theta, \sin \theta)$$
```
**Rendered as:**
$$(\cos \theta, \sin \theta)$$

For common angles:

```latex
$$\sin 0^\circ = 0, \quad \sin 30^\circ = \frac{1}{2}, \quad \sin 45^\circ = \frac{\sqrt{2}}{2}, \quad \sin 60^\circ = \frac{\sqrt{3}}{2}, \quad \sin 90^\circ = 1$$
```
**Rendered as:**
$$\sin 0^\circ = 0, \quad \sin 30^\circ = \frac{1}{2}, \quad \sin 45^\circ = \frac{\sqrt{2}}{2}, \quad \sin 60^\circ = \frac{\sqrt{3}}{2}, \quad \sin 90^\circ = 1$$

Similarly, for cosine:
```latex
$$\cos 0^\circ = 1, \quad \cos 30^\circ = \frac{\sqrt{3}}{2}, \quad \cos 45^\circ = \frac{\sqrt{2}}{2}, \quad \cos 60^\circ = \frac{1}{2}, \quad \cos 90^\circ = 0$$
```
**Rendered as:**
$$\cos 0^\circ = 1, \quad \cos 30^\circ = \frac{\sqrt{3}}{2}, \quad \cos 45^\circ = \frac{\sqrt{2}}{2}, \quad \cos 60^\circ = \frac{1}{2}, \quad \cos 90^\circ = 0$$

---

### **5. Sum and Difference Formulas**
#### **Sine and Cosine Sum and Difference**
```latex
$$\sin (A \pm B) = \sin A \cos B \pm \cos A \sin B$$
$$\cos (A \pm B) = \cos A \cos B \mp \sin A \sin B$$
```
**Rendered as:**
$$\sin (A \pm B) = \sin A \cos B \pm \cos A \sin B$$
$$\cos (A \pm B) = \cos A \cos B \mp \sin A \sin B$$

#### **Tangent Sum and Difference**
```latex
$$\tan (A \pm B) = \frac{\tan A \pm \tan B}{1 \mp \tan A \tan B}$$
```
**Rendered as:**
$$\tan (A \pm B) = \frac{\tan A \pm \tan B}{1 \mp \tan A \tan B}$$

---

### **6. Double Angle and Half Angle Formulas**
#### **Double Angle Formulas**
```latex
$$\sin 2A = 2 \sin A \cos A$$
$$\cos 2A = \cos^2 A - \sin^2 A = 2\cos^2 A - 1 = 1 - 2\sin^2 A$$
$$\tan 2A = \frac{2\tan A}{1 - \tan^2 A}$$
```
**Rendered as:**
$$\sin 2A = 2 \sin A \cos A$$
$$\cos 2A = \cos^2 A - \sin^2 A = 2\cos^2 A - 1 = 1 - 2\sin^2 A$$
$$\tan 2A = \frac{2\tan A}{1 - \tan^2 A}$$

#### **Half Angle Formulas**
```latex
$$\sin \frac{A}{2} = \pm \sqrt{\frac{1 - \cos A}{2}}$$
$$\cos \frac{A}{2} = \pm \sqrt{\frac{1 + \cos A}{2}}$$
$$\tan \frac{A}{2} = \pm \sqrt{\frac{1 - \cos A}{1 + \cos A}} = \frac{\sin A}{1 + \cos A}$$
```
**Rendered as:**
$$\sin \frac{A}{2} = \pm \sqrt{\frac{1 - \cos A}{2}}$$
$$\cos \frac{A}{2} = \pm \sqrt{\frac{1 + \cos A}{2}}$$
$$\tan \frac{A}{2} = \pm \sqrt{\frac{1 - \cos A}{1 + \cos A}} = \frac{\sin A}{1 + \cos A}$$

---

### **Conclusion**
This review covers the essential **trigonometry notation** in LaTeX, making it easier to write trigonometric expressions, identities, and equations. Let me know if you need any **modifications or additional formulas**! 🚀
