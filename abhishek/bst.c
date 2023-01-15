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

void insert(node *root, int data)
{
    if (*root == NULL)
    {
        *root = getNode(data);
        return;
    }
    if ((*root)->data == data)
    {
        return;
    }
    if ((*root)->data > data)
    {
        insert(&((*root)->left), data);
    }
    else
    {
        insert(&((*root)->right), data);
    }
}

node rsearch(node root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (data == root->data)
    {
        return root;
    }
    if (data < root->data)
    {
        return rsearch(root->left, data);
    }
    else
    {
        return rsearch(root->right, data);
    }
}

node maximum(node root)
{
    if (root == NULL)
    {
        return NULL;
    }

    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

int main()
{
    node root = NULL;

    insert(&root, 10);
    insert(&root, 2);
    insert(&root, 4);
    insert(&root, 5);
    insert(&root, 11);
    insert(&root, 8);

    printf("\nInorder:   ");
    inorder(root);

    printf("\nSearch 5:  ");
    node n = rsearch(root, 5);
    if (n == NULL)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("element found\n");
    }

    node max = maximum(root);
    if (max == NULL)
    {
        printf("tree is empty\n");
    }
    else
    {
        printf("max element is %d\n", max->data);
    }

    return 0;
}