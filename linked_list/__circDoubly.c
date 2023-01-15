#include <stdio.h>
#include <stdlib.h>
#include "circDoubly.h"

node getNode(int data)
{
    node n = (struct NODE *)malloc(sizeof(struct NODE));
    n->d = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void display(list *a)
{
    node cur = a->front;

    if (cur == NULL)
    {
        return;
    }

    printf("right -> %d ", cur->d);
    cur = cur->right;
    while (cur != a->front)
    {
        printf("-> %d ", cur->d);
        cur = cur->right;
    }
    printf("\n");

    printf("left  -> %d ", cur->d);
    cur = cur->left;
    while (cur != a->front)
    {
        printf("-> %d ", cur->d);
        cur = cur->left;
    }
    printf("\n");
}

void insertFront(list *a, int data)
{
    if (a->front == NULL)
    {
        a->front = getNode(data);
        a->front->left = a->front;
        a->front->right = a->front;
        return;
    }

    node cur = a->front->left;

    cur->right = getNode(data);

    cur->right->left = cur;
    cur->right->right = a->front;

    a->front->left = cur->right;
    a->front = cur->right;
}

void deleteRear(list *a, int data)
{
    if (a->front == NULL)
    {
        return;
    }

    if (a->front->right = a->front)
    {
        node temp = a->front;
        a->front = NULL;
        free(temp);
    }

    node cur = a->front->left;

    cur->right->left = a->front;
    cur->left->right = cur->right;

    free(cur);
}
