#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    struct NODE *left;
    int d;
    struct NODE *right;
} *node;

typedef struct
{
    node front;
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

    printf("right -> %d ", cur->d);
    while (cur->right != NULL)
    {
        cur = cur->right;
        printf("-> %d ", cur->d);
    }
    printf("\n");

    printf("left  -> %d ", cur->d);
    while (cur->left != NULL)
    {
        cur = cur->left;
        printf("-> %d ", cur->d);
    }
    printf("\n");
}

void insertFront(list *a, int data)
{
    node cur = a->front;

    cur = get_node(data);

    cur->left = NULL;
    cur->right = a->front;

    cur->right->left = cur;

    a->front = cur;
}

int deleteFront(list *a)
{
    node cur = a->front;

    if (cur == NULL)
    {
        return -1;
    }

    if (cur->right == NULL)
    {
        a->front = NULL;

        int temp = cur->d;
        free(cur);
        return temp;
    }

    cur->right->left = NULL;

    a->front = cur->right;

    int temp = cur->d;
    free(cur);
    return temp;
}

void insertRear(list *a, int data)
{
    node cur = a->front;

    if (cur == NULL)
    {
        cur = get_node(data);

        cur->left = NULL;
        cur->right = NULL;

        a->front = cur;
        return;
    }

    while (cur->right != NULL)
        cur = cur->right;

    cur->right = get_node(data);

    cur->right->right = NULL;
    cur->right->left = cur;
}

int deleteRear(list *a)
{
    node cur = a->front;

    if (cur == NULL)
    {
        return -1;
    }

    while (cur->right != NULL)
    {
        cur = cur->right;
    }

    cur->left->right = NULL;

    int temp = cur->d;
    free(cur);
    return temp;
}