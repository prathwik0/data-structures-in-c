#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int top = -1;
char stack[100];

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    if (top == -1)
    {
        return -1;
    }
    return stack[top--];
}

char peek()
{
    if (top == -1)
    {
        return -1;
    }
    return stack[top];
}

int precedence(char ch);

int main()
{
    char *expression = "a+c*d^e*f";
    char *ch = expression, temp;

    while (*ch != '\0')
    {
        if (isalnum(*ch))
        {
            printf("%c ", *ch);
        }
        else if (*ch == '(')
        {
            push(*ch);
        }
        else if (*ch == ')')
        {
            while ((temp = pop()) != '(')
            {
                printf("%c ", temp);
            }
        }
        else
        {
            while (precedence(peek()) >= precedence(*ch))
            {
                printf("%c ", pop());
            }
            push(*ch);
        }

        ch++;
    }
    while (top != -1)
    {
        printf("%c ", pop());
    }

    return 0;
}

int precedence(char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    if (ch == '*' || ch == '/')
    {
        return 2;
    }
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    if (ch == '(')
    {
        return 0;
    }
    return 0;
}