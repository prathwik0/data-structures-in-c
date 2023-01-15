#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int d;
    struct NODE *next;
} *node;

typedef struct
{
    struct NODE *front;
    node rear;
} list;

node get_node(int data)
{
    node n = (struct NODE *)malloc(sizeof(struct NODE));
    n->d = data;
    return n;
}

void display(list *a);

void insertFront(list *a, int data);

int deleteFront(list *a);

void insertRear(list *a, int data);

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

            insertRear(&a, d);
        }
        else if (n == 2)
        {
            display(&a);
        }
        else if (n == 3)
        {
            printf("deleted %d\n", deleteRear(&a));
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
    if (a->front == NULL)
    {
        a->front = get_node(data);
        a->front->next = cur;
        a->rear = cur;
        return;
    }

    a->rear->next = get_node(data);
    a->rear->next->next = a->front;
    a->front = a->rear->next;
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

void insertRear(list *a, int data)
{
    node cur = a->rear;

    if (cur == NULL)
    {
        cur = get_node(data);
        cur->next = cur;
        a->front = cur;
        a->rear = cur;
        return;
    }

    cur->next = get_node(data);
    cur->next->next = a->front;
    a->rear = cur->next;
}

int deleteRear(list *a)
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

    while (cur->next != a->rear)
    {
        cur = cur->next;
    }

    a->rear = cur;
    cur = cur->next;
    a->rear->next = a->front;

    int temp = cur->d;
    free(cur);
    return temp;
}