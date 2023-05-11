#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int d;
    struct NODE *right;
} *node;

node getnode(int data)
{
    node n = (struct NODE *)malloc(sizeof(struct NODE));
    n->d = data;
    n->right = NULL;
    return n;
}

void display(node *n);
void insertFront(node *n, int x);

void splitOddEven(node *n, node *odd, node *even);

int main()
{
    node n = NULL;

    while (1)
    {
        int choice;
        printf("1 - insert, 2 - display, 3 - splitOddEven : ");
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
            display(&n);

            node odd = NULL;
            node even = NULL;

            splitOddEven(&n, &odd, &even);

            printf("After splitting\n");
            printf("Odd: ");
            display(&odd);
            printf("Even: ");
            display(&even);
            return 0;
        }
        else
        {
            return 0;
        }
    }
}

void splitOddEven(node *n, node *odd, node *even)
{
    if (*n == NULL)
    {
        return;
    }
    while ((*n) != NULL)
    {
        if ((*n)->d % 2 == 0)
        {
            *even = *n;
            even = &((*even)->right);
        }
        else 
        {
            *odd = *n;
            odd = &((*odd)->right);
        }
        n = &((*n)->right);
    }
    *odd = *even = NULL;
}

void insertFront(node *n, int data)
{
    node temp = *n;
    *n = getnode(data);
    (*n)->right = temp;
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
        n = &((*n)->right);
    }
    printf("\n");
}