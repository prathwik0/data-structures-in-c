#ifndef STACK_H
#define STACK_H

typedef struct STACKNODE
{
    void *ptr;
    struct STACKNODE *next;
} *stacknode;

typedef struct
{
    struct STACKNODE *front;
} stack;

void push(stack *s, void *ptr);
void *pop(stack *s);
void *peek(stack *s);

#endif