#include <stdlib.h> //needed for malloc
#include <stdio.h>  //needed for print
#include <ctype.h>  //needed for isnumber()
#include <math.h>   //needed for pow()
#include "tree.h"

node getNode(char c)
{
    node n = (struct NODE *)malloc(sizeof(struct NODE));
    n->c = c;
    n->left = NULL;
    n->right = NULL;
    return n;
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
    case '^':
        return pow(left, right);
    default:
        return 0;
    }
}