#include <stdio.h> //this is for NULL
#include "treeNode.h"
#include "delete.h"
#include "search.h"

void del(node *root)
{
    if (*root == NULL)
    {
        return;
    }

    if ((*root)->right == NULL)
    {
        *root = (*root)->left;
        return;
    }

    if ((*root)->left == NULL)
    {
        *root = (*root)->right;
        return;
    }

    // else -- find inorder successor and delete it
    node *successor = &((*root)->right);
    while ((*successor)->left != NULL)
    {
        successor = &((*successor)->left);
    }

    node temp = *successor;

    del(successor);

    temp->left = (*root)->left;
    temp->right = (*root)->right;
    *root = temp;
}

// wrapper over del
node delete(node *root, int key)
{
    node *temp = rsearchptr(root, key);
    node temp2 = *temp;
    del(temp);
    return temp2;
}