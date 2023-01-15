#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    struct NODE *left;
    struct NODE *right;
    int data;
} *node;

node getNode(int data)
{
    node n = (struct NODE *)malloc(sizeof(struct NODE));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void preorder(node root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(node root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void inorder(node root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main()
{
    node root;

    root = getNode(100);

    root->left = getNode(8);
    root->right = getNode(14);

    root->left->left = getNode(5);
    root->left->right = getNode(11);
    root->left->left->left = getNode(1);
    root->left->left->right = getNode(6);

    // root->left->right->left = getNode(9);
    // root->left->right->left->right = getNode(10);
    // root->left->right->right = getNode(12);
    // root->right->right = getNode(145);

    //                 (100)
    //            /            \
    //         (8)              (14)
    //       /      \          /    \
    //    (5)        (11)     (-)    (145)
    //   /   \      /   \
    // (1)   (6)  (9)  (12)
    //              \
    //              (10)

    printf("\nInorder:   ");
    inorder(root);

    printf("\nPreorder:   ");
    preorder(root);

    printf("\nPostorder:   ");
    postorder(root);

    return 0;
}