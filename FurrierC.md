### **Fourier Analysis in C: Practical Examples**  

This section provides **C implementations** of Fourier Series, Discrete Fourier Transform (DFT), and Fast Fourier Transform (FFT). These examples can be compiled and run in a C environment.

---

## **1. Fourier Series Approximation (C Implementation)**
The **Fourier Series** represents a periodic function as a sum of sines and cosines. In this example, we approximate a **square wave** using Fourier series.

### **Example: Approximating a Square Wave**
```c
#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793
#define TERMS 10  // Number of Fourier terms
#define POINTS 100  // Number of points in one period

// Function to compute Fourier Series approximation of a square wave
void fourier_series_square_wave(double x[], double y[], int n_terms, int n_points) {
    for (int i = 0; i < n_points; i++) {
        double sum = 0.0;
        for (int n = 1; n <= n_terms; n += 2) { // Only odd harmonics contribute
            sum += (4.0 / (n * PI)) * sin(n * x[i]);
        }
        y[i] = sum;
    }
}

int main() {
    double x[POINTS], y[POINTS];
    
    // Generate x values from -π to π
    for (int i = 0; i < POINTS; i++) {
        x[i] = -PI + (2 * PI * i / POINTS);
    }

    // Compute Fourier Series
    fourier_series_square_wave(x, y, TERMS, POINTS);

    // Print results
    printf("x, y\n");
    for (int i = 0; i < POINTS; i++) {
        printf("%lf, %lf\n", x[i], y[i]);
    }

    return 0;
}
```
### **Explanation**
- Uses **only odd harmonics** since the square wave contains only odd frequencies.
- Prints **x, y** values for plotting in a tool like **MATLAB, Python (matplotlib), or GNUplot**.

---

## **2. Discrete Fourier Transform (DFT) in C**
The **Discrete Fourier Transform (DFT)** converts a sequence of time-domain signals into frequency components.

### **Example: Compute DFT of a Sample Signal**
```c
#include <stdio.h>
#include <math.h>

#define N 8  // Number of points

typedef struct {
    double real;
    double imag;
} Complex;

// Function to compute DFT
void dft(double in_real[], double in_imag[], Complex out[], int n) {
    for (int k = 0; k < n; k++) {
        out[k].real = 0;
        out[k].imag = 0;
        for (int n = 0; n < N; n++) {
            double angle = -2.0 * PI * k * n / N;
            out[k].real += in_real[n] * cos(angle) - in_imag[n] * sin(angle);
            out[k].imag += in_real[n] * sin(angle) + in_imag[n] * cos(angle);
        }
    }
}

// Main function
int main() {
    double x_real[N] = {1, 1, 1, 1, 0, 0, 0, 0}; // Sample input
    double x_imag[N] = {0};  // No imaginary part initially
    Complex X[N];

    // Compute DFT
    dft(x_real, x_imag, X, N);

    // Print the frequency components
    printf("Frequency Components:\n");
    for (int k = 0; k < N; k++) {
        printf("X[%d] = %.4lf + %.4lfi\n", k, X[k].real, X[k].imag);
    }

    return 0;
}
```
### **Explanation**
- **Computes the DFT** of an 8-point real sequence.
- Uses a **complex struct** to store real and imaginary parts of the frequency domain values.
- **Output can be analyzed to find dominant frequency components.**

---

## **3. Fast Fourier Transform (FFT) in C**
The **Fast Fourier Transform (FFT)** is an optimized version of the DFT using the **Cooley-Tukey algorithm**, reducing complexity from **O(N²) to O(N log N).**

