#include <stdio.h>
#include "insert.h"
#include "treeNode.h"

void insert(node *root, int data)
{
    if (*root == NULL)
    {
        *root = getNode(data);
        return;
    }

    if ((*root)->data == data)
    {
        return;
    }

    if ((*root)->data > data)
    {
        insert(&((*root)->left), data);
    }
    else
    {
        insert(&((*root)->right), data);
    }
}