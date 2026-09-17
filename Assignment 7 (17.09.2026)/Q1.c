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
    double price;
    struct st *next;
} link;

link *head = NULL;

// Option 1: Create List 
void create(double price)
{
    link *ptr, *temp;

    ptr = (link *)malloc(sizeof(link));

    if (ptr == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    ptr->price = price;
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

// Option 2: Traverse List */
void traverse()
{
    link *temp = head;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%.2lf", temp->price);

        if (temp->next != NULL)
            printf(" -> ");

        temp = temp->next;
    }

    printf("\n");
}

// Option 3: Search a price
void search(double item)
{
    link *temp = head;

    while (temp != NULL)
    {
        if (temp->price == item)
        {
            printf("Price %.2lf found in the list.\n", item);
            return;
        }

        temp = temp->next;
    }

    printf("Price %.2lf not found in the list.\n", item);
}

// Option 4: Insert price at Head 
void insertHead(double item)
{
    link *ptr;

    ptr = (link *)malloc(sizeof(link));

    if (ptr == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    ptr->price = item;
    ptr->next = head;
    head = ptr;

    printf("%.2lf inserted at head.\n", item);
}

//  Option 5: Insert price at 3rd Position 
void insertThird(double item)
{
    link *ptr, *temp;
    int i;

    //  A 3rd-position insertion needs at least 2 nodes 
    if (head == NULL || head->next == NULL)
    {
        printf("At least 2 nodes are required.\n");
        return;
    }

    ptr = (link *)malloc(sizeof(link));

    if (ptr == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    ptr->price = item;

    temp = head;

    // Move to 2nd node
    for (i = 1; i < 2; i++)
    {
        temp = temp->next;
    }

    // Insert new node at 3rd position
    ptr->next = temp->next;
    temp->next = ptr;

    printf("%.2lf inserted at 3rd position.\n", item);
}

int main()
{
    int choice, i;
    double price;

    while (1)
    {
        printf("1. Create List\n");
        printf("2. Traverse List\n");
        printf("3. Search Price\n");
        printf("4. Insert Price at Head\n");
        printf("5. Insert Price at 3rd Position\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter price: ");
            scanf("%lf", &price);
            create(price);
            break;

        case 2:
            printf("Product Price List: ");
            traverse();
            break;

        case 3:
            printf("Enter price to search: ");
            scanf("%lf", &price);
            search(price);
            break;

        case 4:
            printf("Enter new price: ");
            scanf("%lf", &price);
            insertHead(price);
            break;

        case 5:
            printf("Enter new price: ");
            scanf("%lf", &price);
            insertThird(price);
            break;

        case 6:
            printf("Program ended.\n");
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
