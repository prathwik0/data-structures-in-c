#include<stdio.h>
#include<stdlib.h>

typedef struct NODE{
    struct NODE *left;
    struct NODE *right;
    int data;
}node;

typedef struct TREE{

    struct NODE *root;
}tree;

void add(tree *t,node *current,node *n){
    if(t->root=NULL){
        t->root=n;
        n->left=NULL;
        n->right=NULL;
        return;
    }

    if(n->data<current->data)
        add(t,t->root->left,n);
        else
        add(t,t->root->right,n);

}



int main(){
    node n1,n2;
    n1.data=10;
    tree t;
    n1=malloc(sizeof(node));
    t.root=NULL;
    add(&t,(t.root),&n1);
}