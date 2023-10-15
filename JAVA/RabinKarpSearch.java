public class RabinKarpSearch {

    // d is the number of characters in the input alphabet
    public final static int d = 256;

    /*
     * Rabin-Karp string search algorithm.
     *
     * @param pat The pattern to search for.
     * @param txt The text to search within.
     * @param q   A prime number used for hashing.
     */
    public static void search(String pat, String txt, int q) {
        int M = pat.length(); // Length of the pattern
        int N = txt.length(); // Length of the text
        int i, j;
        int p = 0; // Hash value for the pattern
        int t = 0; // Hash value for the current window of text
        int h = 1; // Initial hash value multiplier

        // Calculate "h" as "d^(M-1) % q"
        for (i = 0; i < M - 1; i++) {
            h = (h * d) % q;
        }

        // Calculate the initial hash values for pattern and the first window of text
        for (i = 0; i < M; i++) {
            p = (d * p + pat.charAt(i)) % q;
            t = (d * t + txt.charAt(i)) % q;
        }

        // Slide the pattern over the text one character at a time
        for (i = 0; i <= N - M; i++) {

            // Check if the hash values match
            if (p == t) {

                // If hash values match, check character by character
                for (j = 0; j < M; j++) {
                    if (txt.charAt(i + j) != pat.charAt(j)) {
                        break;
                    }
                }

                // If the inner loop completes, it means pattern found
                if (j == M) {
                    System.out.println("Pattern found at index " + i);
                }
            }

            // Calculate the hash value for the next window of text
            if (i < N - M) {
                t = (d * (t - txt.charAt(i) * h) + txt.charAt(i + M)) % q;

                // Ensure the hash value is positive
                if (t < 0) {
                    t = (t + q);
                }
            }
        }
    }

    public static void main(String[] args) {
        String txt = "GEEKS FOR GEEKS";
        String pat = "GEEK";

        // A prime number used for hashing
        int q = 101;

        // Call the search function to find the pattern in the text
        search(pat, txt, q);
    }
}
