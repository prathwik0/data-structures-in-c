#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct
{
    int top;
    char *a;
} stack;

void push(stack *s, char ch)
{
    s->a[++(s->top)] = ch;
}

char pop(stack *s)
{
    if (s->top == -1)
    {
        return '0';
    }

    return s->a[(s->top)--];
}

char peek(stack *s)
{
    if (s->top == -1)
    {
        return '0';
    }

    return s->a[(s->top)];
}

int precedence(char ch);

int main()
{
    char *expression = "k-l-m*n+(o*p)*w/u/v*t+q";
    char *ch = expression;

    stack s;
    s.top = -1;
    s.a = (char *)malloc(sizeof(char) * 20);

    while (*ch != '\0')
    {
        // if alnum, print
        if (isalnum(*ch))
        {
            printf("%c ", *ch);
        }
        // if opening brackt push to stak
        else if (*ch == '(')
        {
            push(&s, *ch);
        }
        else if (*ch == ')')
        {
            char temp = pop(&s);
            while (temp != '(')
            {
                printf("%c ", temp);
                temp = pop(&s);
            }
        }
        // if stack empty push to stack
        else if (peek(&s) == '0')
        {
            push(&s, *ch);
        }
        else
        {
            char operator= peek(&s);

            if (precedence(operator) < precedence(*ch))
            {
                push(&s, *ch);
            }
            else if (precedence(operator) == precedence(*ch))
            {
                printf("%c ", pop(&s));
                push(&s, *ch);
            }
            else
            {
                char temp = pop(&s);
                while (temp != '0')
                {
                    if (temp == '(')
                    {
                        push(&s, '(');
                        break;
                    }
                    printf("%c ", temp);
                    temp = pop(&s);
                }
                push(&s, *ch);
            }
        }

        ch++;
    }

    char temp = pop(&s);
    while (temp != '0')
    {
        printf("%c ", temp);
        temp = pop(&s);
    }

    return 0;
}

int precedence(char ch)
{
    if (ch == '(')
    {
        return 4;
    }
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
    return 0;
}