/*
In an array of integers n, the prefix sum array is the array whose every element is the sum of all elements, of the original array, up to the current index.

eg -

Given an array of n=5 , array[]={1,2,3,4,5}
Its Prefix Sum array will be p[].
p[0]=array[0]=1;
p[1]=array[0]+array[1]=1+2=3;
p[2]=array[0]+array[1]+array[2]=1+2+3=6;
p[3]=array[0]+array[1]+array[2]+array[3]=1+2+3+4=10;
p[4]=array[0]+array[1]+array[2]+array[3]+array[4]=1+2+3+4+5=15;
Final Prefix Sum Array would be={1,3,6,10,15}
*/

// CODE -
#include<iostream>

using namespace std;
int main() {
  int ar[5] = {1,2,3,4,5};
  int prefix[5];
  
  // since there are no elements before 0th element.
  // hence prefix sum of 0th element will be element at 0th index only.
  prefix[0] = ar[0]; //initializing first element
  

  // now start iterating from index 1 till n-1.
  for (int i = 1; i < 5; i++) {
    // prefix[i-1] contains sum of values of array from index 0 till i-1.
    // hence to find prefix[i] , instead of iterating again ang again to find sum of values from index 0 till i.
    // we will directly use value of prefix[i-1] to get sum from index 0 till i-1.
    // then add arr[i] to it , to get sum of values from index 0 to i.
    prefix[i] = prefix[i - 1] + ar[i];
  }

  for (int i = 0; i < 5; i++) {
    cout << prefix[i] << " "; //printing the array
  }
  return 0;
}
