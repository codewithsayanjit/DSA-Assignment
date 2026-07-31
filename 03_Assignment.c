/*
* Date : 30/07/2026
A class teacher has a list of marks of 10 students in a random fashion.All the marks are whole number.Before publishing the result the class teacher wants to arrange the marks in an order so that the rank of the students can easily be detected.Use a method to arrange the marks in ascending order.Which methodology to used here ? Implement the method using C program.
Sample Input: [99,85,58,71,46,80,78,65,49,55]
*/

#include <stdio.h>

void bubbleSort(int arr[], int size)
{
    int i, j, temp;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {99, 85, 58, 71, 46, 80, 78, 65, 49, 55};
    int size = 10;
    int i;

    bubbleSort(arr, 10);

    printf("Marks in Ascending Order:\n");

    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}