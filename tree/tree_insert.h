#ifndef TREE_INSERT_H
#define TREE_INSERT_H

/*
 *define data structure for tree
 */
typedef struct NODE
{
    struct NODE *left;
    int data;
    struct NODE *right;
} *node;

typedef struct
{
    node root;
} tree;

/*
 *print inorder
 */
void inorder(node root);

/*
 *BST insertion
 */
void insert_without_arranging(node *root, int data);

/*
 *AVL tree insertion
 */
void insert_with_arranging(node *root, int data);

/*
 *get height of tree node
 */
int get_height(node root);

#endif