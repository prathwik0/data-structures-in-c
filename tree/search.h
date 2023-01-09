#ifndef SEARCH_H
#define SEARCH_H

#include "treeNode.h"

/*
 *recursively search for integer
 *returns pointer to pointer pointing to the node with integer
 *else returns NULL
 */
node *rsearchptr(node *root, int data);

/*
 *recursively search for integer
 *returns pointer pointing to the node with integer
 *else returns NULL
 */
node rsearch(node n, int data);

#endif