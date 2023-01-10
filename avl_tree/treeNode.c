#include <stdlib.h>
#include "treeNode.h"

node getNode(void *data_ptr)
{
    node temp = (struct NODE *)malloc(sizeof(struct NODE));
    temp->ptr = data_ptr;
    temp->height = 1;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int get_height(node root)
{
    if (root == NULL)
    {
        return 0;
    }
    return root->height;
}