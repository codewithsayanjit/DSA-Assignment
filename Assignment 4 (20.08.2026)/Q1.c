/*
Bank account keeping the transaction amount as it is processed by customer.
THe transaction amount of last customer is stores at top position after completion of all transaction, the manager pull the amount one by one and display the amount and find total-transaction-amount to print define following funstion:
push(): to insert amount in
pop(): to remove amount
dosum(): find sum of all transaction amount

AMOUNT INSERTED IN FOLLOWING ORDER:
1050,2090,3000,6000,5500,8900
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

/* PUSH operation */
void push(int amount)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    else
    {
        top = top + 1;
        stack[top] = amount;
    }

    printf("Transaction amount %d pushed into stack.\n", amount);
}

/* POP operation */
int pop()
{
    int amount;

    if (top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        amount = stack[top];
        top = top - 1;

        printf("Transaction amount %d is removed from stack.\n", amount);

        return amount;
    }
}

/* DOSUM operation */
void dosum()
{
    int sum = 0;
    int amount;

    if (top == -1)
    {
        printf("Stack is empty.\n");
        return;
    }

    printf("\nTransaction amounts pulled from stack:\n");

    while (top != -1)
    {
        amount = pop();

        if (amount != -1)
        {
            printf("Amount = %d\n", amount);
            sum = sum + amount;
        }
    }

    printf("\nTotal Transaction Amount = %d\n", sum);
}

/* DISPLAY operation */
void display()
{
    int i;

    if (top == -1)
    {
        printf("Stack is empty.\n");
        return;
    }

    printf("\nCurrent Stack (Bottom -> Top):\n");

    for (i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }

    printf("\n");
}

int main()
{
    int choice;
    int amount;

    while (1)
    {
        printf("\nEnter Your Choice:\n");
        printf("1 : Push Transaction Amount\n");
        printf("2 : Pop Transaction Amount\n");
        printf("3 : Find Total Transaction Amount\n");
        printf("4 : Display Stack\n");
        printf("5 : Exit\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter Transaction Amount: ");
            scanf("%d", &amount);

            push(amount);
            break;

        case 2:
            pop();
            break;

        case 3:
            dosum();
            break;

        case 4:
            display();
            break;

        case 5:
            printf("Program terminated.\n");
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
