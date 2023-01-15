#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *next;
    int data;
};

struct node *top = NULL;

void push(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

void pop()
{
    struct node *temp;
    temp = top;
    if (top == 0)
    {
        printf("empty\n");
    }
    else
    {
        printf("%d\n", top->data);
        top = top->next;
        free(temp);
    }
}

void display()
{
    struct node *temp;
    temp = top;
    if (top == 0)
    {
        printf("empty\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    int ch;
    int x;
    while (1)
    {
        printf("enter the choice\n");
        printf("1.INSERT 2.DELETE 3.DISPLAY\n");
        scanf("%d", &ch);
        printf("\n");
        switch (ch)
        {
        case 1:
            printf("enter a data\n");
            scanf("%d", &x);
            push(x);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;

        default:
            printf("wrong choice\n");
        }
    }
    return 0;
}