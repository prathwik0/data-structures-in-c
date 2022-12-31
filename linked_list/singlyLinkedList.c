#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int d;
    struct NODE *next;
} *node;

typedef struct
{
    struct NODE *head;
} list;

void getnode(node *n)
{
    *n = (struct NODE *)malloc(sizeof(struct NODE));
}

void display(list a);

void insertFront(list *a, int x);

int deleteFront(list *a);

int main()
{
    list a;
    a.head = NULL;

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
            display(a);
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

void insertFront(list *a, int x)
{
    node temp = a->head;
    getnode(&(a->head));
    a->head->d = x;
    a->head->next = temp;
}

void display(list a)
{
    if (a.head == NULL)
    {
        printf("no elements present");
    }

    while (a.head != NULL)
    {
        printf("-> ");
        printf("%d", a.head->d);
        a.head = a.head->next;
    }

    printf("\n");
}

int deleteFront(list *a)
{
    if (a->head == NULL)
    {
        return -1;
    }

    node temp = a->head;
    int temp2 = temp->d;
    a->head = a->head->next;

    free(temp);
    return temp2;
}
