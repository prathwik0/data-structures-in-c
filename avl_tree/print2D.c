#include <stdio.h>
#include "treeNode.h"
#include "print2D.h"
#include "data.h"

void print2DUtil(node root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printdata(root->ptr);

    // Process left child
    print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void print2D(node root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
    printf("\n\n");
}
