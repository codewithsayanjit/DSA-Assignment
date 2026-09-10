/*
03/09/2026
Infix to postfix Conversion using stack

A simple Calculator Recives an infix expression It must:
-> Convert infix expression to postfix
Sample input: 3+4*5
*/

#include <stdio.h>
#include <string.h>

char st[100];
int top = -1;

int precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    if (c == '^')
        return 3;
    return 0;
}

void push(char c)
{
    top++;
    st[top] = c;
}

char pop()
{
    char c = st[top];
    top--;
    return c;
}

void infixtopostfix(char Q[], char P[])
{
    int len, i = 0, j = 0;

    len = strlen(Q);
    Q[len] = ')';
    Q[len + 1] = '\0';

    push('(');

    for (i = 0; i < len + 1; i++)
    {
        if ((Q[i] >= '0' && Q[i] <= '9') ||
            (Q[i] >= 'A' && Q[i] <= 'Z') ||
            (Q[i] >= 'a' && Q[i] <= 'z'))
        {
            P[j] = Q[i];
            j++;
        }
        else if (Q[i] == '(')
        {
            push(Q[i]);
        }
        else if (Q[i] == ')')
        {
            while (st[top] != '(')
            {
                P[j] = pop();
                j++;
            }
            pop();
        }
        else
        {
            while (precedence(st[top]) >= precedence(Q[i]))
            {
                P[j] = pop();
                j++;
            }
            push(Q[i]);
        }
    }

    P[j] = '\0';
}

int main()
{
    char Q[100], P[100];

    printf("Enter Infix Expression: ");
    gets(Q);

    infixtopostfix(Q, P);

    printf("Postfix Expression: %s\n", P);

    return 0;
}
