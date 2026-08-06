/*
* Date : 30/07/2026
An online shop keeps it product catalogue sorted by product ID(Whole Number ) in ascending order. When a customer search for a specific product ID .The system return true if the product item present in the catalogue else it returns false.Which searching techinque is used to find the product id quickly from the catalogue.Implement this searching method using a function.The function takes parameters product ID List ,size of the list and product ID to be searched
Sample Input : [2,8,9,16,18,26,38,48,51,90]
Case 1: Product ID to be searched : 26
Case 2: Product ID to be searched : 49
*/

#include <stdio.h>

void binarySearch(int a[], int size, int item)
{
    int low = 0, high = size - 1, mid;
    int flag = 0;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (a[mid] == item)
        {
            flag = 1;
            printf("Product ID found at index %d\n", mid);
            break;
        }
        else if (item < a[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if (flag == 0)
        printf("Product ID not found\n");
}

int main()
{
    int a[] = {2, 8, 9, 16, 18, 26, 38, 48, 51, 90};
    int size = 10;
    int item;

    printf("Enter Product ID to Search: ");
    scanf("%d", &item);

    binarySearch(a, size, item);

    return 0;
}
