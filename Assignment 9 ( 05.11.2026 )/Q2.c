/*
Write a program to create two list represent polynomial upto degree 3.
Find sum of two polynomials
exp1: 3x^3 + 2x^2 + 5
exp2: 4x^2 - 2
Result : 3x^3 + 6x^2 + 3
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct link
{
    int coeff;
    int exp;
    struct link *next;
} link;


// CREATE POLYNOMIAL
link *create()
{
    link *head = NULL, *tail = NULL, *ptr;

    int c, i;

    for (i = 3; i >= 0; i--)
    {
        printf("Enter coefficient of x^%d: ", i);
        scanf("%d", &c);

        if (c != 0)
        {
            ptr = (link *)malloc(sizeof(link));

            ptr->coeff = c;
            ptr->exp = i;
            ptr->next = NULL;

            if (head == NULL)
            {
                head = ptr;
                tail = ptr;
            }
            else
            {
                tail->next = ptr;
                tail = ptr;
            }
        }
    }

    return head;
}


// DISPLAY POLYNOMIAL
void display(link *head)
{
    link *temp = head;
    int first = 1;

    while (temp != NULL)
    {
        if (temp->coeff > 0 && !first)
            printf(" + ");

        else if (temp->coeff < 0)
            printf(" - ");

        int c = abs(temp->coeff);

        if (temp->exp == 0)
            printf("%d", c);

        else if (temp->exp == 1)
            printf("%dx", c);

        else
            printf("%dx^%d", c, temp->exp);

        first = 0;
        temp = temp->next;
    }

    if (first)
        printf("0");

    printf("\n");
}


// ADD TWO POLYNOMIALS
link *add(link *p1, link *p2)
{
    link *head = NULL, *tail = NULL, *ptr;

    while (p1 != NULL && p2 != NULL)
    {
        ptr = (link *)malloc(sizeof(link));

        if (p1->exp == p2->exp)
        {
            ptr->coeff = p1->coeff + p2->coeff;
            ptr->exp = p1->exp;

            p1 = p1->next;
            p2 = p2->next;
        }

        else if (p1->exp > p2->exp)
        {
            ptr->coeff = p1->coeff;
            ptr->exp = p1->exp;

            p1 = p1->next;
        }

        else
        {
            ptr->coeff = p2->coeff;
            ptr->exp = p2->exp;

            p2 = p2->next;
        }

        ptr->next = NULL;

        if (ptr->coeff != 0)
        {
            if (head == NULL)
            {
                head = ptr;
                tail = ptr;
            }
            else
            {
                tail->next = ptr;
                tail = ptr;
            }
        }
        else
        {
            free(ptr);
        }
    }

    while (p1 != NULL)
    {
        ptr = (link *)malloc(sizeof(link));

        ptr->coeff = p1->coeff;
        ptr->exp = p1->exp;
        ptr->next = NULL;

        if (head == NULL)
        {
            head = ptr;
            tail = ptr;
        }
        else
        {
            tail->next = ptr;
            tail = ptr;
        }

        p1 = p1->next;
    }

    while (p2 != NULL)
    {
        ptr = (link *)malloc(sizeof(link));

        ptr->coeff = p2->coeff;
        ptr->exp = p2->exp;
        ptr->next = NULL;

        if (head == NULL)
        {
            head = ptr;
            tail = ptr;
        }
        else
        {
            tail->next = ptr;
            tail = ptr;
        }

        p2 = p2->next;
    }

    return head;
}


int main()
{
    link *p1 = NULL, *p2 = NULL, *result = NULL;

    printf("\nEnter First Polynomial:\n");
    p1 = create();

    printf("\nEnter Second Polynomial:\n");
    p2 = create();

    printf("\nFirst Polynomial: ");
    display(p1);

    printf("Second Polynomial: ");
    display(p2);

    result = add(p1, p2);

    printf("Sum of Polynomials: ");
    display(result);

    return 0;
}
