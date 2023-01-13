#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tree.h"
#include "stack.h"

int getPrecedence(char ch);
void inorder(node root);
void postorder(node root);

int evaluate(node root);

int main()
{
    char *expression = "3-4*5*2-3*2";
    char *ptr = expression;

    stack s1, s2;

    s1.front = NULL;
    s2.front = NULL;

    while (*ptr != '\0')
    {
        if (isnumber(*ptr))
        {
            node root = getNode(*ptr);
            push(&s1, root);
        }
        else
        {
            node operator= peek(&s2);

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

    while (peek(&s2) != NULL)
    {
        node root = pop(&s2);

        root->right = pop(&s1);
        root->left = pop(&s1);

        push(&s1, root);
    }

    node root = pop(&s1);

    inorder(root);
    printf("\n");
    postorder(root);

    printf("\nEvaluated expression:\n");
    printf("%d\n", evaluate(root));

    return 0;
}

int getPrecedence(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else if (ch == '/' || ch == '*')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

void inorder(node root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    printf("%c ", root->c);
    inorder(root->right);
}

void postorder(node root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%c ", root->c);
}

int evaluate(node root)
{
    if (isnumber(root->c))
    {
        return (root->c) - 48;
    }

    char operator= root->c;

    int left = evaluate(root->left);
    int right = evaluate(root->right);

    printf("left - %d, right - %d \n", left, right);

    switch (operator)
    {
    case '+':
        return left + right;
    case '-':
        return left - right;
    case '*':
        return left * right;
    case '/':
        return left / right;
    default:
        return 0;
    }
}