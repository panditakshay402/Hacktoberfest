#include<stdio.h>
int main() {
  int i, j, n;
  printf("Enter no. of rows: ");
  scanf("%d", &n);

  // Iterate over the rows
  for (i = 0; i < n; i++) {
    // Iterate over the columns
    for (j = 0; j < n; j++) {
      // Print an asterisk
      printf("*");
    }

    // Print a newline character to start a new row
    printf("\n");
  }
  return 0;
}


/*
 OUTPUT

 Enter no. of rows: 5

*****
*****
*****
*****
*****

*/