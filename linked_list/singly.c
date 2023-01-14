#include <stdio.h>
#include <stdlib.h>
#include "singly.h"

node getnode(int data)
{
    node n = (struct NODE *)malloc(sizeof(struct NODE));
    n->d = data;
    n->next = NULL;
    return n;
}

void display(list *a)
{
    node cur = a->front;

    if (cur == NULL)
    {
        return;
    }

    while (cur != NULL)
    {
        printf("-> %d ", cur->d);
        cur = cur->next;
    }
    printf("\n");
}

void insertFront(list *a, int data)
{
    node temp = getnode(data);
    temp->next = a->front;
    a->front = temp;
}

void insertRear(list *a, int data)
{
    node cur = a->front;

    if (cur == NULL)
    {
        a->front = getnode(data);
        return;
    }

    while (cur->next != NULL)
    {
        cur = cur->next;
    }

    cur->next = getnode(data);
}

void deleteFront(list *a)
{
    node cur = a->front;

    // empty list condition
    if (cur == NULL)
    {
        // printf("empty list\n");
        return;
    }

    a->front = a->front->next;
    free(cur);
}

void deleteRear(list *a)
{
    node cur = a->front;

    if (cur == NULL)
    {
        return;
    }

    if (cur->next == NULL)
    {
        a->front = NULL; // or a->front = a->front->next;

        free(cur);
        return;
    }

    node previous = cur;
    cur = cur->next;

    while (cur->next != NULL)
    {
        previous = cur;
        cur = cur->next;
    }

    previous->next = NULL;
    free(cur);
}

void deleteRear2(list *a)
{
    node cur = a->front;

    // list empty condition
    if (cur == NULL)
    {
        return;
    }

    // only one element present
    if (cur->next == NULL)
    {
        a->front = NULL; // or a->front = a->front->next;

        free(cur);
        return;
    }

    while (cur->next->next != NULL)
    {
        cur = cur->next;
    }

    node temp = cur->next;

    cur->next = NULL; // or cur->next = cur->next->next

    free(temp);
}

void deletePosition(list *a, int key)
{
    node cur = a->front;

    // list empty condition
    if (cur == NULL)
    {
        return;
    }

    // check first node
    if (cur->next == NULL && key != 0)
    {
        printf("invalid key\n");
        return;
    }
    if (key == 0)
    {
        a->front = a->front->next;
        free(cur);
        return;
    }

    int pos = 1;

    while (cur->next->next != NULL && pos < key) // or use pos != key
    {
        cur = cur->next;
        pos++;
    }

    if (pos != key)
    {
        printf("invalid key\n");
        return;
    }

    node temp = cur->next;

    cur->next = cur->next->next;

    free(temp);
}

void deleteElement(list *a, int element)
{
    node cur = a->front;

    // list empty condition
    if (cur == NULL)
    {
        return;
    }

    // check first node
    if (cur->next == NULL && element != cur->d)
    {
        printf("element not present\n");
        return;
    }
    if (element == cur->d)
    {
        a->front = a->front->next;
        free(cur);
        return;
    }

    while (cur->next->next != NULL && cur->next->d != element)
    {
        cur = cur->next;
    }

    if (cur->next->d != element)
    {
        printf("element not present\n");
        return;
    }

    node temp = cur->next;

    cur->next = cur->next->next;

    free(temp);
}
