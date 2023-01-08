#ifndef SINGLY_H
#define SINGLY_H

/*
 *This defines the nodes used in singly linked list
 */
typedef struct NODE
{
    int d;
    struct NODE *next;
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
void insertFront(list *a, int x);
void insertRear(list *a, int x);

/*
 *These functions are used for deletion in the list
 */
void deleteFront(list *a);
void deleteRear(list *a);
void deletePosition(list *a, int key);
void deleteElement(list *a, int element);

#endif