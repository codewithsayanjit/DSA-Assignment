/*
* Date : 30/07/2026
In a library the books are store using there Acc. no. Acc number is the whole number the consist maximum 3 digits number whole number.Consider an array where the access number of the books are store in are organised fashion.The librarian once to search for us specific access number in the array .Which searching methodology the librarian must follow ,write the C program to implement this searching technique.
Sample input: [101,20,49,385,210,620,85,921,12,206]
Case 1: Access number to be search : 85
Case 2: Access number to be search : 465
*/

#include <stdio.h>

void linearSearch(int a[], int size, int item)
{
    int i, flag = 0;

    for (i = 0; i < size; i++)
    {
        if (a[i] == item)
        {
            flag = 1;
            printf("Item found at index %d\n", i);
            break;
        }
    }

    if (flag == 0)
        printf("Item not found\n");
}

int main()
{
    int a[] = {101, 20, 49, 385, 210, 620, 85, 921, 12, 206};
    int size = 10;
    int item;

    printf("Array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", a[i]);

    printf("\nEnter Access Number to Search: ");
    scanf("%d", &item);

    linearSearch(a, size, item);

    return 0;
}