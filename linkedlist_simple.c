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

//for insert in the beginning set pos as 0
//for insert in the end set pos as negative number say -1
void insert(node *n, int pos, int x)
{
    while(*n != NULL && pos != 0)
    {
        n = &((*n)->next);
        pos--;
    }
    node temp = *n;
    getnode(n);
    (*n)->data = x;
    (*n)->next = temp;
}

void display(node n)
{
    if (n == NULL)
    {
        printf("no elements present");
    }
    
    while(n != NULL)
    {
        printf("-> %d ", n->data);
        n = n->next;
    }

    printf("\n\n");
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
    return 0;
}

int main()
{
    node a = NULL;

    while (1)
    {
        int n;
        printf("1 - insert, 2 - display, 3 - delete : ");
        scanf("%d", &n);

        if (n == 1)
        {
            int d, pos;
            printf("Enter int: ");
            scanf("%d", &d);

            printf("Enter position : ");
            scanf("%d", &pos);
            printf("\n");

            insert(&a, pos, d);
        }
        else if (n == 2)
        {
            display(a);
        }
        else if (n == 3)
        {
            int pos;
            printf("Enter position : ");
            scanf("%d", &pos);
            printf("\n");
            delete(&a, pos);
        }
        else
        {
            return 0;
        }
    }
}