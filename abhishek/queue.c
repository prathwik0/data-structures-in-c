#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;

    if (front == NULL && rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue()
{
    struct node *temp;
    temp = front;
    if (front == NULL && rear == NULL)
    {
        printf("empty\n");
    }
    else if (front == rear)
    {
        printf("%d", front->data);
        front = rear = NULL;
        free(temp);
    }
    else
    {
        printf("%d", front->data);
        front = front->next;
        free(temp);
    }
}

void display()
{
    struct node *temp;
    temp = front;
    if (front == NULL && rear == NULL)
    {
        printf("empty\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{

    int ch, x;

    while (1)
    {
        printf("enter the choice\n");
        printf("1.insert 2. delete 3.display\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter the element\n");
            scanf("%d", &x);
            enqueue(x);
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
    return 0;
}