/*
A single Screen Cinema hall has one ticket counter . One customer arrives at a time .
The requirements :
1.Add Customers
2.Serve Customers
3.Show "Housefull" if the seats are full
4.Display all the customers

Sample input:
Customer Ids:
100
115
095
086
*/

#include <stdio.h>

#define MAX 4

int Q[MAX];
int Rear = -1;
int Front = -1;

/* ENQUEUE operation */
void enqueue(int item)
{
    if (Rear == MAX - 1)
    {
        printf("Housefull\n");
        return;
    }

    Rear = Rear + 1;
    Q[Rear] = item;

    printf("Customer %d added\n", item);
}

/* DEQUEUE operation */
int dequeue()
{
    int x;

    if (Rear == Front || Front == MAX - 1)
    {
        printf("Queue is underflow\n");
        return -1;
    }

    Front = Front + 1;
    x = Q[Front];

    return x;
}

/* DISPLAY operation */
void display()
{
    int i;

    if (Rear == Front)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("\nCustomers in Queue:\n");

    for (i = Front + 1; i <= Rear; i++)
    {
        printf("%d ", Q[i]);
    }

    printf("\n");
}

int main()
{
    /* Add Customers */
    enqueue(100);
    enqueue(115);
    enqueue(95);
    enqueue(86);

    /* Display all customers */
    display();

    /* Serve Customer */
    printf("\nServed Customer: %d\n", dequeue());

    /* Display remaining customers */
    display();

    return 0;
}
