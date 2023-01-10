#include <stdio.h>
#include <stdlib.h>
#define COUNT 5

typedef struct NODE
{
    struct NODE *left;
    int data;
    struct NODE *right;
} *node;

node return_node(int data)
{
    node x = (struct NODE *)malloc(sizeof(struct NODE));
    x->left = NULL;
    x->data = data;
    x->right = NULL;
    return x;
}

void insert_node(node *x, int data)
{
    *x = (struct NODE *)malloc(sizeof(struct NODE));
    (*x)->left = NULL;
    (*x)->data = data;
    (*x)->right = NULL;
}

typedef struct
{
    node root;
} tree;

void inorder(node root);
void insert_without_arranging(node *root, int data);
int get_height(node root);
void print2DUtil(node root, int space);
void print2D(node root);

int main()
{
    node root = NULL;

    insert_without_arranging(&(root), 1);
    insert_without_arranging(&(root), 2);
    insert_without_arranging(&(root), 3);
    insert_without_arranging(&(root), 4);
    insert_without_arranging(&(root), 5);
    insert_without_arranging(&(root), 6);
    insert_without_arranging(&(root), 7);

    printf("\nInorder:   ");
    inorder(root);

    printf("\nHeight:    %d", get_height(root));

    print2D(root);

    return 0;
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

void insert_without_arranging(node *root, int data)
{
    if (*root == NULL)
    {
        *root = return_node(data);
        return;
    }

    if ((*root)->data > data)
    {
        insert_without_arranging(&((*root)->left), data);
    }
    else
    {
        insert_without_arranging(&((*root)->right), data);
    }
}

int get_height(node root)
{
    if (root == NULL)
    {
        return 0;
    }

    int x = get_height(root->left);
    int y = get_height(root->right);

    return x > y ? x + 1 : y + 1;
}

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
    printf("%d", root->data);

    // Process left child
    print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void print2D(node root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}