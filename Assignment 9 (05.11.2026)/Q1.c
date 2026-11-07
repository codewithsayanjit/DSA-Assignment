/*
Write a menu driven program in C to perform the following operations on a Doubly Linked List.

a) Create List
b) Traverse list in forward and reverse order
c) Insert a node at p-th position
d) Delete a node from p-th position
e) Search a specific item in the list
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

    if (ptr == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

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

// INSERT NODE AT P-TH POSITION
void insert(int item, int pos)
{
    link *temp, *ptr, *new;

    new = (link *)malloc(sizeof(link));

    if (new == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    new->n = item;
    new->next = NULL;
    new->prev = NULL;

    // Insert at first position
    if (pos == 1)
    {
        new->next = head;

        if (head != NULL)
            head->prev = new;
        else
            tail = new;

        head = new;

        return;
    }

    temp = head;

    int loc = 1;

    while (loc < pos - 1 && temp != NULL)
    {
        temp = temp->next;
        loc = loc + 1;
    }

    if (temp == NULL)
    {
        printf("Invalid Position\n");
        free(new);
        return;
    }

    new->next = temp->next;

    temp->next = new;

    new->prev = temp;

    ptr = new->next;

    if (ptr != NULL)
        ptr->prev = new;
    else
        tail = new;
}

// DELETE NODE FROM P-TH POSITION
void del_node(int pos)
{
    int loc;
    link *temp = head, *ptr;

    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    if (pos < 1)
    {
        printf("Invalid Position\n");
        return;
    }

    // Delete first node
    if (pos == 1)
    {
        ptr = head;

        head = head->next;

        if (head != NULL)
            head->prev = NULL;
        else
            tail = NULL;

        free(ptr);

        return;
    }

    loc = 1;

    while (loc < pos - 1 && temp != NULL)
    {
        loc = loc + 1;
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)
    {
        printf("Invalid Position\n");
        return;
    }

    ptr = temp->next;

    temp->next = ptr->next;

    if (ptr->next != NULL)
        ptr->next->prev = temp;
    else
        tail = temp;

    free(ptr);
}

// SEARCH FUNCTION
void search(int item)
{
    int pos = 1;
    link *temp;

    temp = head;

    while (temp != NULL)
    {
        if (temp->n == item)
        {
            printf("Found item at %d th position in Forward Traverse\n",
                   pos);
            return;
        }

        temp = temp->next;
        pos = pos + 1;
    }

    printf("Item Not Found\n");
}

int main()
{
    int choice, item, pos, n, i;

    do
    {
        printf("1. Create List\n");
        printf("2. Forward Traverse\n");
        printf("3. Backward Traverse\n");
        printf("4. Insert at P-th Position\n");
        printf("5. Delete from P-th Position\n");
        printf("6. Search an Item\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            printf("Enter number of nodes: ");
            scanf("%d", &n);

            for (i = 1; i <= n; i++)
            {
                printf("Enter data: ");
                scanf("%d", &item);
                create(item);
            }
            break;

        case 2:

            printf("Forward Traverse: ");
            traverse();
            break;

        case 3:

            printf("Backward Traverse: ");
            backward();
            break;

        case 4:

            printf("Enter item: ");
            scanf("%d", &item);

            printf("Enter position: ");
            scanf("%d", &pos);

            insert(item, pos);

            printf("After Insertion (Forward): ");
            traverse();

            printf("After Insertion (Backward): ");
            backward();

            break;

        case 5:

            printf("Enter position to delete: ");
            scanf("%d", &pos);

            del_node(pos);

            printf("After Deletion (Forward): ");
            traverse();

            printf("After Deletion (Backward): ");
            backward();

            break;

        case 6:

            printf("Enter item to search: ");
            scanf("%d", &item);

            search(item);

            break;

        case 7:

            printf("Exit\n");
            break;

        default:

            printf("Invalid Choice\n");
        }

    } while (choice != 7);

    return 0;
}
