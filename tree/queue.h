#ifndef QUEUE_H
#define QUEUE_H

struct NODE;

typedef struct
{
    struct NODE *front;
    struct NODE *rear;
} queue;

void enqueue(queue *q, void *x);
extern void *dequeue(queue *q);

#endif