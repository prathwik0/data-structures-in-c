#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *next;
    int data;
};

struct node *top = 0;

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

    if (top == NULL)
    {
        printf("no element\n");
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
    if (top == NULL)
    {
        printf("no element\n");
        return;
    }

    while (temp != 0)
    {
        printf("%d", temp->data);
        temp = temp->next;
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
            push(x);
            break;
        case 2:
            pop();
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