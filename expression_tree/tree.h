#ifndef TREE_H
#define TREE_H

typedef struct NODE
{
    char c;
    struct NODE *left;
    struct NODE *right;
} *node;

node getNode(char c);

#endif