#include <stdio.h>

#include <stdlib.h>
#define size 5

int q[size], rear = -1, front = 0, totalelements = 0;

void insert(int element)
{
    if (totalelements == size)
    {
        printf("Queue is full");
    }
    else
    {
        rear = (rear + 1) % size;
        q[rear] = element;
        totalelements = totalelements + 1;
    }
}

void delete()
{
    if (totalelements == 0)
    {
        printf("Queue is empty");
        // pause the loop to see the message
    }
    else
    {
        printf("Number Deleted = %d", q[front]);
        front = (front + 1) % size;
        totalelements = totalelements - 1;
        // pause the loop to see the number
    }
}

void display()
{
    if (totalelements == 0)
    {
        printf("Queue is empty");
        // pause the loop to see the message
    }
    else
    {
        int x = front;
        for (int i = 1; i <= totalelements; i++)
        {
            printf("%d ", q[x]);
            x = (x + 1) % size;
        }
        // pause the loop to see the numbers
    }
}
int main()
{
    int ch, n;
    while (1) // An infinite loop
    {
        // for clearing the screen
        printf("\n1. Add\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter a number ");
            scanf("%d", &n);
            insert(n);
            break;

        case 2:
            delete ();
            break;

        case 3:
            display(); // pause the loop to see the numbers
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("Wrong Choice");
            // pause the loop to see the message
        }
    }
    return 0;
}