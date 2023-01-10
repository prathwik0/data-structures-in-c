#include <stdlib.h> // for NULL and malloc
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

int getHeight(node root)
{
    if (root == NULL)
    {
        return 0;
    }
    return root->height;
}

int getHeightRecursive(node root)
{
    if (root == NULL)
    {
        return 0;
    }

    int x = getHeightRecursive(root->left);
    int y = getHeightRecursive(root->right);

    return x > y ? x + 1 : y + 1;
}

void updateHeight(node root)
{
    int a = getHeight(root->left);
    int b = getHeight(root->right);
    root->height = a > b ? a + 1 : b + 1;
}
