#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

typedef struct NODE
{
    void *d;
    struct NODE *next;
} *node;

void getnode(node *n)
{
    *n = (struct NODE *)malloc(sizeof(struct NODE));
}

void enqueue(queue *q, void *x)
{
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

        q->front = q->front->next;
    }
}

void *dequeue(queue *q)
{
    if (q->front == NULL)
    {
        return NULL;
    }

    if (q->rear == q->front)
    {
        void *temp = q->front->d;
        free(q->front);
        q->front = NULL;
        q->rear = NULL;
        return temp;
    }

    q->rear = q->rear->next;

    void *temp = q->front->next->d;
    free(q->front->next);
    q->front->next = q->rear;

    return temp;
}