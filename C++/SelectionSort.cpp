void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

void selectionSort(vector<int>& arr, int n)
{
    int minVal;

    // This is used to iterate over all elements of array.
    for (int i = 0; i < n - 1; i++)
    {
        // This is used to store the minimum value index.
        minVal = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minVal]) {
                minVal = j;
            }

        // Swapping the minimum element with the first element.
        swap(&arr[minVal], &arr[i]);
    }
}
