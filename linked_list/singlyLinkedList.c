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
    // n->next = NULL;
    return n;
}

void display(list a);

void insertFront(list *a, int x);

int deleteFront(list *a);

int main()
{
    list a;
    a.front = NULL;

    while (1)
    {
        int choice;
        printf("1 - insert, 2 - display, 3 - delete : ");
        scanf("%d", &choice);

        /*
        switch(choice)
        case(1):
        case(2):
        case(3):
        default:
        */

        if (choice == 1)
        {
            int data;
            scanf("%d", &data);

            insertFront(&a, data);
        }
        else if (choice == 2)
        {
            display(&a);
        }
        else if (choice == 3)
        {
            printf("deleted %d", deleteFront(&a));
        }
        else
        {
            return 0;
        }
    }
}

void insertFront(list *a, int data)
{
    node cur = a->front;
    a->front = getnode(data);
    a->front->next = cur;
}

void display(list *a)
{
    if (a->front == NULL)
    {
        printf("no elements present");
    }

    while (a->front != NULL)
    {
        printf("-> %d ", a->front->d);
        a->front = a->front->next;
    }
    printf("\n");
}

int deleteFront(list *a)
{
    if (a->front == NULL)
    {
        return -1;
    }

    node cur = a->front;
    int temp = cur->d;

    a->front = a->front->next;

    free(cur);
    return temp;
}
