#include <stdio.h>
#include <stdlib.h>
#include "doubly.h"

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
    while (cur->right != NULL)
    {
        cur = cur->right;
        printf("-> %d ", cur->d);
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

void deleteElement(list *l,int element)
{
    node cur=l->front;
    //Checks for List Empty Conditions     
    if(cur==NULL)
    {
        return;
    }
    //checks if the Element is delted from the head
    if(cur->d==element && cur->right==NULL){
        l->front=NULL;
        free(cur);
        return;
    }
    //head with other elements
    if(cur->d==element)
    {
        l->front=cur->right;
        l->front->left=NULL;
        free(cur);
        return;
    } 
    //finding the element
    //Kausthubh:THE FUCKING ORDER MATTERS DUMBASS (SEG FAULT OTHERWISE DUE TO cur->d)
    while(cur!=NULL && cur->d!=element)
    {
        cur=cur->right;
    }
    //if not found
    if(cur==NULL)
    {
        printf("Element not found\n");
        return;
    }
    //found a match and not the last element
    cur->left->right=cur->right;
    //Last element
    if(cur->right==NULL)
    {
        free(cur);
        return;
    }
    cur->right->left=cur->left;
    free(cur);
}