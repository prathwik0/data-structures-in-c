#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int data;
    struct NODE *next;
}*node;

typedef struct STACK
{
    node a;
}stack;

typedef struct QUEUE
{
    node b;
}queue;

void getnode(node *n)
{
    *n = (struct NODE *)malloc(sizeof(struct NODE));
}

void insert(node *n, int pos, int x)
{
    //if position is neg or exceeds the num of elements in list, insert end
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

void insertfront(node *n, int x)
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

int delete(node *n, int pos)
{
    while (*n != NULL && pos != 0)
    {
        n = &((*n)->next);
        pos--;
    }
    if (pos == 0)
    {
        node temp = *n;
        *n = (*n)->next;
        free(temp);
    }
    return -1;
}

int deletevalue(node *n, int x)
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

int popf(node *n)
{
    //returns -1 if linked list is empty
    if (*n == NULL)
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
    if (*n == NULL)
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

int basic_main()
{
    //this is an implementation of basic linked list
    //for insertion and deletion, the program asks the user for the position 
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
            printf("%d elements deleted\n", deletevalue(&a, d));
        }
        else
        {
            return 0;
        }
    }
    return -1;
}

int stack_main()
{
    return -1;
}

int queue_main()
{
    return -1;
}

int main()
{
    //choice allows you to choose if you want to implement a stack or queue or just use the linked list
    //basic_main(), stack_main() etc. can also be used as the main function if you want just one implementations
    //to do that rename those functions to main() and delete the current main function

    int choice;
    printf("1 - basic, 2 - stack, 3 - circ queue\n");
    scanf("%d", &choice);

    if (choice == 1)
    {
        return basic_main();
    }
    else 
    {
        return 0;
    }
}
