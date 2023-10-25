import java.util.HashSet;
import java.util.Set;

/**
 * The Solution class checks if an array of integers contains any duplicate
 * elements.
 */
class Solution {

    /**
     * This method checks if there are any duplicate elements in the given integer
     * array.
     *
     * @param nums An array of integers to be checked for duplicates.
     * @return True if there are duplicate elements; otherwise, false.
     */
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> seen = new HashSet<>();
        for (int num : nums) {
            if (seen.contains(num)) {
                return true;
            }
            seen.add(num);
        }
        return false;
    }

    /**
     * The main method demonstrates the usage of the containsDuplicate method.
     *
     * @param args Command-line arguments (not used in this example).
     */
    public static void main(String[] args) {
        // Example input array
        int[] nums = { 9, 2, 10, 91 };

        // Create an instance of the Solution class
        Solution sol = new Solution();

        // Call the containsDuplicate method and print the result
        System.out.println(sol.containsDuplicate(nums));
    }
}
