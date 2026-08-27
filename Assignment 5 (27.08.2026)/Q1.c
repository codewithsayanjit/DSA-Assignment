// Single Linked List creation & traversal using switch case.

#include <stdio.h>
#include <stdlib.h>

typedef struct st
{
    int n;
    struct st *next;
} link;

link *head = NULL;

// Function for creating a node
void create(int data)
{
    link *ptr = NULL, *temp = NULL;

    ptr = (link *)malloc(sizeof(link));

    ptr->n = data;
    ptr->next = NULL;

    if (head == NULL)
    {
        head = ptr;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = ptr;
    }
}

// Function for traversing the linked list
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

int main()
{
    int choice, data;

    while (1)
    {
        printf("\n1. Create");
        printf("\n2. Traverse");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            create(data);
            break;

        case 2:
            printf("Linked List: ");
            traverse();
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
