#include <stdio.h>
#include "insert.h"
#include "data.h"
#include "treeNode.h"

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
        insert(&((*root)->left), data);
    }
    else
    {
        insert(&((*root)->right), data);
    }
}