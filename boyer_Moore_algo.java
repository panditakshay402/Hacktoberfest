import java.io.*;
import java.util.*;
class Solution
{
    public static void sort012(int a[], int n)
    {

         int low=0,mid=0,high=a.length-1;
        while(mid<=high)
        {
            if(a[mid]==0)
            {
                int temp =a[mid];
                a[mid]=a[low];
                a[low]=temp;
                low++;
                mid++;
            }

            else if(a[mid]==1)
                mid++;
            else if(a[mid]==2)
            {
                int temp=a[mid];
                a[mid]=a[high];
                a[high]=temp;
                high--;
            }
        }
    }
}
