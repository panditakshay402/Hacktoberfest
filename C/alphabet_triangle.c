#include<stdio.h>
int main()
{
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=4-i;j++)
        {
            printf(" ");
        }
        for(int k=1;k<=i;k++)
        {
            int a=k+64;
         char c=(char)a;   
            printf("%c",c);
             
        }
        printf("\n");
    }
    return 0;
}