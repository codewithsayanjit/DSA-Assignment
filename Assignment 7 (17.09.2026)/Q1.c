/*
* 17/09/2026
In a shop the Product prices of 5 products are stored in a list.
The price is stored in a float/double .
Each node of list consist of price of one product and address of next.
Perform the following operation on the list in menu driven form.
option 1: Create List
option 2: Traverse list
option 3: Search one price in list taken input from user
option 4: Insert the price of new at the head
option 5: Insert the Price of new item at 3rd position of list.

Sample:
List : 50.5->20.25->13.5->18.5->41.25
at head insert 65.25
at position 3 insert 102.50
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct st
{
    float n;
    struct st *next;
} link;

link *head = NULL;

// Function for creating a node
void create(float data)
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
        printf("%.2f -> ", temp->n);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Function for searching an item
void search(float item)
{
    link *temp;

    temp = head;

    while (temp != NULL)
    {
        if (temp->n == item)
        {
            printf("Found\n");
            return;
        }
        else
        {
            temp = temp->next;
        }
    }

    printf("Not Found\n");
}

// Function for inserting at head
void insert_head(float item)
{
    link *ptr;

    ptr = (link *)malloc(sizeof(link));

    ptr->next = head;
    ptr->n = item;

    head = ptr;
}

// Function for inserting at 3rd position
void insert_pos3(float item)
{
    link *ptr, *temp;
    int i = 1;

    ptr = (link *)malloc(sizeof(link));

    ptr->next = NULL;
    ptr->n = item;

    temp = head;

    /* Move temp to 2nd node */
    while (i < 2 && temp != NULL)
    {
        temp = temp->next;
        i = i + 1;
    }

    if (temp == NULL)
    {
        printf("Cannot insert at 3rd position\n");
        free(ptr);
        return;
    }

    ptr->next = temp->next;
    temp->next = ptr;
}

int main()
{
    int choice;
    float data;

    while (1)
    {
        printf("\n1. Create List");
        printf("\n2. Traverse List");
        printf("\n3. Search Price");
        printf("\n4. Insert Price at Head");
        printf("\n5. Insert Price at 3rd Position");
        printf("\n6. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter price: ");
            scanf("%f", &data);

            create(data);
            break;

        case 2:
            printf("Linked List: ");
            traverse();
            break;

        case 3:
            printf("Enter price to search: ");
            scanf("%f", &data);

            search(data);
            break;

        case 4:
            printf("Enter new price: ");
            scanf("%f", &data);

            insert_head(data);
            break;

        case 5:
            printf("Enter new price: ");
            scanf("%f", &data);

            insert_pos3(data);
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
