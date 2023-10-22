#include <stdio.h>

int solve(int arr[],int n,int start)
{
  int res = 0;
  for(int i=start;i<n;i+=2)
  {
    int to = arr[i];
    if(i)
    // make sure current element is less than its left neighboor
    {
      if(arr[i-1]-1<to)
        to = arr[i-1]-1;
    }
    if(i+1 != n)
    // make sure current element is less than its right neighboor
    {
      if(arr[i+1]-1<to)
        to = arr[i+1]-1;
    }
    // if curr value was decreased to "to", add the difference
    res += arr[i] - to;
  }
  return res;
}

int main()
{
  int n;
  scanf("%d",&n);
  int arr[n];
  for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
  int res1 = solve(arr,n,0);
  int res2 = solve(arr,n,1);

  if(res1 < res2)
    printf("%d",res1);
  else
    printf("%d",res2);

  return 0;
}
