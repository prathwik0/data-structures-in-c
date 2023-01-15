#include <stdio.h>
#include <stdlib.h>
typedef struct NODE
{
    struct NODE *next;
    int d;

} *node;

typedef struct
{
    node front;
    /* data */
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
    if (a->front == NULL)
    {
        return;
    }
    node cur = a->front;
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
    if (a->front == NULL)
    {
        return;
    }
    if (cur->next == NULL)
    {
        a->front = NULL;
        free(cur);
    }
    node prev = cur;
    cur = cur->next;
    while (cur->next != NULL)
    {
        prev = cur;
        cur = cur->next;
    }
    prev->next = cur;
    free(cur);
}
int main()
{
    int ch, x;
    list a;
    a.front = NULL;
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
            deleterear(&a);
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