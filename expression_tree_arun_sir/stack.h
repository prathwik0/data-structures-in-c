#ifndef _STACK_H_
#define _STACK_H_

#define MAX 100

#include "tree.h"
#include <stdbool.h>

typedef struct stack
{
  int top;
  void *data[MAX];
} STACK;

void stack_init(STACK *s);

bool stack_empty(STACK *s);

bool stack_push(STACK *s, void *data);

bool stack_pop(STACK *s, void **data_ptr);

bool stack_peek(STACK *s, void **data_ptr);

#endif /* _STACK_H_ */
