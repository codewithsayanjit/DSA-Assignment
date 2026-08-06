/*
Write a program to take input in an array 10 unordered number and apply QuickSort to order the array in ascending order.
Input: Array size = 10;
       Array Items :- [8,2,10,6,5,12,18,9,4,11]
*/

#include <stdio.h>

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (a[j] < pivot)
        {
            i++;

            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    int temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    return i + 1;
}

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(a, low, high);

        quickSort(a, low, pivot - 1);
        quickSort(a, pivot + 1, high);
    }
}

int main()
{
    int a[10] = {8, 2, 10, 6, 5, 12, 18, 9, 4, 11};

    quickSort(a, 0, 9);

    printf("Sorted Array:\n");

    for (int i = 0; i < 10; i++)
        printf("%d ", a[i]);

    return 0;
}
