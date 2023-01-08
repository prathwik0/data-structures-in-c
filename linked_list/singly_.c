#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int d;
    struct NODE *next;
} *node;

typedef struct
{
    node front; // struct NODE* front;
} list;

node getnode(int data)
{
    node n = (struct NODE *)malloc(sizeof(struct NODE));
    n->d = data;
    n->next = NULL;
    return n;
}

void display(list *a);

void insertFront(list *a, int x);
void insertRear(list *a, int x);
void insertPosition(list *a, int data, int pos);

void deleteFront(list *a);
void deleteRear(list *a);
void deletePosition(list *a, int key);
void deleteElement(list *a, int element);

int main()
{
    list a;
    a.front = NULL;

    while (1)
    {
        int choice;
        printf("1 - insert, 2 - display, 3 - delete : ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int data;
            scanf("%d", &data);

            insertRear(&a, data);
        }
        else if (choice == 2)
        {
            display(&a);
        }
        else if (choice == 3)
        {
            int key;
            scanf("%d", &key);
            deletePosition(&a, key);
        }
        else
        {
            return 0;
        }
    }
}

void insertFront(list *a, int data)
{
    node temp = a->front;
    a->front = getnode(data);
    a->front->next = temp;
}

void deleteFront(list *a)
{
    // empty list condition
    if (a->front == NULL)
    {
        return;
    }

    node temp = a->front;
    a->front = a->front->next;
    free(temp);
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

void insertRear(list *a, int x)
{
    node cur = a->front;

    if (cur == NULL)
    {
        a->front = getnode(x);
        return;
    }

    while (cur->next != NULL)
    {
        cur = cur->next;
    }

    cur->next = getnode(x);
}

void insertPosition(list *a, int data, int pos)
{
    node *n = &(a->front);
    while (*n != NULL && pos > 0)
    {
        n = &((*n)->next);
        pos--;
    }
    if (pos != 0)
    {
        return;
    }
    node temp = *n;
    *n = getnode(data);
    (*n)->next = temp;
}

void deleteRear(list *a)
{
    node *n = &(a->front);

    // list empty condition
    if (*n == NULL)
    {
        return;
    }

    while ((*n)->next != NULL)
    {
        n = &((*n)->next);
    }
    node temp = *n;
    *n = (*n)->next;
    free(temp);
}

void deletePosition(list *a, int key)
{
    node *n = &(a->front);
    while (*n != NULL && key > 0)
    {
        n = &((*n)->next);
        key--;
    }
    if (*n == NULL)
    {
        return;
    }
    node temp = (*n);
    *n = (*n)->next;
    free(temp);
}

void deleteElement(list *a, int element)
{
    node *n = &(a->front);
    while (*n != NULL)
    {
        if ((*n)->d == element)
        {
            node temp = *n;
            *n = (*n)->next;
            free(temp);
            return;
        }
        else
        {
            n = &((*n)->next);
        }
    }
}
