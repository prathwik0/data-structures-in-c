#include <stdio.h>
#include <stdlib.h>
#define COUNT 4

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

void print2DUtil(node root, int space);
void print2D(node root);

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

node *rsearch(node *n, int key)
{
    if (*n == NULL)
    {
        return NULL;
    }
    if (key == (*n)->data)
    {
        return n;
    }

    if (key < (*n)->data)
    {
        return rsearch(&((*n)->left), key);
    }
    else
    {
        return rsearch(&((*n)->right), key);
    }
}

void del(node *root)
{
    if (*root == NULL)
    {
        return;
    }

    if ((*root)->right == NULL)
    {
        *root = (*root)->left;
        return;
    }

    if ((*root)->left == NULL)
    {
        *root = (*root)->right;
        return;
    }

    // else -- find inorder successor and delete it
    node *successor = &((*root)->right);
    while ((*successor)->left != NULL)
    {
        successor = &((*successor)->left);
    }

    node temp = *successor;

    del(successor);

    temp->left = (*root)->left;
    temp->right = (*root)->right;
    *root = temp;
}

node delete(node *root, int key)
{
    node *temp = rsearch(root, key);
    node temp2 = *temp;
    del(temp);
    return temp2;
}

int main()
{
    node root;
    int x;

    root = newNode(13);
    root->left = newNode(8);
    root->right = newNode(14);
    root->left->left = newNode(5);
    root->left->right = newNode(11);
    root->left->left->left = newNode(1);
    root->left->left->right = newNode(6);
    root->left->right->left = newNode(9);
    root->left->right->left->right = newNode(10);
    root->left->right->right = newNode(12);
    root->right->right = newNode(145);

    //                 (13)
    //            /            \
    //         (8)              (14)
    //       /      \          /    \
    //    (5)        (11)     (-)    (145)
    //   /   \      /   \
    // (1)   (6)  (9)  (12)
    //              \
    //              (10)

    node temp = delete (&root, 8);
    printf("\ndeleted %d\n", temp->data);

    print2D(root);

    printf("\nInorder:   ");
    inorder(root);

    return 0;
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