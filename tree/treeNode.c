#include <stdlib.h>
#include "treeNode.h"

node getNode(int data)
{
    node temp = (struct NODE *)malloc(sizeof(struct NODE));
    temp->data = data;
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

    int x = get_height(root->left);
    int y = get_height(root->right);

    return x > y ? x + 1 : y + 1;
}