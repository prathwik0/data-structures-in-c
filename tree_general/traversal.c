#include <stdio.h>
#include "treeNode.h"
#include "queue.h"

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