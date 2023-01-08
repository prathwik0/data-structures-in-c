#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct NODE
{
    struct NODE *left;
    struct NODE *right;
    int data;
} *node;

node getNode(int data)
{
    node temp = (struct NODE *)malloc(sizeof(struct NODE));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
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

void levelorder(node root)
{
    queue q;
    q.front = NULL;
    q.rear = NULL;

    while (root)
    {
        printf("%d ", root->data);
        if (root->left)
            enqueue(&q, root->left);
        if (root->right)
            enqueue(&q, root->right);

        root = dequeue(&q);
    }
}

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

    return 0;
}