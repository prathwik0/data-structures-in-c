#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tree.h"
#include "stack.h"

int getPrecedence(char ch);

int main()
{
    char *expression = "a+c*d^e-f";
    char *ch = expression;

    stack s1, s2;

    s1.front = NULL;
    s2.front = NULL;

    while (*ch != '\0')
    {
        // is *ch is alnum, push to stack1
        if (isalnum(*ch))
        {
            node root = getNode(*ch);
            push(&s1, root);
        }
        // if *ch is an operator do the following
        else
        {
            node operator= peek(&s2);
            while (operator!= NULL && getPrecedence(*ch) <= getPrecedence(operator->c))
            {
                operator= pop(&s2);

                operator->right = pop(&s1);
                operator->left = pop(&s1);

                push(&s1, operator);

                operator= peek(&s2);
            }
            node root = getNode(*ch);
            push(&s2, root);
        }

        ch++;
    }

    // pop stack2 and finish building the expression tree
    while (peek(&s2) != NULL)
    {
        node root = pop(&s2);

        root->right = pop(&s1);
        root->left = pop(&s1);

        push(&s1, root);
    }

    // the final expression tree is the remaining element in stack1
    node root = pop(&s1);

    inorder(root);
    printf("\n");
    postorder(root);

    // printf("\nEvaluated expression:\n");
    // printf("%d\n", evaluate(root));

    return 0;
}

int getPrecedence(char ch)
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