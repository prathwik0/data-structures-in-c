#include <stdio.h>
#include "insert.h"
#include "data.h"
#include "treeNode.h"

void insertUnbalanced(node *root, void *data_ptr)
{
    if (*root == NULL)
    {
        *root = getNode(data_ptr);
        return;
    }
    if (datacmp((*root)->ptr, data_ptr) == 0)
    {
        return;
    }
    if (datacmp((*root)->ptr, data_ptr) == 1)
    {
        insertUnbalanced(&((*root)->left), data_ptr);
        updateHeight(*root);
    }
    else
    {
        insertUnbalanced(&((*root)->right), data_ptr);
        updateHeight(*root);
    }
}

void balance(node *root);
void clockwiseRotate(node *root);
void antiClockwiseRotate(node *root);

void insert(node *root, void *data_ptr)
{
    if (*root == NULL)
    {
        *root = getNode(data_ptr);
        return;
    }
    if (datacmp((*root)->ptr, data_ptr) == 0)
    {
        return;
    }
    if (datacmp((*root)->ptr, data_ptr) == 1)
    {
        insert(&((*root)->left), data_ptr);
        updateHeight(*root);
    }
    else
    {
        insert(&((*root)->right), data_ptr);
        updateHeight(*root);
    }

    balance(root);
}

void balance(node *root)
{
    int l = getHeight((*root)->left);
    int r = getHeight((*root)->right);

    if (l - r == 0 || l - r == 1 || l - r == -1)
    {
        return;
    }

    if (r > l)
    {
        if (getHeight((*root)->right->right) > getHeight((*root)->right->left))
        {
            antiClockwiseRotate(root);
        }
        else
        {
            clockwiseRotate(&((*root)->right));
            antiClockwiseRotate(root);
        }
    }

    if (l > r)
    {
        if (getHeight((*root)->left->left) > getHeight((*root)->left->right))
        {
            clockwiseRotate(root);
        }
        else
        {
            antiClockwiseRotate(&((*root)->left));
            clockwiseRotate(root);
        }
    }
}

void clockwiseRotate(node *root)
{
    node temp = (*root)->left->right;

    (*root)->left->right = *root;
    *root = (*root)->left;

    (*root)->right->left = temp;

    updateHeight((*root)->right);
    updateHeight((*root));
}

void antiClockwiseRotate(node *root)
{
    node temp = (*root)->right->left;

    (*root)->right->left = *root;
    *root = (*root)->right;

    (*root)->left->right = temp;

    updateHeight((*root)->left);
    updateHeight((*root));
}
