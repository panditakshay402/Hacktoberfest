/*Sample OUTPUT
    1
   21
  321
 4321
54321*/
#include <stdio.h>
int main()
{
    int n, i, j;
    // Prompt the user to enter the number of rows
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    // Outer loop to iterate through rows
    for (i = 1; i <= n; i++)
    {
        // Inner loop to print spaces before numbers
        for (j = n; j >= 1; j--)
        {
            if (j <= i)
            {
                //To print the number 
                printf("%d", j);
            }
            else
            {
                //Space for alignment
                printf(" ");
            }
        }
        // Move to the next line after each row
        printf("\n");
    }
}
/*This C code generates a right-angled triangle pattern with descending numbers and spaces. It first prompts the user for the number of rows, which determines the pattern's size. It uses nested loops: the outer one controls rows, and the inner one handles numbers and spaces. The inner loop prints numbers in descending order from the current row number and spaces for alignment. A newline character separates each row. This process repeats until the specified number of rows is reached, resulting in a visually appealing pattern similar to the provided sample output.*/