#include <stdio.h>
#include "print2D.h"
#include "treeNode.h"

/*
 *prints the nodes in 2d using inverse postorder traversal
 */
void print2Dutility(node root, int space)
{
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    print2Dutility(root->right, space);

    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d", root->data);

    print2Dutility(root->left, space);
}

// Wrapper over print2Dutility
() void print2D(node *root)
{
    // Pass initial space count as 0
    print2Dutility(root, 0);
}
