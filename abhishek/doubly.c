#include <stdio.h>
#include <stdlib.h>
typedef struct NODE
{
    struct NODE *next;
    struct NODE *prev;

    int d;

} *node;

typedef struct
{
    node front;
    node rear;
    /* data */
} list;

node getnode(int x)
{
    node n = (struct NODE *)malloc(sizeof(struct NODE));
    n->d = x;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

void display(list *a)
{
    node cur = a->front;
    if (a->front == NULL)
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

void insertfront(list *a, int x)
{
    if (a->front == NULL)
    {
        node newnode = getnode(x);
        a->front = newnode;
        a->rear = a->front;
        a->front->next = NULL;
        a->front->prev = NULL;
    }
    else
    {
        node newnode = getnode(x);
        a->front->prev = newnode;
        newnode->next = a->front;
        a->front = newnode;
    }
}
void deletefront(list *a)
{
    node cur = a->front;
    if (cur == NULL)
    {
        return;
    }
    if (cur->next == NULL)
    {
        a->front = NULL;
        a->rear = NULL;
        free(cur);
        return;
    }
    a->front->next->prev = NULL;
    a->front = a->front->next;
    free(cur);
}

void deleterear(list *a)
{
    node cur = a->rear;

    a->rear->prev->next = NULL;
    a->rear = a->rear->prev;
    free(cur);
}

void deleteelement(list *a, int x)
{
    node cur = a->front;
    if (a->front == NULL)
    {
        return;
    }
    while (cur != NULL && cur->d != x)
    {
        cur = cur->next;
    }
    if (cur == NULL)
    {
        printf("noone\n");

        return;
    }
    if (cur == a->rear)
    {
        deleterear(a);
        return;
    }
    if (cur == a->front)
    {
        deletefront(a);
        return;
    }
    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    free(cur);
}

int main()
{
    int ch, x;
    list a;
    a.front = NULL;
    a.rear = NULL;
    while (1)
    {
        printf("enter ur choice\n");
        printf("1.insert 2. delete 3.display\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter ur data\n");
            scanf("%d", &x);
            insertfront(&a, x);
            break;
        case 2:
            printf("enter element\n");
            scanf("%d", &x);
            deleteelement(&a, x);
            break;
        case 3:
            display(&a);
            break;
        default:
            printf("wrong\n");
        }
    }
    return 0;
}