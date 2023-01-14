#include <stdio.h>
#include <ctype.h>

int top = -1, stack[100];

void push(int n)
{
    stack[++top] = n;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char *expression = "245*+";
    char *e = expression;

    while (*e != '\0')
    {
        if (isdigit(*e))
        {
            push(*e - 48);
        }
        else
        {
            int n1 = pop();
            int n2 = pop();
            int n3;
            switch (*e)
            {
            case '+':
                n3 = n1 + n2;
                break;
            case '-':
                n3 = n2 - n1;
                break;
            case '*':
                n3 = n1 * n2;
                break;
            case '/':
                n3 = n2 / n1;
                break;
            }
            push(n3);
        }
        e++;
    }
    printf("result of %s is = %d\n", expression, pop());
    return 0;
}