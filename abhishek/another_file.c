#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct NODE
{
    int d;
    struct NODE *left;
    struct NODE *right;
} *node;
typedef struct
{
    node front;
    node rear;
} list;
node getnode(int x)
{
    node n = (struct NODE *)malloc(sizeof(struct NODE));
    n->d = x;
    n->left = NULL;
    n->right = NULL;
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
        cur = cur->right;
    }
}
void insertfront(list *a, int x)
{
    node cur = a->front;
    if (cur == NULL)
    {
        node newnode = getnode(x);
        a->front = newnode;
        newnode->right = NULL;
        newnode->left = NULL;
        return;
    }
    while (cur->right != NULL)
    {
        cur = cur->right;
    }
    node newnode = getnode(x);

    a->front->left = newnode;
    newnode->right = a->front;
    a->front = newnode;
}
void delete(list *a, int x)
{
    node cur = a->front;
    if (a->front == NULL)
    {
        return;
    }
    while (cur != NULL && cur->d != x)
    {
        cur = cur->right;
    }
    if (cur == NULL)
    {
        printf("none\n");
        return;
    }
    if (cur == a->front)
    {
        if (a->front->right == NULL)
        {
            a->front = NULL;
            a->rear = NULL;
            free(cur);
        }
        a->front = a->front->right;
        a->front->left = NULL;
        free(cur);
        return;
    }
    if (cur == a->rear)
    {
        a->rear = a->rear->left;
        a->rear->right = NULL;
        free(cur);
        return;
    }
    cur->left->right = cur->right;
    cur->right->left = cur->left;
    free(cur);
}
int main()
{
    list a;
    a.front = NULL;
    a.rear = NULL;

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
            delete (&a, x);
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