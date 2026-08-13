/*
Write a C program to take input number in A(2*2) and B(2*2) matrix.Find the sum of A and B and store in C(2*2) matrix.Print A,B and C 
*/

#include <stdio.h>

void input(int a[2][2], int b[2][2])
{
    int i, j;

    printf("Enter elements of Matrix A:\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("Enter a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nEnter elements of Matrix B:\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("Enter b[%d][%d]: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }
}

void doSum(int a[2][2], int b[2][2], int c[2][2])
{
    int i, j;

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void printMatrix(int a[2][2])
{
    int i, j;

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int a[2][2], b[2][2], c[2][2];

    input(a, b);

    doSum(a, b, c);

    printf("\nMatrix A:\n");
    printMatrix(a);

    printf("\nMatrix B:\n");
    printMatrix(b);

    printf("\nSum Matrix C:\n");
    printMatrix(c);

    return 0;
}
