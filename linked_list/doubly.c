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
    // node cur = a->front;

    // a->front = get_node(data);
    // a->front->right = cur;

    // if (cur != NULL)
    // {
    //     a->front->right->left = a->front;
    // }

    node newNode = get_node(data);

    if (a->front == NULL)
    {
        a->front = newNode;
        a->rear = newNode;
        return;
    }

    a->front->left = newNode;
    newNode->right = a->front;
    a->front = newNode;
}

void insertPosition(list *a, int pos)
{
    if (a->front == NULL && pos != 0)
    {
        return;
    }

    if (a->front == NULL)
    {
        a->front = get_node(data);
        a->rear = a->front;
        return;
    }

    if (pos == 0)
    {
        node temp = a->front;
        a->front = get_node(data);
        a->front->right = temp;
        a->front->right->left = a->front;
        return;
    }

    node cur = a->front;
    pos--;

    while (cur != NULL && pos != 0)
    {
        cur = cur->right;
        pos--;
    }

    if (cur == NULL)
    {
        printf("position out of bound\n");
        return;
    }

    node temp = cur->right;
    cur->right = get_node(data);
    cur->right->left = cur;
    cur->right->right = temp;

    (temp == NULL) ? (a->rear = cur->right) : (temp->left = cur->right);
}

int deleteFront(list *a)
{
    if (a->front == NULL)
    {
        return -1;
    }

    node cur = a->front;

    if (a->front->right == NULL)
    {
        a->front = NULL;
        a->rear = NULL;

        int temp = cur->d;
        free(cur);
        return temp;
    }

    a->front = a->front->right;
    a->front->left = NULL;

    int temp = cur->d;
    free(cur);
    return temp;
}

void insertRear(list *a, int data)
{
    node newNode = get_node(data);

    if (a->rear == NULL)
    {
        a->rear = newNode;
        a->front = newNode;
        return;
    }

    a->rear->right = newNode;
    newNode->left = a->rear;
    a->rear = newNode;
}

int deleteRear(list *a)
{
    if (a->rear == NULL)
    {
        return -1;
    }

    node cur = a->rear;

    if (a->rear->left == NULL)
    {
        a->rear = NULL;
        a->front = NULL;

        int temp = cur->d;
        free(cur);
        return temp;
    }

    a->rear = a->rear->left;
    a->rear->right = NULL;

    int temp = cur->d;
    free(cur);
    return temp;
}

void deleteElement(list *a, int element)
{
    if (a->front == NULL)
    {
        return;
    }

    node cur = a->front;

    while (cur != NULL && cur->d != element)
    {
        cur = cur->right;
    }

    if (cur == NULL)
    {
        printf("not found\n");
        return;
    }

    if (cur == a->front)
    {
        deleteFront(a);
        return;
    }
    if (cur == a->rear)
    {
        deleteRear(a);
        return;
    }

    cur->left->right = cur->right;
    cur->right->left = cur->left;
    free(cur);
}

void deleteElement(list *l, int element)
{
    node cur = l->front;
    // Checks for List Empty Conditions
    if (cur == NULL)
    {
        return;
    }
    // checks if the Element is delted from the head
    if (cur->d == element && cur->right == NULL)
    {
        l->front = NULL;
        free(cur);
        return;
    }
    // head with other elements
    if (cur->d == element)
    {
        l->front = cur->right;
        l->front->left = NULL;
        free(cur);
        return;
    }
    // finding the element
    // Kausthubh:THE FUCKING ORDER MATTERS DUMBASS (SEG FAULT OTHERWISE DUE TO cur->d)
    while (cur != NULL && cur->d != element)
    {
        cur = cur->right;
    }
    // if not found
    if (cur == NULL)
    {
        printf("Element not found\n");
        return;
    }
    // found a match and not the last element
    cur->left->right = cur->right;
    // Last element
    if (cur->right == NULL)
    {
        free(cur);
        return;
    }
    cur->right->left = cur->left;
    free(cur);
}