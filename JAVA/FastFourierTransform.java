import java.util.Arrays;

public class FFT {
    
    public static void fft(double[] real, double[] imag) {
        int n = real.length;

        // Bit-reversal permutation
        int j = 0;
        for (int i = 1; i < n; i++) {
            int bit = n >> 1;
            while (j >= bit) {
                j -= bit;
                bit >>= 1;
            }
            j += bit;
            if (i < j) {
                // Swap real[i] and real[j]
                double tempReal = real[i];
                double tempImag = imag[i];
                real[i] = real[j];
                imag[i] = imag[j];
                real[j] = tempReal;
                imag[j] = tempImag;
            }
        }

        // FFT
        for (int length = 2; length <= n; length <<= 1) {
            double ang = 2 * Math.PI / length;
            double wReal = Math.cos(ang);
            double wImag = Math.sin(ang);
            for (int i = 0; i < n; i += length) {
                double uReal = 1;
                double uImag = 0;
                for (int j = 0; j < length / 2; j++) {
                    int evenIndex = i + j;
                    int oddIndex = i + j + length / 2;

                    double tReal = uReal * real[oddIndex] - uImag * imag[oddIndex];
                    double tImag = uReal * imag[oddIndex] + uImag * real[oddIndex];

                    real[oddIndex] = real[evenIndex] - tReal;
                    imag[oddIndex] = imag[evenIndex] - tImag;
                    real[evenIndex] += tReal;
                    imag[evenIndex] += tImag;

                    double tempReal = uReal;
                    uReal = uReal * wReal - uImag * wImag;
                    uImag = tempReal * wImag + uImag * wReal;
                }
            }
        }
    }

    public static void main(String[] args) {
        // Example input: 8 points (must be a power of 2)
        // Real part 
        double[] real = {0, 1, 2, 3, 4, 5, 6, 7};
        // Imaginary part (initialized to 0)
        double[] imag = new double[real.length]; 

        System.out.println("Original:");
        System.out.println("Real: " + Arrays.toString(real));
        System.out.println("Imaginary: " + Arrays.toString(imag));

        // Perform FFT
        fft(real, imag);

        System.out.println("\nFFT Result:");
        System.out.println("Real: " + Arrays.toString(real));
        System.out.println("Imaginary: " + Arrays.toString(imag));
    }
}
