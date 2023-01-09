#ifndef TREE_NODE_H
#define TREE_NODE_H

/*
 *simple tree node with left, right and integer as data
 *tree height is absent in this node
 */
typedef struct NODE
{
    struct NODE *left;
    struct NODE *right;
    int data;
} *node;

/*
 *inserts integer data and returns node
 *initializes left and right pointer to NULL
 */
node getNode(int data);

/*
 *get height of tree node
 */
int get_height(node root);

#endif