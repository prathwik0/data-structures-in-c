#ifndef QUEUE_H
#define QUEUE_H

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

void preorder(node root);
void postorder(node root);
void inorder(node root);

void levelorder(node root);

#endif