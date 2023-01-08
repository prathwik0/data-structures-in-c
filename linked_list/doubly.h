#ifndef DOUBLY_H
#define DOUBLY_H

/*
 *This defines the nodes used in doubly linked list
 */
typedef struct NODE
{
    struct NODE *left;
    int d;
    struct NODE *right;
} *node;

/*
 *This defines the structure list which contains pointer to the first node of the linked list
 */
typedef struct
{
    node front; // struct NODE* front;
} list;

/*
 *This displays the linked list
 */
void display(list *a);

/*
 *These functions are used for insertion in the list
 */
void insertFront(list *a, int data);
void insertRear(list *a, int data);

/*
 *These functions are used for deletion in the list
 */
int deleteFront(list *a);
int deleteRear(list *a);

#endif