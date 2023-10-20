public class CyclicSort {
    public static void cyclicSort(int[] arr) {
        int n = arr.length;
        
        for (int i = 0; i < n; ) {
            if (arr[i] != i + 1) {
                // Place the current element at its correct position
                int temp = arr[i];
                arr[i] = arr[temp - 1];
                arr[temp - 1] = temp;
            } else {
                i++;
            }
        }
    }

    public static void main(String[] args) {
        int[] arr = {3, 5, 2, 1, 4};
        cyclicSort(arr);

        System.out.println("Sorted Array:");
        for (int num : arr) {
            System.out.print(num + " ");
        }
    }
}
