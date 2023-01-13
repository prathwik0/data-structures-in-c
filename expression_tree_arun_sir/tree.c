#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

void tree_init(TREE *tree)
{
  tree->root = NULL;
}

int height(TREE_NODE *root)
{
  int left_height, right_height;
  left_height = 0;
  right_height = 0;

  if (root == NULL) {
    return 0;
  }

  if (root->left) {
    left_height  = 1 + height(root->left);
  }

  if (root->right) {
    right_height = 1 + height(root->right);
  }

  if (left_height - right_height > 0)
    return left_height;
  return right_height;
}

TREE_NODE *inorder_pred(TREE_NODE *root)
{
  TREE_NODE *pred;

  if (root == NULL) {
    return NULL;
  }

  pred = root->left;
  while (pred) {
    pred = pred->right;
  }

  return pred;
}

TREE_NODE *inorder_succ(TREE_NODE *root)
{
  TREE_NODE *succ;

  if (root == NULL) {
    return NULL;
  }

  succ = root->right;
  while (succ) {
    succ = succ->left;
  }

  return succ;
}

void tree_add(TREE *tree, TREE_NODE *root, TREE_NODE *node)
{
  node->left  = NULL;
  node->right = NULL;

  if (tree->root == NULL) {
    tree->root = node;
    return;
  }

  if (node->data > root->data) {
    if (root->right) {
      tree_add(tree, root->right, node);
    }
    else {
      root->right = node;
    }
  }
  else {
    if (root->left) {
      tree_add(tree, root->left, node);
    }
    else {
      root->left = node;
    }
  }
}

void tree_inorder(TREE_NODE *root)
{
  if (root == NULL) {
    return;
  }
  tree_inorder(root->left);
  printf("Node = %c\n", root->data);
  tree_inorder(root->right);
}

int eval_expr(TREE_NODE *root)
{
  if (root == NULL) {
    return 0;
  }

  if (root->left == NULL && root->right == NULL) {
    char val = root->data;
    return (atoi(&val));
  }

  int ltree_val = eval_expr(root->left);
  int rtree_val = eval_expr(root->right);

  if (root->data == '+')
    return (ltree_val + rtree_val);

  if (root->data == '-')
    return (ltree_val - rtree_val);

  if (root->data == '*')
    return (ltree_val * rtree_val);

  if (root->data == '/')
    return (ltree_val / rtree_val);

  return -1;
}

