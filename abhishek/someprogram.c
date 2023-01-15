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
} list;

node getnode(int x)
{
    node n = (struct NODE *)malloc(sizeof(struct NODE));
    n->d = x;
    n->next = NULL;
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
        printf("%d\n", cur->d);
        cur = cur->next;
    }
    printf("\n");
}

void insertfront(list *a, int x)
{
    node cur = a->front;
    if (a->front == NULL)
    {
        node newnode = getnode(x);
        a->front = newnode;
        newnode->next = NULL;
    }

    else
    {
        node newnode = getnode(x);
        newnode->next = a->front;
        a->front = newnode;
    }
}
void deleterear(list *a)
{
    node cur = a->front;
    if (a->front == NULL) // nothing//
    {
        return;
    }
    if (cur->next == NULL) // one node exist//
    {
        a->front = a->front->next;
        free(cur);
        return;
    }
    node prev = cur;
    cur = cur->next;
    while (cur->next != NULL)
    {
        prev = cur;
        cur = cur->next;
    }
    prev->next = NULL;
    free(cur);
}

int main()
{
    list a;
    a.front = NULL;

    int ch;
    int x;
    while (1)
    {
        printf("enter the choice\n");
        printf("1.INSERT 2.DELETE 3.DISPLAY\n");
        scanf("%d", &ch);
        printf("\n");
        switch (ch)
        {
        case 1:
            printf("enter a data\n");
            scanf("%d", &x);
            insertfront(&a, x);
            break;
        case 2:
            deleterear(&a);
            break;
        case 3:
            display(&a);
            break;

        default:
            printf("wrong choice\n");
        }
    }
    return 0;
}