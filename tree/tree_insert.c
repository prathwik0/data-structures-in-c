#include <stdio.h>
#include <stdlib.h>
#include "print2D.h"

node return_node(int data)
{
    node x = (struct NODE *)malloc(sizeof(struct NODE));
    x->left = NULL;
    x->data = data;
    x->right = NULL;
    return x;
}

void insert_node(node *x, int data)
{
    *x = (struct NODE *)malloc(sizeof(struct NODE));
    (*x)->left = NULL;
    (*x)->data = data;
    (*x)->right = NULL;
}

void inorder(node root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int get_height(node root)
{
    if (root == NULL)
    {
        return 0;
    }

    int x = get_height(root->left);
    int y = get_height(root->right);

    return x > y ? x + 1 : y + 1;
}

void insert_without_arranging(node *root, int data)
{
    if (*root == NULL)
    {
        *root = return_node(data);
        return;
    }

    if ((*root)->data > data)
    {
        insert_without_arranging(&((*root)->left), data);
    }
    else
    {
        insert_without_arranging(&((*root)->right), data);
    }
}

void arrange(node *root);
void clockwise_rotate(node *root);
void anticlockwise_rotate(node *root);

void insert_with_arranging(node *root, int data)
{
    if (*root == NULL)
    {
        *root = return_node(data);
        return;
    }

    if ((*root)->data > data)
    {
        insert_with_arranging(&((*root)->left), data);
    }
    else
    {
        insert_with_arranging(&((*root)->right), data);
    }

    arrange(root);
}

void arrange(node *root)
{
    int l = get_height((*root)->left);
    int r = get_height((*root)->right);

    if (l - r == 0 || l - r == 1 || l - r == -1)
    {
        return;
    }

    if (r > l)
    {
        if (get_height((*root)->right->right) > get_height((*root)->right->left))
        {
            anticlockwise_rotate(root);
        }
        else
        {
            clockwise_rotate(&((*root)->right));
            anticlockwise_rotate(root);
        }
    }

    if (l > r)
    {
        if (get_height((*root)->left->left) > get_height((*root)->left->right))
        {
            clockwise_rotate(root);
        }
        else
        {
            anticlockwise_rotate(&((*root)->left));
            clockwise_rotate(root);
        }
    }
}

void clockwise_rotate(node *root)
{
    node temp = (*root)->left->right;

    (*root)->left->right = *root;
    *root = (*root)->left;

    (*root)->right->left = temp;
}

void anticlockwise_rotate(node *root)
{
    node temp = (*root)->right->left;

    (*root)->right->left = *root;
    *root = (*root)->right;

    (*root)->left->right = temp;
}