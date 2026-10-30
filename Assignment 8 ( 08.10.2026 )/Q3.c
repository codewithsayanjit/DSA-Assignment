/*
29/10/2026
(Doubly Linked list problem statement 2)
Q.8.3.
Consider an existing doubly linked list
6 <-> 2 <-> 8 <-> 4

write a function to insert node with value 12 between 2nd and 3rd node
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
        tail = ptr;
    }
    else
    {
        temp = tail;

        temp->next = ptr;
        ptr->prev = temp;

        tail = ptr;
    }
}

void insert(int item, int pos)
{
    link *temp, *ptr, *new;

    new = (link *)malloc(sizeof(link));

    new->n = item;
    new->next = NULL;
    new->prev = NULL;

    temp = head;

    int loc = 1;

    while (loc < pos - 1)
    {
        temp = temp->next;
        loc = loc + 1;
    }

    new->next = temp->next;

    temp->next = new;

    ptr = new->next;

    ptr->prev = new;

    new->prev = temp;
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
    // Create existing doubly linked list
    create(6);
    create(2);
    create(8);
    create(4);

    printf("Original List: ");
    traverse();

    // Insert 12 at position 3
    insert(12, 3);

    printf("After Insertion (Forward): ");
    traverse();

    printf("After Insertion (Backward): ");
    backward();

    return 0;
}
