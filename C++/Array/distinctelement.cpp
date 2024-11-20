#include <iostream>
// using namespace std;

int main()
{
    // Ask user the size of the array to be input
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    // initialize and allocate size*sizeof(int) space to the array
    int array[size];

    // ask user to enter the elemnts in the array
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++)
    {
        std::cin >> array[i];
    }

    // Show the elments of the array
    std::cout << "The elements of the array are: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }

    // Print the unique elements of the array
    std::cout << "\nUnique elements of the said array: ";
    for (int i = 0; i < size; i++)
    {
        int j;
        for (j = 0; j < i; j++)
            if (array[i] == array[j])
                break;
        if (i == j)
            std::cout << array[i] << " ";
    }

    return 0;
}
