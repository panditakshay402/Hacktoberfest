
#include <stdio.h>

// merge sort function  //look at the algorithm
void mergeSort(int a[], int lb, int up);

// function to merge the sub arrays
void merge(int a[], int lb, int mid, int up);

// function to print the array
void printArray(int a[], int size);


int main(){

    int arr[] = {15, 5, 24, 8, 1, 3, 16, 10, 20};
    int len = sizeof(arr)/sizeof(arr[0]);

    printf("Given array: \n");
    printArray(arr, len);

    // calling merge sort
    mergeSort(arr, 0, len - 1);

    printf("\nSorted array: \n");
    printArray(arr, len);
    return 0;
}




// merge sort function  //look at the algorithm
void mergeSort(int a[], int lb, int up) //lb = lower bound up=upper bound
{
    int mid;
    if(lb < up)
    {
        mid = (lb + up) / 2;
        mergeSort(a, lb, mid);
        mergeSort(a, mid+1, up);
        merge(a, lb, mid, up);
    }
}

// function to merge the sub arrays
void merge(int a[], int lb, int mid, int up)
{
    int b[9];   //sorted sub array
    int i, j, k;

    i = lb;
    j = mid + 1;
    k = 0;

    while(i <= mid && j <= up){ //comparing 2 sub arrays and placing elements in the sorted sub array
        if(a[i] < a[j]){
            b[k] = a[i];
            k++;
            i++;
        }else{
            b[k] = a[j];
            k++;
            j++;
        }
    }

    //if elements of one sub array remain after comparing values just copy them in to sorted sub array
     while(i <= mid)
    {
        b[k++] = a[i++];
    }

    while(j <= up)
    {
        b[k++] = a[j++];
    }

    //copy sorted sub array in to our original sub array
    for(i=up; i>=lb; i--){
        a[i] = b[--k];
    }

}

// function to print the array
void printArray(int a[], int size){

    int i;
    for (i=0; i < size; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}


