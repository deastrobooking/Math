### **Comprehensive Review of Trigonometry Notation in LaTeX (High School & College Level)**  

This guide covers **basic, intermediate, and advanced** trigonometric concepts using LaTeX, formatted for readability.  

---

## **1. Trigonometric Functions**  

The six primary trigonometric functions:  

```latex
$$\sin x, \quad \cos x, \quad \tan x, \quad \csc x, \quad \sec x, \quad \cot x$$
```
**Rendered as:**  
$$\sin x, \quad \cos x, \quad \tan x, \quad \csc x, \quad \sec x, \quad \cot x$$  

Inverse functions:  

```latex
$$\sin^{-1} x, \quad \cos^{-1} x, \quad \tan^{-1} x$$
```
**Rendered as:**  
$$\sin^{-1} x, \quad \cos^{-1} x, \quad \tan^{-1} x$$  

---

## **2. Right Triangle Trigonometry**  

For a right triangle with hypotenuse \( c \), opposite side \( a \), and adjacent side \( b \):  

```latex
$$\sin \theta = \frac{a}{c}, \quad \cos \theta = \frac{b}{c}, \quad \tan \theta = \frac{a}{b}$$
$$\csc \theta = \frac{c}{a}, \quad \sec \theta = \frac{c}{b}, \quad \cot \theta = \frac{b}{a}$$
```
**Rendered as:**  
$$\sin \theta = \frac{a}{c}, \quad \cos \theta = \frac{b}{c}, \quad \tan \theta = \frac{a}{b}$$  
$$\csc \theta = \frac{c}{a}, \quad \sec \theta = \frac{c}{b}, \quad \cot \theta = \frac{b}{a}$$  

---

## **3. Pythagorean Identities**  

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

## **4. Unit Circle & Special Angles**  

For a unit circle:  

```latex
$$(\cos \theta, \sin \theta)$$
```
**Rendered as:**  
$$(\cos \theta, \sin \theta)$$  

Common values:  

```latex
$$\sin 0^\circ = 0, \quad \sin 30^\circ = \frac{1}{2}, \quad \sin 45^\circ = \frac{\sqrt{2}}{2}, \quad \sin 60^\circ = \frac{\sqrt{3}}{2}, \quad \sin 90^\circ = 1$$
```
**Rendered as:**  
$$\sin 0^\circ = 0, \quad \sin 30^\circ = \frac{1}{2}, \quad \sin 45^\circ = \frac{\sqrt{2}}{2}, \quad \sin 60^\circ = \frac{\sqrt{3}}{2}, \quad \sin 90^\circ = 1$$  

---

## **5. Sum and Difference Formulas**  

```latex
$$\sin (A \pm B) = \sin A \cos B \pm \cos A \sin B$$
$$\cos (A \pm B) = \cos A \cos B \mp \sin A \sin B$$
$$\tan (A \pm B) = \frac{\tan A \pm \tan B}{1 \mp \tan A \tan B}$$
```
**Rendered as:**  
$$\sin (A \pm B) = \sin A \cos B \pm \cos A \sin B$$  
$$\cos (A \pm B) = \cos A \cos B \mp \sin A \sin B$$  
$$\tan (A \pm B) = \frac{\tan A \pm \tan B}{1 \mp \tan A \tan B}$$  

---

## **6. Double and Half Angle Formulas**  

```latex
$$\sin 2A = 2 \sin A \cos A$$
$$\cos 2A = \cos^2 A - \sin^2 A = 2\cos^2 A - 1 = 1 - 2\sin^2 A$$
$$\tan 2A = \frac{2\tan A}{1 - \tan^2 A}$$
```
**Rendered as:**  
$$\sin 2A = 2 \sin A \cos A$$  
$$\cos 2A = \cos^2 A - \sin^2 A = 2\cos^2 A - 1 = 1 - 2\sin^2 A$$  
$$\tan 2A = \frac{2\tan A}{1 - \tan^2 A}$$  

---

## **7. Law of Sines and Cosines**  

```latex
$$\frac{a}{\sin A} = \frac{b}{\sin B} = \frac{c}{\sin C}$$
$$c^2 = a^2 + b^2 - 2ab \cos C$$
```
**Rendered as:**  
$$\frac{a}{\sin A} = \frac{b}{\sin B} = \frac{c}{\sin C}$$  
$$c^2 = a^2 + b^2 - 2ab \cos C$$  

---

## **8. Polar and Parametric Equations**  

### **Polar Form**
```latex
$$r = a + b \cos \theta$$
$$r = a + b \sin \theta$$
```
**Rendered as:**  
$$r = a + b \cos \theta$$  
$$r = a + b \sin \theta$$  

### **Conversion Between Forms**
```latex
$$x = r\cos \theta, \quad y = r\sin \theta$$
$$r^2 = x^2 + y^2, \quad \theta = \tan^{-1} \left(\frac{y}{x}\right)$$
```
**Rendered as:**  
$$x = r\cos \theta, \quad y = r\sin \theta$$  
$$r^2 = x^2 + y^2, \quad \theta = \tan^{-1} \left(\frac{y}{x}\right)$$  

---

## **9. Fourier Series (Advanced Trigonometry)**  

```latex
$$f(x) = \frac{a_0}{2} + \sum_{n=1}^{\infty} \left( a_n \cos \frac{n\pi x}{L} + b_n \sin \frac{n\pi x}{L} \right)$$
```
**Rendered as:**  
$$f(x) = \frac{a_0}{2} + \sum_{n=1}^{\infty} \left( a_n \cos \frac{n\pi x}{L} + b_n \sin \frac{n\pi x}{L} \right)$$  

---

 🚀

 ### **Breaking Down Every Symbol in Fourier Analysis**

