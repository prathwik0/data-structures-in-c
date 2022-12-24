#include<stdio.h>
#include<stdlib.h>

typedef struct NODE{
     struct NODE *left;
     struct NODE *right;
     char value;
}node;

void preorder(node *root){//print first then check left then chcking right using recursion
    if(root!=NULL){
        printf("%d",root->value);//postorder(root->left);
        preorder(root->left);    //postorder(root->right);
        preorder(root->right);   //printf("%d",root->value);
    }
}

void levelorder(node *root){
        QUEUE q,init(&q);
        enqueue(root);
        node *n;
        while(n!=dequeue()){
        printf("%d",n->values);
        enqueue(n->left);
        enqueue(n->right);
        }
}