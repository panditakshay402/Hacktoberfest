//Wave Print Matrix Program - Mr. Eshank Tyagi
#include <iostream>
#include <vector>

int main() 
{
    std::vector<std::vector<int>> arr;
    int r, c;

    std::cout << "\nEnter the number of rows : ";
    std::cin >> r;

    std::cout << "\nEnter the number of columns : ";
    std::cin >> c;

    arr.resize(r, std::vector<int>(c));

    std::cout << "\nEnter the elements of the matrix :-\n";

    for(int i = 0; i < r; i++) 
    {
        for(int j = 0; j < c; j++) 
        {
            std::cin >> arr[i][j];
        }
    }

    std::cout << "The matrix is :-\n";

    for(int i = 0; i < r; i++) 
    {
        for(int j = 0; j < c; j++) 
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "The wave print of the matrix is :-\n";

    for(int i = 0; i < c; i++) 
    {
        if(i % 2 == 0) {
            for(int j = 0; j < r; j++) 
            {
                std::cout << arr[j][i] << " ";
            }
        }
        else 
        {
            for(int j = r - 1; j >= 0; j--) 
            {
                std::cout << arr[j][i] << " ";
            }
        }
    }

    return 0;
}
