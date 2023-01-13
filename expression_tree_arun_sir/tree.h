#ifndef _TREE_H_
#define _TREE_H_

typedef struct tree_node
{
  char data;
  struct tree_node *left;
  struct tree_node *right;
} TREE_NODE;

typedef struct tree
{
  TREE_NODE *root;
} TREE;


void tree_init(TREE *tree);

int height(TREE_NODE *root);

TREE_NODE *inorder_pred(TREE_NODE *root);

TREE_NODE *inorder_succ(TREE_NODE *root);

void tree_add(TREE *tree, TREE_NODE *root, TREE_NODE *node);

void tree_inorder(TREE_NODE *root);

int eval_expr(TREE_NODE *root);

#endif /* _TREE_H_ */
