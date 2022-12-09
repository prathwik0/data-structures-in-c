#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    int data;
    struct NODE *next;
};

typedef struct NODE *node;

void getnode(node *n)
{
    *n = (struct NODE *)malloc(sizeof(struct NODE));
}

void insert(node *n, int x)
{
    node temp = *n;
    getnode(n);
    (*n)->data = x;
    (*n)->next = temp;
}

void insertend(node *n, int x)
{
    while(*n != NULL)
        n = &((*n)->next);
    getnode(n);
    (*n)->data = x;
    (*n)->next = NULL;
}

void display(node *n)
{
    printf("\n");
    while(*n != NULL)
    {
        printf("%d ", (*n)->data);
        n = &((*n)->next);
    }
    printf("\n");
    return;
}

int popf(node *n)
{
    //returns -1 if linked list is empty
    if (*node == NULL)
    {
        return -1;
    }

    node temp = *n;
    *n = (*n)->next;

    int temp2 = temp->data;

    free(temp);

    return temp2;
}

int popb(node *n)
{
    //returns -1 if linked list is empty
    if (*node == NULL)
    {
        return -1;
    }

    //this traverses to the node
    while((*n)->next != NULL)
    {
        n = &((*n)->next);
    }

    node temp = *n;
    *n = (*n)->next;

    int temp2 = temp->data;

    free(temp);

    return temp2;
}

int delete(node *n, int pos)
{
    while (*n != NULL)
    {
        if (pos == 0)
        {
            node temp = *n;
            *n = (*n)->next;

            int temp2 = temp->data;

            free(temp);

            return temp2;
        }
        pos--;
    }
}

int deleteval(node *n, int x)
{
    int count = 0;
    while(*n != NULL)
    {
        if ((*n)->data == x)
        {
            node temp = *n;
            *n = (*n)->next;
            free(temp);
            count++;
        }
        else
        {
            n = &((*n)->next);
        }
    }
    return count;
}

int main()
{
    node a = NULL;

    while (1)
    {
        int n;
        printf("1 - insert, 2 - display, 3 - delete\n");
        scanf("%d", &n);

        if (n == 1)
        {
            int d;
            printf("Enter int: ");
            scanf("%d", &d);
            insertend(&a, d);
        }
        else if (n == 2)
        {
            display(&a);
        }
        else if (n == 3)
        {
            int d;
            printf("Enter int: ");
            scanf("%d", &d);
            printf("%d elements deleted\n", delete(&a, d));
        }
        else
        {
            return 0;
        }
    }
}
