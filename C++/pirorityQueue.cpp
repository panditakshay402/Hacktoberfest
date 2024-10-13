#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define MAX 10
using namespace std;
int queue[MAX];

int front = -1, rear = -1;

void insertionSort(int arr[], int N)
{
    for (int i = 1; i < N; i++)
    {
        int key = arr[i];
        int j = i - 1;
        // Move elements of arr[0..i-1], that are less than key, to one position to the right
        while (j >= 0 && arr[j] < key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


void insert()
{
    int num;
    printf("Enter a number to insert in queue from rear : ");
    scanf("%d", &num);
    if (rear == MAX - 1)
    {
        printf("Overflow condtion");
    }
    else if (rear == -1 && front == -1)
    {
        rear = 0, front = 0;
        queue[rear] = num;
    }
    else
    {
        rear++;
        queue[rear] = num;
    }
    insertionSort(queue, rear + 1);
}
int main()
{
    insert();
    insert();
    insert();
    insert();

    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    return 0;
}
