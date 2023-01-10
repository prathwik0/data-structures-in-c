#ifndef INSERT_H
#define INSERT_H

#include "treeNode.h"

/*
 *regular BST insertion
 */
void insertUnbalanced(node *root, void *data_ptr);

/*
 *avl tree insertion
 */
void insert(node *root, void *data_ptr);

#endif