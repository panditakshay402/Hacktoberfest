#include <stdio.h>
int main() {
   int rows, j, k;
   printf("Enter the number of rows: ");
   scanf("%d", &rows);
   for (int i = rows; i >= 1; --i) {
      for (space = 0; k< rows - i; ++k)
         printf("  ");
      for (j = i; j <= 2 * i - 1; ++j)
         printf("* ");
      for (j = 0; j < i - 1; ++j)
         printf("* ");
      printf("\n");
   }
   return 0;
}
