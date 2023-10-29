//Wave Print Matrix Program - Mr. Eshank Tyagi
import java.util.*;
class WavePrintMatrixProgram
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);

        System.out.print("\nEnter the number of rows : ");
        int r = sc.nextInt();

        System.out.print("\nEnter the number of columns : ");
        int c = sc.nextInt();

        int[][] arr = new int[r][c];

        System.out.println("\nEnter the elements of the matrix :-");

        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                arr[i][j] = sc.nextInt();
            }
        }

        System.out.println("The matrix is :-");

        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
                System.out.print(arr[i][j] + " ");

            System.out.println();
        }

        System.out.println("The wave print of the matrix is :-");

        for(int i = 0; i < c; i++)
        {
            if(i % 2 == 0)
            {
                for(int j = 0; j < r; j++)
                    System.out.print(arr[j][i] + " ");
            }
            else
            {
                for(int j = r - 1; j >= 0; j--)
                    System.out.print(arr[j][i] + " ");
            }
        }
        sc.close();
    }
}
