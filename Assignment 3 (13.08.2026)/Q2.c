/*
Consider a barkrack ,where the books are placed in Stack.Each book has acc_no (1,2,3,...).If you are asked to place book in stack using acc_no and take the book from stack using acc_no ,how you perform these two operations on stack of books.The sequence of opertaion is given here.
-- PUSH(1),PUSH(2),PUSH(3),POP(3),PUSH(4),PUSH(5),POP(5)
-- Display the final position of the stack.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

//* PUSH operation
void push(int acc_no)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    else
    {
        top = top + 1;
        stack[top] = acc_no;
    }

    printf("Book %d pushed into stack.\n", acc_no);
}

//* POP operation
void pop(int acc_no)
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }
    else if (stack[top] != acc_no)
    {
        printf("Book %d cannot be popped because it is not at the top.\n",
               acc_no);
        return;
    }
    else
    {
        printf("Book %d is taken away from stack.\n", stack[top]);
        top = top - 1;
    }
}

//* Display stack
void display()
{
    int i;

    if (top == -1)
    {
        printf("Stack is empty.\n");
        return;
    }

    printf("\nFinal Stack (Bottom -> Top):\n");

    for (i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }

    printf("\n");
}

int main()
{
    int choice, acc_no;

    while (1)
    {
        printf("\nEnter Your choice :\n");
        printf("1 : Push\n");
        printf("2 : Pop\n");
        printf("3 : Exit and Display Final Stack\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter acc_no to be pushed : ");
            scanf("%d", &acc_no);
            push(acc_no);
            break;

        case 2:
            printf("Enter acc_no to be popped : ");
            scanf("%d", &acc_no);
            pop(acc_no);
            break;

        case 3:
            display();
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
