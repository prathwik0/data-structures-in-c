#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int d;
    struct NODE *next;
} *node;

node getnode(int data)
{
    node n = (struct NODE *)malloc(sizeof(struct NODE));
    n->d = data;
    n->next = NULL;
    return n;
}

void display(node *n);

void insertFront(node *n, int x);

void deleteAllOccurences(node *n, int element);

int main()
{
    node n = NULL;

    while (1)
    {
        int choice;
        printf("1 - insert, 2 - display, 3 - delete : ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int data;
            scanf("%d", &data);

            insertFront(&n, data);
        }
        else if (choice == 2)
        {
            display(&n);
        }
        else if (choice == 3)
        {
            int key;
            scanf("%d", &key);
            deleteAllOccurences(&n, key);
        }
        else
        {
            return 0;
        }
    }
}

void insertFront(node *n, int data)
{
    node temp = *n;
    *n = getnode(data);
    (*n)->next = temp;
}

void display(node *n)
{
    if (*n == NULL)
    {
        return;
    }

    while (*n != NULL)
    {
        printf("-> %d ", (*n)->d);
        n = &((*n)->next);
    }
    printf("\n");
}

void deleteAllOccurences(node *n, int element)
{
    while (*n != NULL)
    {
        if ((*n)->d == element)
        {
            node temp = *n;
            *n = (*n)->next;
            free(temp);
        }
        else
        {
            n = &((*n)->next);
        }
    }
}