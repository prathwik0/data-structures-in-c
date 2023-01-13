#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

char expr_str[] = "3-4*5*2-3*2";

bool is_operator(char c)
{
  if (c == '+' || c == '-' || c == '/' || c == '*')
    return true;
  return false;
}

int prec(char oper)
{
  if (oper == '*' || oper == '/')
  {
    return 1;
  }
  return 0;
}

TREE_NODE *make_tree_node(char var)
{
  TREE_NODE *node = (TREE_NODE *)malloc(sizeof(TREE_NODE));
  node->data = var;
  node->left = NULL;
  node->right = NULL;
  return node;
}

char *make_oper(char oper)
{
  char *ret = (char *)malloc(sizeof(char));
  *ret = oper;
  return (ret);
}

TREE_NODE *build_expr_tree(STACK *tree_node_stack, STACK *oper_stack)
{
  char *operator;
  TREE_NODE *root, *lnode, *rnode;

  while (!stack_empty(oper_stack))
  {
    stack_pop(oper_stack, (void *)&operator);
    root = make_tree_node(*operator);

    stack_pop(tree_node_stack, (void *)&rnode);
    stack_pop(tree_node_stack, (void *)&lnode);
    root->right = rnode;
    root->left = lnode;

    stack_push(tree_node_stack, root);
  }

  return root;
}

TREE_NODE *build_expr_tree_small(STACK *tree_node_stack, STACK *oper_stack)
{
  char *operator;
  TREE_NODE *root, *lnode, *rnode;

  stack_pop(oper_stack, (void *)&operator);
  root = make_tree_node(*operator);

  stack_pop(tree_node_stack, (void *)&rnode);
  stack_pop(tree_node_stack, (void *)&lnode);
  root->right = rnode;
  root->left = lnode;

  stack_push(tree_node_stack, root);

  return root;
}

int main()
{
  TREE *rtree, *ltree;
  int i = 0;
  char token;
  STACK tree_node_stack, oper_stack;

  stack_init(&tree_node_stack);
  stack_init(&oper_stack);

  while ((token = expr_str[i]) != '\0')
  {
    if (is_operator(token))
    {
      if (stack_empty(&oper_stack))
      {
        stack_push(&oper_stack, make_oper(token));
      }
      else
      {
        char *oper_on_top;
        stack_peek(&oper_stack, (void *)&oper_on_top);
        if (prec(token) > prec(*oper_on_top))
        {
          stack_push(&oper_stack, make_oper(token));
        }
        else if (prec(token) == prec(*oper_on_top))
        {
          TREE_NODE *n = build_expr_tree_small(&tree_node_stack, &oper_stack);
          stack_push(&oper_stack, make_oper(token));
        }
        else
        {
          TREE_NODE *n = build_expr_tree(&tree_node_stack, &oper_stack);
          stack_push(&oper_stack, make_oper(token));
        }
      }
    }
    else
    {
      TREE_NODE *tree_node = make_tree_node(token);
      stack_push(&tree_node_stack, tree_node);
    }

    i++;
  }

  build_expr_tree(&tree_node_stack, &oper_stack);

  TREE_NODE *exp_tree_root;
  if (stack_pop(&tree_node_stack, (void *)&exp_tree_root))
  {
    printf("root of the expression tree = %c\n", exp_tree_root->data);
  }

  printf("height of the expression tree = %d\n", height(exp_tree_root));

  tree_inorder(exp_tree_root);

  printf("postorder: \n");
  tree_postorder(exp_tree_root);
  printf("\n");

  printf("value of this expr tree = %d\n", eval_expr(exp_tree_root));

  return 0;
}
