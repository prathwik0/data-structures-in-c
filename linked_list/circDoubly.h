#ifndef CIRC_DOUBLY_H
#define CIRC_DOUBLY_H

/*
 *This defines the nodes used in singly linked list
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
void deletePosition(list *a, int key);
void deleteElement(list *a, int element);

#endif