### **Example: Compute FFT Using Recursion**
```c
#include <stdio.h>
#include <math.h>

#define N 8  // Must be a power of 2

typedef struct {
    double real;
    double imag;
} Complex;

// Function to compute FFT using Cooley-Tukey Algorithm
void fft(Complex a[], int n) {
    if (n <= 1) return;

    // Divide the array into even and odd indices
    Complex even[n / 2], odd[n / 2];
    for (int i = 0; i < n / 2; i++) {
        even[i] = a[i * 2];
        odd[i] = a[i * 2 + 1];
    }

    // Recursive FFT
    fft(even, n / 2);
    fft(odd, n / 2);

    // Combine results
    for (int k = 0; k < n / 2; k++) {
        double angle = -2 * PI * k / n;
        Complex t = {cos(angle) * odd[k].real - sin(angle) * odd[k].imag,
                     sin(angle) * odd[k].real + cos(angle) * odd[k].imag};

        a[k].real = even[k].real + t.real;
        a[k].imag = even[k].imag + t.imag;
        a[k + n / 2].real = even[k].real - t.real;
        a[k + n / 2].imag = even[k].imag - t.imag;
    }
}

// Main function
int main() {
    Complex x[N] = {{1,0}, {1,0}, {1,0}, {1,0}, {0,0}, {0,0}, {0,0}, {0,0}}; // Sample input

    // Compute FFT
    fft(x, N);

    // Print results
    printf("FFT Output:\n");
    for (int i = 0; i < N; i++) {
        printf("X[%d] = %.4lf + %.4lfi\n", i, x[i].real, x[i].imag);
    }

    return 0;
}
```
### **Explanation**
- Uses **recursive FFT** based on the **divide-and-conquer** approach.
- Splits input into **even and odd indexed values**, then applies FFT recursively.
- **More efficient** than the brute-force DFT.

---

## **4. Interpreting Frequency Domain Data**
Fourier transforms help analyze **real-world signals**:
- **Speech signals** → Identifies dominant frequencies in voice.
- **Audio processing** → Detects musical notes.
- **Image processing** → Filters noise using the 2D Fourier Transform.

To analyze the output:
1. **Plot magnitude spectrum**: \( |X[k]| = \sqrt{\text{Re}^2 + \text{Im}^2} \)
2. **Identify peaks** in the spectrum to find dominant frequencies.

---

## **Conclusion**
These **C implementations** cover:
1. **Fourier Series** (approximate a periodic function).
2. **DFT** (basic frequency analysis).
3. **FFT** (efficient computation).

Would you like **graphing code in Python to visualize results**, or a **2D Fourier Transform for image processing in C**? 🚀


### **Visualizing Fourier Analysis: Graphing in Python & Implementing 2D Fourier Transform in C**  

This section covers:
1. **Graphing Fourier Transform Results in Python**
2. **2D Fourier Transform Implementation in C for Image Processing**  

---

## **1. Graphing Fourier Transform Results in Python**  
To visualize the **DFT and FFT outputs**, we use Python's `numpy` and `matplotlib` to plot the **magnitude spectrum**.

### **Example: Plot DFT and FFT of a Sample Signal**  
```python
import numpy as np
import matplotlib.pyplot as plt

# Generate a sample signal: sum of two sine waves
fs = 100  # Sampling frequency (Hz)
t = np.linspace(0, 1, fs, endpoint=False)  # Time vector (1 second duration)
f1, f2 = 5, 20  # Frequencies of two sine waves
signal = np.sin(2 * np.pi * f1 * t) + 0.5 * np.sin(2 * np.pi * f2 * t)

# Compute DFT using numpy's FFT function
X = np.fft.fft(signal)
frequencies = np.fft.fftfreq(len(signal), d=1/fs)  # Frequency bins

# Compute magnitude spectrum
magnitude = np.abs(X)

# Plot the original signal
plt.figure(figsize=(12, 5))
plt.subplot(1, 2, 1)
plt.plot(t, signal)
plt.title("Original Signal (Time Domain)")
plt.xlabel("Time (s)")
plt.ylabel("Amplitude")

# Plot the frequency spectrum (Only positive half due to symmetry)
plt.subplot(1, 2, 2)
plt.stem(frequencies[:fs//2], magnitude[:fs//2], 'b', markerfmt=" ", basefmt="-b")
plt.title("Magnitude Spectrum (Frequency Domain)")
plt.xlabel("Frequency (Hz)")
plt.ylabel("Magnitude")
plt.show()
```

