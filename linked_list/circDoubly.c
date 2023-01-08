#include <stdio.h>
#include <stdlib.h>
#include "circDoubly.h"

node get_node(int data)
{
    node n = (struct NODE *)malloc(sizeof(struct NODE));
    n->d = data;
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
    node cur = a->front;

    if (cur == NULL)
    {
        cur = get_node(data);
        cur->left = cur;
        cur->right = cur;
        a->front = cur;
        return;
    }

    cur = cur->left;

    cur->right = get_node(data);
    cur->right->right = a->front;
    cur->right->left = cur;

    a->front->left = cur->right;

    a->front = cur->right;
}

int deleteFront(list *a)
{
    node cur = a->front;

    if (cur == NULL)
    {
        return -1;
    }

    if (cur->right == cur)
    {
        int temp = cur->d;

        a->front = NULL;

        free(cur);

        return temp;
    }

    cur->left->right = cur->right;
    cur->right->left = cur->left;

    a->front = cur->right;

    int temp = cur->d;
    free(cur);
    return temp;
}

void insertRear(list *a, int data)
{
    node cur = a->front;

    if (cur == NULL)
    {
        cur = get_node(data);
        cur->left = cur;
        cur->right = cur;
        a->front = cur;
        return;
    }

    cur = cur->left;
    cur->right = get_node(data);

    cur->right->right = a->front;
    cur->right->left = cur;

    cur->right->right->left = cur->right;
}

int deleteRear(list *a)
{
    node cur = a->front;

    if (cur == NULL)
    {
        return -1;
    }

    if (cur->right == cur)
    {
        int temp = cur->d;

        a->front = NULL;

        free(cur);

        return temp;
    }

    cur = cur->left;

    cur->left->right = cur->right;
    cur->right->left = cur->left;

    int temp = cur->d;
    free(cur);
    return temp;
}

