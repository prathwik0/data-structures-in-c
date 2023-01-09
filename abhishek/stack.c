#include <stdio.h>
#include <stdlib.h>

#define N 5
int stack[N];
int top = -1;

void push(int x)
{
    if (top == N - 1)
    {
        printf("full");
    }
    else
    {
        top = top + 1;
        stack[top] = x;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("empty");
    }
    else
    {
        printf("%d", stack[top]);
        top--;
    }
}

void display()
{
    int i;

    if (top == -1)
    {
        printf("empty\n");
    }
    else
    {
        for (i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
    }
    printf("\n");
}
int main()
{
    int ch, data;
    while (1)
    {
        printf("1.PUSH \n 2.POP \n 3.DISPLAY\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter the element: ");
            scanf("%d", &data);
            printf("\n%d", data);
            push(data);
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