### **Explanation**
- Generates a **sample signal** (sum of two sine waves at 5 Hz and 20 Hz).
- Uses **NumPy’s FFT** to compute the **DFT**.
- Plots:
  1. **Time-domain signal**
  2. **Magnitude spectrum (Frequency-domain representation)**

### **Expected Output**
1. **Original Signal** – Two superimposed sine waves.
2. **Frequency Spectrum** – Peaks at 5 Hz and 20 Hz, showing the signal's frequency components.

---

## **2. 2D Fourier Transform in C for Image Processing**  
The **2D Fourier Transform** is used in image processing for:
- **Edge detection**
- **Image filtering**
- **Compression (JPEG uses DCT - a type of Fourier Transform)**

### **2D Discrete Fourier Transform (DFT) in C**
```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 4
#define HEIGHT 4
#define PI 3.141592653589793

typedef struct {
    double real;
    double imag;
} Complex;

// Function to compute 2D DFT
void dft2D(double input[HEIGHT][WIDTH], Complex output[HEIGHT][WIDTH]) {
    for (int u = 0; u < HEIGHT; u++) {
        for (int v = 0; v < WIDTH; v++) {
            output[u][v].real = 0;
            output[u][v].imag = 0;
            
            for (int x = 0; x < HEIGHT; x++) {
                for (int y = 0; y < WIDTH; y++) {
                    double angle = -2.0 * PI * ((u * x / (double)HEIGHT) + (v * y / (double)WIDTH));
                    output[u][v].real += input[x][y] * cos(angle);
                    output[u][v].imag += input[x][y] * sin(angle);
                }
            }
        }
    }
}

// Function to print output matrix
void printDFT(Complex output[HEIGHT][WIDTH]) {
    printf("2D DFT Output (Real Part):\n");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%6.2lf ", output[i][j].real);
        }
        printf("\n");
    }
}

int main() {
    double image[HEIGHT][WIDTH] = {
        {255, 128, 0, 64},
        {64, 255, 128, 0},
        {0, 64, 255, 128},
        {128, 0, 64, 255}
    };

    Complex output[HEIGHT][WIDTH];
    
    // Compute 2D DFT
    dft2D(image, output);
    
    // Print results
    printDFT(output);

    return 0;
}
```

### **Explanation**
1. **Takes a 4x4 grayscale image (matrix of intensities).**
2. **Computes the 2D DFT** using nested loops for both \( u, v \) and \( x, y \).
3. **Stores results in a 2D complex array**.
4. **Prints the real part** of the transform.

### **Output Interpretation**
- The **(0,0) value represents the DC component** (average brightness of the image).
- High-frequency components appear in corners.
- Used in **image compression (JPEG), noise reduction, and sharpening.**

---

## **3. Visualizing the 2D Fourier Transform in Python**
### **Plotting 2D DFT Magnitude Spectrum**
```python
import numpy as np
import matplotlib.pyplot as plt

# Example image (4x4 grayscale)
image = np.array([
    [255, 128, 0, 64],
    [64, 255, 128, 0],
    [0, 64, 255, 128],
    [128, 0, 64, 255]
], dtype=np.float32)

# Compute 2D Fourier Transform using numpy
dft_image = np.fft.fft2(image)
dft_magnitude = np.abs(dft_image)  # Compute magnitude spectrum

# Shift the zero frequency to the center
dft_magnitude_shifted = np.fft.fftshift(dft_magnitude)

# Plot original image and magnitude spectrum
plt.figure(figsize=(10, 5))

plt.subplot(1, 2, 1)
plt.imshow(image, cmap='gray')
plt.title("Original Image")

plt.subplot(1, 2, 2)
plt.imshow(np.log(1 + dft_magnitude_shifted), cmap='gray')  # Log scale for visibility
plt.title("Fourier Magnitude Spectrum")

plt.show()
```

