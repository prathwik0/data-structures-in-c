#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    struct NODE *left;
    struct NODE *right;
    int data;
}*node;

node newNode(int data)
{
    node temp = (struct NODE*)malloc(sizeof(struct NODE));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void preorder(node root){
    if (root == NULL){
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(node root){
    if (root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void inorder(node root){
    if (root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
 
int main()
{
    node root;
    int x;
 
    root = newNode(3);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(4);

    //            (3)    
    //          /     \
    //       (2)      (5)
    //      /   \      /  \
    //    (1)   (4)  (-)  (-)
    
    printf("\nPreorder:  ");
    preorder(root);

    printf("\nPostorder: ");
    postorder(root);

    printf("\nInorder:   ");
    inorder(root);
    
    return 0;
}