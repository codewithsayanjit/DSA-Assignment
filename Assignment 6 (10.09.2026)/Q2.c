/*
10/09/2026
A basic Calculator needs to evaluate expression already written in postfix from.
Requirements:
1.Evaluate given postfix expression
Input: 6 2 + 3 *
*/

#include <stdio.h>
#include <string.h>

int st[100];
int top = -1;

void push(int n)
{
    top++;
    st[top] = n;
}

int pop()
{
    int n;
    n = st[top];
    top--;
    return n;
}

int operation(int a, int b, char op)
{
    if (op == '+')
        return a + b;

    if (op == '-')
        return a - b;

    if (op == '*')
        return a * b;

    if (op == '/')
        return a / b;

    return 0;
}

void evaluate(char Q[])
{
    int i, a, b, result;
    int len = strlen(Q);

    for (i = 0; i < len; i++)
    {
        if (Q[i] == ' ')
            continue;

        if (Q[i] >= '0' && Q[i] <= '9')
        {
            push(Q[i] - '0');
        }
        else
        {
            b = pop();
            a = pop();

            result = operation(a, b, Q[i]);

            push(result);
        }
    }

    result = pop();

    printf("Result = %d", result);
}

int main()
{
    char Q[100];

    printf("Enter Postfix Expression: ");
    gets(Q);

    evaluate(Q);

    return 0;
}
