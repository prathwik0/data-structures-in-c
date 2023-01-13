#include "stack.h"
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

void stack_init(STACK *s)
{
  s->top = -1;
}

bool stack_empty(STACK *s)
{
  if (s->top <= -1)
    return true;
  return false;
}

bool stack_push(STACK *s, void *data)
{
  if (s->top == MAX-1) {
    return false;
  }
  s->top++;
  s->data[s->top] = data;
  return true;
}

bool stack_pop(STACK *s, void **data_ptr)
{
  if (s->top == -1) {
    return false;
  }

  *data_ptr = s->data[s->top];
  s->top--;
  return true;
}

bool stack_peek(STACK *s, void **data_ptr)
{
  if (s->top == -1) {
    return false;
  }
  *data_ptr = s->data[s->top];
  return true;
}

