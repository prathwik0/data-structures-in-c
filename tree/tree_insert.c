#include <stdio.h>
#include <stdlib.h>
#define COUNT 4

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
void insert_with_arranging(node *root, int data);
void arrange(node *root);
int get_height(node root);
void clockwise_rotate(node *root);
void anticlockwise_rotate(node *root);
void print2DUtil(node root, int space);
void print2D(node root);

int main()
{
    node root = NULL;

    insert_with_arranging(&(root), 1);
    insert_with_arranging(&(root), 2);
    insert_with_arranging(&(root), 3);
    insert_with_arranging(&(root), 4);
    insert_with_arranging(&(root), 5);
    insert_with_arranging(&(root), 6);
    insert_with_arranging(&(root), 7);
    insert_with_arranging(&(root), 8);
    insert_with_arranging(&(root), 9);
    insert_with_arranging(&(root), 10);
    insert_with_arranging(&(root), 9);
    insert_with_arranging(&(root), 7);
    // insert_with_arranging(&(root), 13);
    // insert_with_arranging(&(root), 14);
    // insert_with_arranging(&(root), 15);
    // insert_with_arranging(&(root), 16);
    // insert_with_arranging(&(root), 17);

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

void insert_with_arranging(node *root, int data)
{
    if (*root == NULL)
    {
        *root = return_node(data);
        return;
    }

    if ((*root)->data > data)
    {
        insert_with_arranging(&((*root)->left), data);
    }
    else
    {
        insert_with_arranging(&((*root)->right), data);
    }

    arrange(root);
}

void arrange(node *root)
{
    int l = get_height((*root)->left);
    int r = get_height((*root)->right);

    if (l - r == 0 || l - r == 1 || l - r == -1)
    {
        return;
    }

    if (r > l)
    {
        if (get_height((*root)->right->right) > get_height((*root)->right->left))
        {
            anticlockwise_rotate(root);
        }
        else
        {
            clockwise_rotate(&((*root)->right));
            anticlockwise_rotate(root);
        }
    }

    if (l > r)
    {
        if (get_height((*root)->left->left) > get_height((*root)->left->right))
        {
            clockwise_rotate(root);
        }
        else
        {
            anticlockwise_rotate(&((*root)->left));
            clockwise_rotate(root);
        }
    }
}

void clockwise_rotate(node *root)
{
    node temp = (*root)->left->right;

    (*root)->left->right = *root;
    *root = (*root)->left;

    (*root)->right->left = temp;
}

void anticlockwise_rotate(node *root)
{
    node temp = (*root)->right->left;

    (*root)->right->left = *root;
    *root = (*root)->right;

    (*root)->left->right = temp;
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