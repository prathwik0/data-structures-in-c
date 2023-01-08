#ifndef __QUEUE
#define __QUEUE

struct NODE;

typedef struct
{
    struct NODE *front;
    struct NODE *rear;
} queue;

void enqueue(queue *q, void *x);
extern void *dequeue(queue *q);

#endif