import java.util.*;

public class BinarySearch {
private static int binarySearch(int  Array[] , int num) {
        int low = 0;
        int high = Array.length - 1;
        
        while (low <= high){
            int midIndex = (low + high) / 2;
            int mid = Array[midIndex];
            
            if (num == mid){
                return midIndex;
            }
            if (num < mid){
                high = midIndex - 1;
            }
            if (num > mid){
                low = midIndex + 1;
            }
        }
        
        return -1;
  }

    public static void main(String args[])
    {
        int[] array = {2,4,5,6,8,11,14};
        
        System.out.println("The location of number in Array:"+binarySearch(array, 11));
        // 5 
        System.out.println("The location of number in Array:"+binarySearch(array, 3));
        //-1 i.e the array doesnt contain that number.

    }
}
