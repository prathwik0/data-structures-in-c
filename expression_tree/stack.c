#include <stdlib.h>
#include "stack.h"

stacknode getNodeStack(void *ptr)
{
    stacknode n = (struct STACKNODE *)malloc(sizeof(struct STACKNODE));
    n->ptr = ptr;
    n->next = NULL;
    return n;
}

void push(stack *s, void *ptr)
{
    stacknode temp = s->front;
    s->front = getNodeStack(ptr);
    s->front->next = temp;
}

void *pop(stack *s)
{
    if (s->front == NULL)
    {
        return NULL;
    }

    stacknode temp = s->front;
    s->front = s->front->next;

    void *ptr = temp->ptr;
    free(temp);
    return (ptr);
}

void *peek(stack *s)
{
    if (s->front == NULL)
    {
        return NULL;
    }

    return s->front->ptr;
}