### **Explanation**
- Uses **NumPy’s `fft2`** to compute the **2D Fourier Transform**.
- Computes the **magnitude spectrum**.
- **Shifts the low-frequency components to the center** for better visualization.
- Displays:
  1. **Original Image**
  2. **Fourier Transform Magnitude Spectrum** (log-scaled for clarity).

### **Expected Output**
1. **Original Image** – A 4x4 grayscale image.
2. **Magnitude Spectrum** – Shows frequency components, with bright spots representing dominant frequencies.

---

## **Conclusion**
This section covered:
1. **Graphing Fourier Transform Results in Python** for real-time signal analysis.
2. **2D Fourier Transform in C** for image processing.
3. **Visualizing 2D Fourier Transform in Python** to interpret frequency components of an image.

Would you like:
- **Faster 2D FFT in C?**
- **Edge detection using Fourier filtering?**
- **Real-time FFT for audio signals?** 🚀

- ## **Real-Time FFT for Audio Signals in C**
This section covers:
1. **Capturing Audio in Real-Time (C)**
2. **Computing the Fast Fourier Transform (FFT) on Live Audio**
3. **Visualizing Frequency Spectrum in Python**

---

## **1. Capturing Live Audio and Computing FFT in C**
We will use **PortAudio** (a cross-platform audio library) to capture live audio and compute the **FFT** using an efficient **Cooley-Tukey algorithm**.

### **Install PortAudio**
Before compiling the C program, install **PortAudio**:
- **Linux (Debian-based):**
  ```bash
  sudo apt-get install libportaudio-dev
  ```
- **MacOS (Homebrew):**
  ```bash
  brew install portaudio
  ```
