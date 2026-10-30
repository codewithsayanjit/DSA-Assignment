/*
29/10/2026
Q.8.4.
consider an existing doubly linked list and delete an item from given position
2 <-> 6 <-> 9 <-> 13
Delete from position 3 and print resultant list
2 <-> 6 <-> 13
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

// Delete a node from given position
void del_node(int pos)
{
    int loc;
    link *temp = head, *ptr;

    loc = 1;

    while (loc < pos - 1)
    {
        loc = loc + 1;
        temp = temp->next;
    }

    ptr = temp->next;

    temp->next = ptr->next;

    ptr->next->prev = temp;

    free(ptr);
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
    create(2);
    create(6);
    create(9);
    create(13);

    printf("Original List: ");
    traverse();

    // Delete node at position 3
    del_node(3);

    printf("After Deletion (Forward): ");
    traverse();

    printf("After Deletion (Backward): ");
    backward();

    return 0;
}
