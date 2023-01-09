#include <stdio.h>
#include <stdlib.h>
#define N 5

int queue[N];
int rear = -1;
int front = -1;

void insert(int x)
{
    if (rear == N - 1)
    {
        printf("full");
    }
    else if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = x;
    }
    else
    {
        rear++;
        printf("rear = %d\n", rear);
        queue[rear] = x;
    }
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void sort()
{
    for (int i = front; i < rear; i++)
    {
        for (int j = i + 1; j <= rear; j++)
        {
            if (queue[j] < queue[i])
            {
                swap(&queue[j], &queue[i]);
            }
        }
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("empty");
    }
    else if (front == rear)
    {
        printf("%d\n", queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("%d\n", queue[front]);
        front++;
    }
}

void display()
{
    int i;

    if (front == -1 && rear == -1)
    {
        printf("empty");
    }
    else
    {
        for (i = front; i < rear + 1; i++)
        {
            printf("%d\n", queue[i]);
        }
    }
}

void main()
{
    int ch, x;

    while (1)
    {
        printf("1.INSERT \n 2.DEQUEUE \n 3. DISPLAY\n");
        scanf("%d", &ch);
        switch (ch)
        {

        case 1:
            printf("enter the elemebnt: ");
            scanf("%d", &x);
            insert(x);
            sort();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        default:
            printf("wrong operation");
        }
    }
}