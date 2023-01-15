#include <stdio.h>
#include <stdlib.h>
#include "doubly.h"

node get_node(int data)
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

    printf("right ");
    while (cur != NULL)
    {
        printf("-> %d ", cur->d);
        cur = cur->right;
    }
    printf("\n");

    printf("left  -> %d ", cur->d);
    while (cur->left != NULL)
    {
        cur = cur->left;
        printf("-> %d ", cur->d);
    }
    printf("\n");
}

void insertFront(list *a, int data)
{
    node temp = a->front;

    a->front = get_node(data);
    a->front->left = NULL;
    a->front->right = temp;

    if (temp != NULL)
    {
        a->front->right->left = a->front;
    }
}

int deleteFront(list *a)
{
    node cur = a->front;

    if (cur == NULL)
    {
        return -1;
    }

    if (cur->right == NULL)
    {
        a->front = NULL;

        int temp = cur->d;
        free(cur);
        return temp;
    }

    cur->right->left = NULL;

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

        cur->left = NULL;
        cur->right = NULL;

        a->front = cur;
        return;
    }

    while (cur->right != NULL)
        cur = cur->right;

    cur->right = get_node(data);

    cur->right->right = NULL;
    cur->right->left = cur;
}

int deleteRear(list *a)
{
    node cur = a->front;

    if (cur == NULL)
    {
        return -1;
    }

    while (cur->right != NULL)
    {
        cur = cur->right;
    }

    cur->left->right = NULL;

    int temp = cur->d;
    free(cur);
    return temp;
}

void deleteElement(list *l, int element)
{
    if (l->front == NULL)
    {
        return;
    }

    node *cur = &(l->front);
}