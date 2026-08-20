/*
WAP in C to take input marks of ten students randomly in an array,
sort the array using merge sort and show the highest and lowest marks.

Sample case:
[80,73,59,92,86,47,92,58,91,48]
*/

#include <stdio.h>

void merge(int a[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = 0;
    int temp[10];

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            temp[k] = a[i];
            i++;
        }
        else
        {
            temp[k] = a[j];
            j++;
        }
        k++;
    }

    while (i <= mid)
    {
        temp[k] = a[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        temp[k] = a[j];
        j++;
        k++;
    }

    for (i = low, k = 0; i <= high; i++, k++)
    {
        a[i] = temp[k];
    }
}

void merge_sort(int a[], int low, int high)
{
    int mid;

    if (low < high)
    {
        mid = (low + high) / 2;

        merge_sort(a, low, mid);
        merge_sort(a, mid + 1, high);

        merge(a, low, mid, high);
    }
}

int main()
{
    int a[10] = {80, 73, 59, 92, 86, 47, 92, 58, 91, 48};
    int i;

    merge_sort(a, 0, 9);

    printf("Sorted array: ");

    for (i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\nHighest marks = %d", a[9]);
    printf("\nLowest marks = %d", a[0]);

    return 0;
}
