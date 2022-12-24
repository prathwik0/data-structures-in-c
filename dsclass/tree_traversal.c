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

//-------------------This is the code for the queue------------------------//
typedef struct NODEQ
{
    node d;
    struct NODEQ *next;
}*nodeq;

void getnode(nodeq *n)
{
    *n = (struct NODEQ *)malloc(sizeof(struct NODEQ));
}

typedef struct 
{
    nodeq front; 
    nodeq rear;  
}queue;

void enqueue(queue *q, node x);
node dequeue(queue *q);

//-------------------This is the code for the queue------------------------//

void levelorder(node root){
    queue q;
    q.front = NULL;
    q.rear = NULL;

    while(root)
    {
        printf("%d ", root->data);
        if (root->left) enqueue(&q, root->left);
        if (root->right) enqueue(&q, root->right);

        root = dequeue(&q);
    }
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
    root->left->left->left = newNode(10);
    root->left->left->right = newNode(11);
    root->left->right->left = newNode(12);
    root->left->right->right = newNode(13);

    //                 (3)    
    //            /           \
    //         (2)              (5)
    //       /      \          /   \
    //    (1)        (4)     (-)    (-)
    //   /   \      /   \
    // (10) (11)  (12)  (13)  
    
    printf("\nPreorder:  ");
    preorder(root);

    printf("\nPostorder: ");
    postorder(root);

    printf("\nInorder:   ");
    inorder(root);

    printf("\nLevelorder:   ");
    levelorder(root);
    
    return 0;
}

void enqueue(queue *q, node x)
{
    //this initializes the queue if there are no elements
    if (q->front == NULL)
    {
        getnode(&(q->front));
        q->front->next = q->front;
        q->rear = q->front->next;

        q->front->d = x;
    }
    else
    {
        getnode(&(q->front->next));

        q->front->next->d = x;
        q->front->next->next = q->rear;

        //this sets front to the new front 
        q->front = q->front->next;

        //we could have done the above before initializing the new nodeq but 
        //but then I wouldn't get to use ...->...->...->...
    }
}

node dequeue(queue *q)
{
    if (q->front == NULL)
    {
        return NULL;
    }

    if (q->rear == q->front)
    {
        node temp = q->front->d;
        free(q->front);
        q->front = NULL;
        q->rear = NULL;
        return temp;
    }

    q->rear = q->rear->next;

    node temp = q->front->next->d;
    free(q->front->next);
    q->front->next = q->rear;

    return temp;
}