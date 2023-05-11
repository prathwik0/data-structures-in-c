#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int d;
    struct NODE *left;
    struct NODE *right;
} *node;

node getnode(int data)
{
    node n = (struct NODE *)malloc(sizeof(struct NODE));
    n->d = data;
    n->left = n->right = NULL;
    return n;
}

void display(node *n);
void insertFront(node *n, int x);

int main()
{
    node n = NULL;

    while (1)
    {
        int choice;
        printf("1 - insert, 2 - display: ");
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
        else
        {
            return 0;
        }
    }
}

void insertFront(node *n, int data)
{
    if (*n == NULL) //No element present in the list
    {
        *n = getnode(data);
        return;
    }
    (*n)->left = getnode(data);
    (*n)->left->right = *n;
    *n = (*n)->left;
}

void display(node *n)
{
    if (*n == NULL)
    {
        return;
    }

    printf("right ");
    while ((*n)->right != NULL)
    {
        printf("-> %d ", (*n)->d);
        n = &((*n)->right);
    }
    printf("-> %d ", (*n)->d);
    printf("\n");

    printf("left  -> %d ", (*n)->d);
    while ((*n)->left != NULL)
    {
        n = &((*n)->left);
        printf("-> %d ", (*n)->d);
    }
    printf("\n");
}