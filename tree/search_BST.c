#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    struct NODE *left;
    struct NODE *right;
    int data;
} *node;

node newNode(int data)
{
    node temp = (struct NODE *)malloc(sizeof(struct NODE));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
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

node rsearch(node n, int key)
{
    if (n == NULL)
    {
        return NULL;
    }
    if (key == n->data)
    {
        return n;
    }

    if (key < n->data)
    {
        return rsearch(n->left, key);
    }
    else
    {
        return rsearch(n->right, key);
    }
}

int main()
{
    node root;
    int x;

    root = newNode(3);
    root->left = newNode(1);
    root->right = newNode(5);
    root->left->left = newNode(0);
    root->left->right = newNode(2);

    //            (3)
    //          /     \
    //       (1)      (5)
    //      /   \      /  \
    //    (0)   (2)  (-)  (-)

    node temp = rsearch(root, 5);
    if (temp != NULL)
    {
        printf("Search for 5: rsearch -- %d", temp->data);
    }

    printf("\nInorder:   ");
    inorder(root);

    return 0;
}