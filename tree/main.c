#include <stdio.h>
#include "treeNode.h"
#include "traversal.h"
#include "print2D.h"

int main()
{
    node root;
    int x;

    root = getNode(3);
    root->left = getNode(2);
    root->right = getNode(5);
    root->left->left = getNode(1);
    root->left->right = getNode(4);
    root->left->left->left = getNode(10);
    root->left->left->right = getNode(11);
    root->left->right->left = getNode(12);
    root->left->right->right = getNode(13);

    //                 (3)
    //            /            \
    //         (2)              (5)
    //       /      \          /    \
    //    (1)        (4)     (-)     (-)
    //   /   \      /   \
    // (10) (11)  (12)  (13)

    printf("\nPreorder:   ");
    preorder(root);

    printf("\nPostorder:  ");
    postorder(root);

    printf("\nInorder:    ");
    inorder(root);

    printf("\nLevelorder: ");
    levelorder(root);

    printf("\n2D: ");
    print2D(root);

    return 0;
}