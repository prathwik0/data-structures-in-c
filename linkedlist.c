#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int data;
    struct NODE *next;
}*node;

typedef struct STACK
{
    node n;
}stack;

typedef struct QUEUE
{
    node enter;
    node exit;
}queue;

void getnode(node *n);

void display(node n);

void insert(node *n, int pos, int x);
void insertfront(node *n, int x);
void insertend(node *n, int x);

int delete(node *n, int pos);
int deletevalue(node *n, int x);

int basic_main();

void push(stack *a, int d);
int pop(stack *a);
int stack_main();

void enqueue(queue *a, int d);
int dequeue(queue *a);
void dispQueue(queue a);
int queue_main();

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
    else if (choice == 2)
    {
        return stack_main();
    }
    else if (choice == 3)
    {
        return queue_main();
    }
    else 
    {
        return 0;
    }
}

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

void display(node n)
{
    //this prints a message for empty linked-list
    if(n == NULL)
    {
        printf("no elements present");
    }
    
    while(n != NULL)
    {
        printf("%d ->", n->data);
        n = n->next;
    }

    printf("\n");
}

int delete(node *n, int pos)
{
    //this checks for list empty condition
    if(*n == NULL)
    {
        //the list is empty, cant delete
        return -1;
    }

    //if position is neg or exceeds the num of elements in list, delete end
    while ((*n)->next != NULL && pos != 0)
    {
        n = &((*n)->next);
        pos--;
    }
    node temp = *n;
    int temp2 = temp->data;
    *n = (*n)->next;
    free(temp);
    return temp2;
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

int basic_main()
{
    //this is an implementation of basic linked list
    //currently, for insertion and deletion, the program asks the user for the position 
    node a = NULL;

    while (1)
    {
        int n;
        printf("1 - insert, 2 - display, 3 - delete: ");
        scanf("%d", &n);

        if (n == 1)
        {
            int d;
            printf("Enter data: ");
            scanf("%d", &d);

            //use the following to insert at the front
            //insertfront(&a, d);

            //use the following to insert at the end
            //insertback(&a, d);

            //use the following to insert in user input position
            //for insert at front input pos = 0, for end input pos = negative (or pos exceeds number of elements in the list)
            int pos;
            printf("Enter position: ");
            scanf("%d", &pos);
            insert(&a, pos, d);
        }
        else if (n == 2)
        {
            display(a);
        }
        else if (n == 3)
        {
            //use the following to delete user input value(s) from the list
            /*int d;
            printf("Enter int: ");
            scanf("%d", &d);
            printf("%d elements deleted\n", deletevalue(&a, d));*/

            //use the following to delete from user input position
            //for delete at front input pos = 0, for end input pos = negative (or pos exceeds number of elements in the list)
            int pos;
            printf("Enter position: ");
            scanf("%d", &pos);
            delete(&a, pos);
        }
        else
        {
            return 0;
        }
    }
}

void push(stack *a, int d)
{
    insert(&(a->n), 0, d);
}

int pop(stack *a)
{
    return delete(&(a->n), 0);
}

int stack_main()
{
    //this is an implementation of stack using linked-lists
    stack a;
    a.n = NULL;

    while (1)
    {
        int n;
        printf("1 - push, 2 - display, 3 - pop: ");
        scanf("%d", &n);

        if (n == 1)
        {
            int d;
            printf("Enter data: ");
            scanf("%d", &d);
            push(&a, d);
        }
        else if (n == 2)
        {
            display(a.n);
        }
        else if (n == 3)
        {
            printf("Popped: %d\n", pop(&a));
        }
        else
        {
            return 0;
        }
    }
}

void enqueue(queue *a, int d)
{
    if (a->enter == NULL)
    {
        getnode(&(a->enter));
        
        a->enter->next = a->enter;
        a->exit = a->enter->next;

        a->enter->data = d;
    }
    else 
    {
        insert(&(a->enter), 1, d);
        a->enter = a->enter->next;
    }
}

int dequeue(queue *a)
{
    if (a->enter == NULL)
    {
        return -1;
    }
    else if (a->enter == a->exit)
    {
        int temp = a->enter->data;
        free(a->enter);
        a->enter = NULL;
        a->exit = NULL;
        return temp;
    }
    else
    {
        a->exit = a->exit->next;
        return delete(&(a->enter), 1);
    }
}

void dispQueue(queue a)
{
    //this prints a message for empty queue
    if(a.enter == NULL)
    {
        printf("no elements present");
    }
    
    while(a.exit != a.enter)
    {
        printf("%d <- ", a.exit->data);
        a.exit = a.exit->next;
    }
    printf("%d", a.enter->data);
    printf("\n");
}

int queue_main()
{
    //this is an implementation of circular queue
    queue a;
    a.enter = NULL;
    a.exit = NULL;

    while (1)
    {
        int n;
        printf("1 - enqueue, 2 - display, 3 - dequeue: ");
        scanf("%d", &n);

        if (n == 1)
        {
            int d;
            printf("Enter data: ");
            scanf("%d", &d);
            enqueue(&a, d);
        }
        else if (n == 2)
        {
            dispQueue(a);
        }
        else if (n == 3)
        {
            printf("Dequeued: %d\n", dequeue(&a));
        }
        else
        {
            return 0;
        }
    }
}
