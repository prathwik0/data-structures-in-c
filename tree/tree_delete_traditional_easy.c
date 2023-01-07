#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
    node cur = *n;
    if (cur == NULL)
    {
        return NULL;
    }
    if (key == cur->data)
    {
        return n;
    }
    if (key < cur->data)
    {
        return rsearch(&(cur->left), key);
    }
    else
    {
        return rsearch(&(cur->right), key);
    }
}

node successor(node root)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->right == NULL)
    {
        return NULL;
    }

    node successor = root->right;
    while (successor->left != NULL)
    {
        successor = successor->left;
    }
    return successor;
}

node del(node root)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->right == NULL)
    {
        node temp = root->left;
        free(root);
        return temp;
    }

    if (root->left == NULL)
    {
        node temp = root->right;
        free(root);
        return temp;
    }

    // else -- find inorder successor and delete it
    node *temp = &(root->right);
    while ((*temp)->left != NULL)
    {
        temp = &((*temp)->left);
    }

    root->data = (*temp)->data;

    (*temp) = del((*temp));

    return root;
}

// wrapper over del
void delete(node *root, int key)
{
    node *temp = rsearch(root, key);
    *temp = del(*temp);
}

int main()
{
    clock_t start, end;
    double elapsed;

    start = clock(); // Start the clock

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

    delete (&root, 8);

    print2D(root);

    printf("\nInorder:   ");
    inorder(root);

    end = clock(); // End the clock

    elapsed = (double)(end - start) / CLOCKS_PER_SEC; // Calculate elapsed time
    printf("\nElapsed time: %f seconds\n", elapsed);

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