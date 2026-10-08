/*
Q.8.2.
Train coaches using Doubly Linked List:
A railway system stores the coaches of a train in a doubly linked list.
Each coach has a coach number and link to both previous and next coaches.
This allows the railway staff to inspect the coaches from the engine towards
the last coach and from the last coach back towards the engine.

Task: — Write a C Program (WACP) to:
i) Create a doubly linked list of coach numbers.
ii) Traverse and display the coaches in forward order.
iii) Traverse and display the coaches in backward order.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct link
{
    int n;
    struct link *next, *prev;
} link;

link *head = NULL;
link *tail = NULL;

void create(int item)
{
    link *ptr, *temp;

    ptr = (link *)malloc(sizeof(link));

    ptr->n = item;
    ptr->next = NULL;
    ptr->prev = NULL;

    if (head == NULL)
    {
        head = ptr;
    }

    if (tail == NULL)
    {
        tail = ptr;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = ptr;
        ptr->prev = temp;
        tail = ptr;
    }
}

void traverse()
{
    link *temp;

    temp = head;

    while (temp != NULL)
    {
        printf("%d ", temp->n);
        temp = temp->next;
    }

    printf("\n");
}

void backward()
{
    link *temp;

    temp = tail;

    while (temp != NULL)
    {
        printf("%d ", temp->n);
        temp = temp->prev;
    }

    printf("\n");
}

int main()
{
    int choice, item;

    do
    {
        printf("\n1. Create\n");
        printf("2. Forward Traverse\n");
        printf("3. Backward Traverse\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter coach number: ");
            scanf("%d", &item);
            create(item);
            break;

        case 2:
            printf("Forward: ");
            traverse();
            break;

        case 3:
            printf("Backward: ");
            backward();
            break;

        case 4:
            printf("Exit\n");
            break;

        default:
            printf("Invalid choice\n");
        }

    } while (choice != 4);

    return 0;
}
