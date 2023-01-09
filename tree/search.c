#include "treeNode.h"
#include <stdlib.h> //definition of NULL is present in stdio.h / stdlib.h / stddef.h etc..

node rsearch(node n, int data)
{
    if (n == NULL)
    {
        return NULL;
    }
    if (data == n->data)
    {
        return n;
    }
    if (data < n->data)
    {
        return rsearch(n->left, data);
    }
    else
    {
        return rsearch(n->right, data);
    }
}

node *rsearchptr(node *n, int data)
{
    node cur = *n;
    if (cur == NULL)
    {
        return NULL;
    }
    if (data == cur->data)
    {
        return n;
    }
    if (data < cur->data)
    {
        return rsearchptr(&(cur->left), data);
    }
    else
    {
        return rsearchptr(&(cur->right), data);
    }
}