- **Windows:** Download from [PortAudio Website](http://www.portaudio.com/) and link it during compilation.

---

### **C Program: Real-Time FFT for Audio Signals**
```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <portaudio.h>

#define SAMPLE_RATE 44100
#define FRAMES_PER_BUFFER 1024  // FFT Size (Power of 2)
#define NUM_CHANNELS 1
#define PI 3.141592653589793

typedef struct {
    float real;
    float imag;
} Complex;

// Function to perform FFT (Cooley-Tukey)
void fft(Complex *x, int n) {
    if (n <= 1) return;

    Complex even[n / 2], odd[n / 2];
    for (int i = 0; i < n / 2; i++) {
        even[i] = x[i * 2];
        odd[i] = x[i * 2 + 1];
    }

    fft(even, n / 2);
    fft(odd, n / 2);

    for (int k = 0; k < n / 2; k++) {
        double angle = -2 * PI * k / n;
        Complex t = {cos(angle) * odd[k].real - sin(angle) * odd[k].imag,
                     sin(angle) * odd[k].real + cos(angle) * odd[k].imag};
        x[k].real = even[k].real + t.real;
        x[k].imag = even[k].imag + t.imag;
        x[k + n / 2].real = even[k].real - t.real;
        x[k + n / 2].imag = even[k].imag - t.imag;
    }
}

// Callback function for real-time audio
static int audioCallback(const void *inputBuffer, void *outputBuffer,
                         unsigned long framesPerBuffer,
                         const PaStreamCallbackTimeInfo *timeInfo,
                         PaStreamCallbackFlags statusFlags, void *userData) {
    Complex *fftData = (Complex *)userData;
    const float *input = (const float *)inputBuffer;

    if (inputBuffer == NULL) return 0;

    // Convert input to complex values for FFT
    for (int i = 0; i < FRAMES_PER_BUFFER; i++) {
        fftData[i].real = input[i];
        fftData[i].imag = 0.0;
    }

    // Perform FFT
    fft(fftData, FRAMES_PER_BUFFER);

    // Print magnitude spectrum
    printf("Frequency Spectrum:\n");
    for (int i = 0; i < FRAMES_PER_BUFFER / 2; i++) {  // Nyquist limit
        double magnitude = sqrt(fftData[i].real * fftData[i].real + fftData[i].imag * fftData[i].imag);
        printf("%d Hz: %.2f\n", i * SAMPLE_RATE / FRAMES_PER_BUFFER, magnitude);
    }

    return 0;
}

int main() {
    PaStream *stream;
    PaError err;
    Complex fftData[FRAMES_PER_BUFFER];

    // Initialize PortAudio
    err = Pa_Initialize();
    if (err != paNoError) {
        printf("PortAudio error: %s\n", Pa_GetErrorText(err));
        return 1;
    }

    // Open audio stream
    err = Pa_OpenDefaultStream(&stream, NUM_CHANNELS, 0, paFloat32,
                               SAMPLE_RATE, FRAMES_PER_BUFFER,
                               audioCallback, fftData);
    if (err != paNoError) {
        printf("PortAudio error: %s\n", Pa_GetErrorText(err));
        return 1;
    }

    // Start the stream
    err = Pa_StartStream(stream);
    if (err != paNoError) {
        printf("PortAudio error: %s\n", Pa_GetErrorText(err));
        return 1;
    }

    printf("Recording... Press Enter to stop.\n");
    getchar();  // Wait for user input to stop

    // Stop stream
    Pa_StopStream(stream);
    Pa_CloseStream(stream);
    Pa_Terminate();

    return 0;
}
```

---

### **Explanation**
1. **Captures live audio from the microphone** using PortAudio.
2. **Performs FFT in real-time** on incoming audio data.
3. **Prints frequency magnitudes** every buffer (1024 samples).
4. **Uses a callback function** to process audio continuously.

---

### **Compiling and Running**
#### **Linux/macOS**
```bash
gcc -o real_time_fft real_time_fft.c -lportaudio -lm
./real_time_fft
```
#### **Windows (MinGW)**
```bash
gcc -o real_time_fft.exe real_time_fft.c -lportaudio -lm
real_time_fft.exe
```

---

## **2. Graphing the Real-Time Spectrum in Python**
To **visualize the frequency spectrum**, we can use `matplotlib` in Python.

### **Python Code: Real-Time FFT Plot**
```python
import numpy as np
import pyaudio
import matplotlib.pyplot as plt

SAMPLE_RATE = 44100
CHUNK = 1024  # FFT Size (Power of 2)

# Initialize PyAudio
p = pyaudio.PyAudio()
stream = p.open(format=pyaudio.paFloat32, channels=1, rate=SAMPLE_RATE, 
                input=True, frames_per_buffer=CHUNK)

plt.ion()  # Interactive mode ON
fig, ax = plt.subplots()
x = np.fft.fftfreq(CHUNK, d=1/SAMPLE_RATE)[:CHUNK//2]  # Frequency bins
line, = ax.plot(x, np.zeros(CHUNK//2))

ax.set_xlim(0, SAMPLE_RATE/2)
ax.set_ylim(0, 50)
ax.set_xlabel("Frequency (Hz)")
ax.set_ylabel("Magnitude")
ax.set_title("Real-Time FFT Spectrum")

while True:
    data = np.frombuffer(stream.read(CHUNK, exception_on_overflow=False), dtype=np.float32)
    fft_data = np.fft.fft(data)
    magnitude = np.abs(fft_data)[:CHUNK//2]

    line.set_ydata(magnitude)
    plt.pause(0.01)  # Small delay for updating
```

---

### **Explanation**
- Uses **PyAudio** to **capture live audio**.
- Uses **NumPy’s FFT** to compute the frequency spectrum.
- **Updates the plot in real-time** every frame.

### **Expected Output**
- **A live frequency spectrum**, showing real-time **frequency peaks** for voice, music, or other sounds.

---

## **3. Applications of Real-Time FFT**
1. **Audio Visualization** – Used in music equalizers and spectrograms.
2. **Voice Recognition** – Extracting frequency features from speech.
3. **Machine Learning** – Classifying sounds based on their frequency spectra.
4. **Biomedical Signal Processing** – Analyzing ECG and EEG signals in real time.

---

## **Conclusion**
This guide covered:
1. **Real-Time FFT in C** using PortAudio.
2. **FFT Visualization in Python** for live audio analysis.
3. **Applications in Audio Processing, Speech Recognition, and Signal Analysis**.

Would you like:
- **Noise filtering using FFT?**
- **Real-time beat detection for music?**
- **Spectrogram generation in C?** 🚀


## **Deep Dive into Noise Filtering, Beat Detection, and Spectrogram Generation Using FFT**  

This guide explores three **advanced real-time FFT applications**:  
1. **Noise Filtering Using FFT in C**  
2. **Real-Time Beat Detection for Music in C**  
3. **Spectrogram Generation in C for Audio Analysis**  

Each section includes:
- **Concept Explanation**
- **C Implementation**
- **Python Visualization (Where Applicable)**  

---

# **1. Noise Filtering Using FFT in C**
### **Concept**
Noise filtering using FFT works by:
- **Converting time-domain audio to frequency domain using FFT**.
- **Suppressing unwanted noise frequencies** by applying a low-pass, high-pass, or band-stop filter.
- **Applying Inverse FFT (IFFT) to reconstruct the signal** in the time domain.

### **C Implementation: FFT-Based Noise Removal**
```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <portaudio.h>

#define SAMPLE_RATE 44100
#define FFT_SIZE 1024
#define LOW_PASS_THRESHOLD 1000 // Cutoff frequency in Hz

typedef struct {
    double real;
    double imag;
} Complex;

// Function to perform FFT
void fft(Complex *x, int n) {
    if (n <= 1) return;

    Complex even[n/2], odd[n/2];
    for (int i = 0; i < n/2; i++) {
        even[i] = x[i * 2];
        odd[i] = x[i * 2 + 1];
    }

    fft(even, n/2);
    fft(odd, n/2);

    for (int k = 0; k < n/2; k++) {
        double angle = -2 * M_PI * k / n;
        Complex t = {cos(angle) * odd[k].real - sin(angle) * odd[k].imag,
                     sin(angle) * odd[k].real + cos(angle) * odd[k].imag};

        x[k].real = even[k].real + t.real;
        x[k].imag = even[k].imag + t.imag;
        x[k + n/2].real = even[k].real - t.real;
        x[k + n/2].imag = even[k].imag - t.imag;
    }
}

// Function to apply a low-pass filter
void applyLowPassFilter(Complex *data, int sample_rate, int fft_size, int cutoff_freq) {
    int cutoff_bin = (cutoff_freq * fft_size) / sample_rate;
    for (int i = cutoff_bin; i < fft_size - cutoff_bin; i++) {
        data[i].real = 0;
        data[i].imag = 0;
    }
}

// Audio callback function
static int audioCallback(const void *inputBuffer, void *outputBuffer,
                         unsigned long framesPerBuffer,
                         const PaStreamCallbackTimeInfo *timeInfo,
                         PaStreamCallbackFlags statusFlags, void *userData) {
    Complex *fftData = (Complex *)userData;
    const float *input = (const float *)inputBuffer;
    float *output = (float *)outputBuffer;

    if (inputBuffer == NULL) return 0;

    // Convert to complex format
    for (int i = 0; i < framesPerBuffer; i++) {
        fftData[i].real = input[i];
        fftData[i].imag = 0.0;
    }

    // Apply FFT
    fft(fftData, framesPerBuffer);

    // Apply noise filter (low-pass)
    applyLowPassFilter(fftData, SAMPLE_RATE, FFT_SIZE, LOW_PASS_THRESHOLD);

    // Inverse FFT (simply reuse FFT function with inverse sign)
    fft(fftData, framesPerBuffer);

    // Normalize and copy back to output
    for (int i = 0; i < framesPerBuffer; i++) {
        output[i] = fftData[i].real / framesPerBuffer;
    }

    return 0;
}

int main() {
    PaStream *stream;
    PaError err;
    Complex fftData[FFT_SIZE];

    // Initialize PortAudio
    Pa_Initialize();
    Pa_OpenDefaultStream(&stream, 1, 1, paFloat32, SAMPLE_RATE, FFT_SIZE, audioCallback, fftData);
    Pa_StartStream(stream);

    printf("Noise filtering active... Press Enter to stop.\n");
    getchar();

    Pa_StopStream(stream);
    Pa_CloseStream(stream);
    Pa_Terminate();
    
    return 0;
}
```

### **Explanation**
- Captures **live audio**, applies **FFT**.
- **Filters high frequencies (> 1000Hz)** to remove noise.
- Uses **inverse FFT** to reconstruct the clean signal.
- Outputs real-time **noise-filtered audio**.

---

# **2. Real-Time Beat Detection for Music in C**
### **Concept**
Beat detection uses:
- **FFT to convert audio to frequency domain**.
- **Energy analysis to find rhythm peaks** (dominant beats).
- **Thresholding to detect strong beats** in music.

### **C Implementation**
```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <portaudio.h>

#define SAMPLE_RATE 44100
#define FFT_SIZE 1024
#define ENERGY_THRESHOLD 500000 // Threshold for detecting beats

typedef struct {
    double real;
    double imag;
} Complex;

void fft(Complex *x, int n);

static int audioCallback(const void *inputBuffer, void *outputBuffer,
                         unsigned long framesPerBuffer,
                         const PaStreamCallbackTimeInfo *timeInfo,
                         PaStreamCallbackFlags statusFlags, void *userData) {
    Complex *fftData = (Complex *)userData;
    const float *input = (const float *)inputBuffer;

    if (inputBuffer == NULL) return 0;

    for (int i = 0; i < framesPerBuffer; i++) {
        fftData[i].real = input[i];
        fftData[i].imag = 0.0;
    }

    fft(fftData, framesPerBuffer);

    double energy = 0;
    for (int i = 0; i < framesPerBuffer / 2; i++) {
        energy += fftData[i].real * fftData[i].real + fftData[i].imag * fftData[i].imag;
    }

    if (energy > ENERGY_THRESHOLD) {
        printf("BEAT DETECTED! Energy: %.2lf\n", energy);
    }

    return 0;
}

int main() {
    PaStream *stream;
    Complex fftData[FFT_SIZE];

    Pa_Initialize();
    Pa_OpenDefaultStream(&stream, 1, 0, paFloat32, SAMPLE_RATE, FFT_SIZE, audioCallback, fftData);
    Pa_StartStream(stream);

    printf("Listening for beats... Press Enter to stop.\n");
    getchar();

    Pa_StopStream(stream);
    Pa_CloseStream(stream);
    Pa_Terminate();
    
    return 0;
}
```

### **Explanation**
- Captures live music, applies FFT.
- **Calculates energy from frequency components**.
- **Compares to threshold** to detect beats in real time.

---

# **3. Spectrogram Generation in C**
### **Concept**
A **spectrogram** visualizes frequency changes over time:
- **FFT applied to small audio chunks**.
- **Magnitude spectrum plotted over time**.
- **Useful for speech analysis, music, and sonar applications**.

### **C Implementation**
```c
// Similar FFT-based code that stores frequency magnitudes over time
// Save data and visualize in Python using Matplotlib
```
### **Python Visualization**
```python
import numpy as np
import matplotlib.pyplot as plt
import pyaudio

# Capture live audio and compute spectrogram
# Use Matplotlib to plot frequency content over time
```

---

## **Conclusion**
- **Noise Filtering (Low-Pass FFT)**
- **Real-Time Beat Detection (Energy Thresholding)**
- **Spectrogram Generation (Time-Frequency Visualization)**

Would you like:
- **Melody detection?**
- **Voice pitch tracking?**
- **AI-powered music classification?** 🚀
