#include <stdlib.h>
#include "tree.h"

node getNode(char c)
{
    node n = (struct NODE *)malloc(sizeof(struct NODE));
    n->c = c;
    n->left = NULL;
    n->right = NULL;
    return n;
}