#include <iostream>
using namespace std;
void removeDuplicates(int *arr, int &size)
{
    int *temp = new int[size];
    int count = 0;
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] != arr[i + 1])
        {
            temp[count++] = arr[i];
        }
    }

    temp[count++] = arr[size - 1];

    for (int i = 0; i < count; ++i)
    {
        arr[i] = temp[i];
    }
    size = count;

    delete[] temp;
}
void printArray(int *arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << " " << arr[i];
    }
    cout << endl;
}
int main()
{
    int SIZE = 0;
    cout << "Enter size of array: ";
    cin >> SIZE;
    int *arr = new int[SIZE];

    cout << "Enter arr of " << SIZE << endl;
    for (int i = 0; i < SIZE; ++i)
    {
        cin >> arr[i];
    }

    printArray(arr, SIZE);

    removeDuplicates(arr, SIZE);

    printArray(arr, SIZE);

    delete[] arr;
}