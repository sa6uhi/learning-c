#include <stdio.h>

// Bubble sort algorithm to sort an array in ascending order
// Time complexity: O(n^2)
// Space complexity: O(1)
// This algorithm is not efficient for large datasets
// It is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order.
// The pass through the list is repeated until the list is sorted.
// The algorithm gets its name from the way larger elements "bubble" to the top of the list.
// The algorithm is not suitable for large data sets as its average and worst-case time complexity is quite high.

void sort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}    

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}

int main()
{
    int array[] = {9, 1, 8, 2, 7, 3, 6, 4, 5};`
    int size = sizeof(array) / sizeof(array[0]);

    sort(array, size);
    printArray(array, size);

    return 0;
}