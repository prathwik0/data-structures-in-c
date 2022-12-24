#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    struct NODE *left;
    struct NODE *right;
    int data;
}*node;

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