Fourier analysis uses a variety of symbols to represent periodic functions, transformations, and their frequency components. Below is a complete breakdown of the most common symbols used in **Fourier series, Fourier transforms, and frequency domain analysis**.

---

## **1. Fourier Series Representation**
A periodic function \( f(x) \) can be represented as an **infinite sum of sines and cosines**:

### **Fourier Series Formula**
```latex
$$f(x) = \frac{a_0}{2} + \sum_{n=1}^{\infty} \left( a_n \cos \frac{n\pi x}{L} + b_n \sin \frac{n\pi x}{L} \right)$$
```
**Rendered as:**  
$$f(x) = \frac{a_0}{2} + \sum_{n=1}^{\infty} \left( a_n \cos \frac{n\pi x}{L} + b_n \sin \frac{n\pi x}{L} \right)$$  

### **Symbol Breakdown**
| Symbol | Meaning |
|--------|---------|
| \( f(x) \) | Original periodic function |
| \( a_0 \) | DC (average) component of the function |
| \( a_n \) | Coefficients for cosine terms (even harmonics) |
| \( b_n \) | Coefficients for sine terms (odd harmonics) |
| \( n \) | Integer index representing harmonics (frequency multiples) |
| \( \pi \) | Mathematical constant (3.14159...) |
| \( L \) | Half-period of the function (i.e., function repeats every \( 2L \)) |
| \( \sum \) | Summation notation, meaning we sum over all harmonics |

#### **Fourier Coefficients Formulas**
To compute \( a_0 \), \( a_n \), and \( b_n \):

```latex
$$a_0 = \frac{1}{L} \int_{-L}^{L} f(x) \, dx$$
$$a_n = \frac{1}{L} \int_{-L}^{L} f(x) \cos \frac{n\pi x}{L} \, dx$$
$$b_n = \frac{1}{L} \int_{-L}^{L} f(x) \sin \frac{n\pi x}{L} \, dx$$
```
**Symbol Breakdown:**
| Symbol | Meaning |
|--------|---------|
| \( \int \) | Integral (continuous summation) |
| \( dx \) | Differential element (infinitesimally small change in \( x \)) |

---

## **2. Fourier Transform (Continuous Time)**
While the Fourier series represents periodic functions, the **Fourier Transform (FT)** applies to general functions (even non-periodic ones).

### **Fourier Transform Formula**
```latex
$$F(\omega) = \int_{-\infty}^{\infty} f(t) e^{-i \omega t} dt$$
```
**Rendered as:**  
$$F(\omega) = \int_{-\infty}^{\infty} f(t) e^{-i \omega t} dt$$

### **Inverse Fourier Transform**
```latex
$$f(t) = \frac{1}{2\pi} \int_{-\infty}^{\infty} F(\omega) e^{i \omega t} d\omega$$
```
**Rendered as:**  
$$f(t) = \frac{1}{2\pi} \int_{-\infty}^{\infty} F(\omega) e^{i \omega t} d\omega$$

### **Symbol Breakdown**
| Symbol | Meaning |
|--------|---------|
| \( F(\omega) \) | Fourier Transform of \( f(t) \) |
| \( f(t) \) | Original time-domain function |
| \( \omega \) | Angular frequency (\( 2\pi f \)) |
| \( e^{-i\omega t} \) | Complex exponential function representing sinusoids |
| \( i \) | Imaginary unit (\( i^2 = -1 \)) |
| \( \int_{-\infty}^{\infty} \) | Integral over all time or frequency |
| \( d\omega \), \( dt \) | Infinitesimally small changes in frequency and time |
| \( \frac{1}{2\pi} \) | Normalization factor ensuring correct scaling |

---

## **3. Discrete Fourier Transform (DFT)**
For digital signals, we use the **Discrete Fourier Transform (DFT)**:

### **DFT Formula**
```latex
$$X_k = \sum_{n=0}^{N-1} x_n e^{-i 2\pi k n / N}$$
```
**Rendered as:**  
$$X_k = \sum_{n=0}^{N-1} x_n e^{-i 2\pi k n / N}$$

### **Inverse DFT (IDFT)**
```latex
$$x_n = \frac{1}{N} \sum_{k=0}^{N-1} X_k e^{i 2\pi k n / N}$$
```
**Rendered as:**  
$$x_n = \frac{1}{N} \sum_{k=0}^{N-1} X_k e^{i 2\pi k n / N}$$

### **Symbol Breakdown**
| Symbol | Meaning |
|--------|---------|
| \( X_k \) | DFT of sequence \( x_n \) (frequency domain representation) |
| \( x_n \) | Original discrete signal in the time domain |
| \( k \) | Frequency bin index (integer) |
| \( N \) | Total number of samples |
| \( e^{-i 2\pi kn / N} \) | Complex exponential function (basis function) |
| \( \sum \) | Summation over all samples |

---

## **4. Fast Fourier Transform (FFT)**
- The **FFT** is a computationally efficient algorithm to compute the **DFT**.
- It uses the **divide-and-conquer strategy** to reduce complexity from \( O(N^2) \) to \( O(N \log N) \).

---

## **5. Frequency Domain Concepts**
| Symbol | Meaning |
|--------|---------|
| \( f \) | Frequency (in Hz) |
| \( \omega = 2\pi f \) | Angular frequency (radians per second) |
| \( T \) | Time period of a signal |
| \( \lambda \) | Wavelength of a wave |
| \( \mathbb{C} \) | Set of complex numbers |
| \( \delta (t) \) | Dirac delta function (impulse) |
| \( \Pi(t) \) | Rectangular function |
| \( \text{sinc}(x) = \frac{\sin(\pi x)}{\pi x} \) | Sinc function, important in signal processing |

---

🚀
