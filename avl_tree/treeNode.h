#ifndef TREE_NODE_H
#define TREE_NODE_H

/*
 *avl tree node with left, right pointer
 *void pointer to point to any data
 *height of the tree as integer
 *tree height is absent in this node
 */
typedef struct NODE
{
    struct NODE *left;
    struct NODE *right;
    void *ptr;
    int height;
} *node;

/*
 *inserts the data pointer and returns node
 *initializes left and right pointer to NULL
 *set the height to 1
 */
node getNode(void *data_ptr);

/*
 *get height of tree node
 */
int getHeight(node root);

/*
 *recursively get height
 *don't use this
 */
int getHeightRecursive(node root);

/*
 *updates the height of the node
 */
void updateHeight(node root);

#endif