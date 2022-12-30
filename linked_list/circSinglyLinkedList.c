#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int d;
    struct NODE *next;
} *node;

typedef struct
{
    node front;
    node rear;
} list;

void get_node(node *n, int data)
{
    *n = (struct NODE *)malloc(sizeof(struct NODE));
    (*n)->d = data;
}

void display(list *a);

void insertFront(list *a, int x);

int deleteFront(list *a);

void insertRear(list *a, int x);

int deleteRear(list *a);

int main()
{
    list a;
    a.front = NULL;
    a.rear = NULL;

    while (1)
    {
        int n;
        printf("1 - insert, 2 - display, 3 - delete : ");
        scanf("%d", &n);

        if (n == 1)
        {
            int d;
            scanf("%d", &d);

            insertFront(&a, d);
        }
        else if (n == 2)
        {
            display(&a);
        }
        else if (n == 3)
        {
            printf("deleted %d\n", deleteFront(&a));
        }
        else
        {
            return 0;
        }
    }
}

void display(list *a)
{
    node cur = a->front;

    if (cur == NULL)
    {
        return;
    }

    printf("-> %d ", cur->d);
    cur = cur->next;
    while (cur != a->front)
    {
        printf("-> %d ", cur->d);
        cur = cur->next;
    }
    printf("\n");
}

void insertFront(list *a, int data)
{
    node cur = a->rear;

    if (cur == NULL)
    {
        get_node(&cur, data);
        cur->next = cur;
        a->front = cur;
        a->rear = cur;
        return;
    }

    get_node(&(cur->next), data);
    cur->next->next = a->front;
    a->front = cur->next;
}

int deleteFront(list *a)
{
    node cur = a->front;

    if (cur == NULL)
    {
        return -1;
    }

    if (cur->next == cur)
    {
        int temp = cur->d;

        a->front = NULL;
        a->rear = NULL;

        free(cur);

        return temp;
    }

    a->front = cur->next;
    a->rear->next = a->front;

    int temp = cur->d;
    free(cur);
    return temp;
}
