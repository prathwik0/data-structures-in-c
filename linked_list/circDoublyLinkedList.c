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

void get_node(node *n, int data)
{
    *n = (struct NODE *)malloc(sizeof(struct NODE));
    (*n)->d = data;
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
    cur = cur->right;
    while (cur != a->front)
    {
        printf("-> %d ", cur->d);
        cur = cur->right;
    }
    printf("\n");

    printf("left  -> %d ", cur->d);
    cur = cur->left;
    while (cur != a->front)
    {
        printf("-> %d ", cur->d);
        cur = cur->left;
    }
    printf("\n");
}

void insertFront(list *a, int data)
{
    node cur = a->front;

    if (cur == NULL)
    {
        get_node(&cur, data);
        cur->left = cur;
        cur->right = cur;
        a->front = cur;
        return;
    }

    cur = cur->left;

    get_node(&(cur->right), data);

    cur->right->right = a->front;
    cur->right->left = cur;

    cur->right->right->left = cur->right;

    a->front = cur->right;
}

int deleteFront(list *a)
{
    node cur = a->front;

    if (cur == NULL)
    {
        return -1;
    }

    if (cur->right == cur)
    {
        int temp = cur->d;

        a->front = NULL;

        free(cur);

        return temp;
    }

    cur->left->right = cur->right;
    cur->right->left = cur->left;

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
        get_node(&cur, data);
        cur->left = cur;
        cur->right = cur;
        a->front = cur;
        return;
    }

    cur = cur->left;
    get_node(&(cur->right), data);

    cur->right->right = a->front;
    cur->right->left = cur;

    cur->right->right->left = cur->right;
}

int deleteRear(list *a)
{
    node cur = a->front;

    if (cur == NULL)
    {
        return -1;
    }

    if (cur->right == cur)
    {
        int temp = cur->d;

        a->front = NULL;

        free(cur);

        return temp;
    }

    cur = cur->left;

    cur->left->right = cur->right;
    cur->right->left = cur->left;

    int temp = cur->d;
    free(cur);
    return temp;
}