/*
Q.8.1.
Reversing a Delivery Route  using a Singly linked list.

A delivery Company Store it's delivery stops in a singly linked list.
Each Node Contains a Stop number and a pointer to the next stop .
After completing the deliveries , the driver needs to stops dilsplayed in
reverse order for the return journey.

Task: WACP to create the route , display it , reverse the singly linked , and display reversed route.

Example:
    Original Route : 101 -> 102 -> 103 -> 104 -> NULL
    Reversed Route : 104 -> 103 -> 102 -> 101 -> NULL
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct st
{
    int n;
    struct st *next;
} link;

link *head = NULL;

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

void reverse()
{
    link *pre = NULL, *curr = head, *post;

    while (curr != NULL)
    {
        post = curr->next;
        curr->next = pre;
        pre = curr;
        curr = post;
    }

    head = pre;
}

int main()
{
    int choice, data;

    while (1)
    {
        printf("\n1. Create");
        printf("\n2. Traverse");
        printf("\n3. Reverse");
        printf("\n4. Exit");
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
            reverse();
            printf("Reversed Linked List: ");
            traverse();
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
