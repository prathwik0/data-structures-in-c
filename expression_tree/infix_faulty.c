#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tree.h"
#include "stack.h"

int getPrecedence(char ch);

int main()
{
    char *expression = "a+c*d^e*f";
    char *ptr = expression;

    stack s1, s2;

    s1.front = NULL;
    s2.front = NULL;

    while (*ptr != '\0')
    {
        // is *ptr is alnum, push to stack1
        if (isalnum(*ptr))
        {
            node root = getNode(*ptr);
            push(&s1, root);
        }
        // if *ptr is operator, check the following conditions
        else
        {
            node operator= peek(&s2);

            // if no operator in stack2, push *ptr to stack2
            if (operator== NULL)
            {
                node root = getNode(*ptr);
                push(&s2, root);
            }
            else if (getPrecedence(*ptr) > getPrecedence(operator->c))
            {
                node root = getNode(*ptr);
                push(&s2, root);
            }
            else if (getPrecedence(*ptr) == getPrecedence(operator->c))
            {
                node root = pop(&s2);

                root->right = pop(&s1);
                root->left = pop(&s1);

                push(&s1, root);

                node root2 = getNode(*ptr);
                push(&s2, root2);
            }
            else
            {
                node root = pop(&s2);

                while (root != NULL)
                {
                    root->right = pop(&s1);
                    root->left = pop(&s1);

                    push(&s1, root);

                    root = pop(&s2);
                }

                node root2 = getNode(*ptr);
                push(&s2, root2);
            }
        }

        ptr++;
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
    if (ch == '/' || ch == '*')
    {
        return 2;
    }
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    return 0;
}
