#include <stdio.h>
#include <stdlib.h>

//this structure defines the data
typedef struct
{
    int value;
}data;

//this inserts the data x into location indicated by data pointer d
void insertdata(data *d, data x)
{
    d->value = x.value;
}

//this returns the data with all values set to null or zero
data getnull()
{
    data d;
    d.value = 0;
    return d;
}

//this asks the user to input the data and return it
data getdata()
{
    data d;
    printf("Enter data                          : ");
    scanf("%d", &d.value);
    return d;
}

//this function should return 1 if the given inputs are identical
//else return 0
int datacmp(data x, data y)
{
    if (x.value == y.value)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

//this prints the data as required
void printdata(data d)
{
    printf("%d ", d.value);
}

//below, linked list is implemented for the data (which was defined above)

typedef struct NODE
{
    data d;
    struct NODE *next;
}*node;

void getnode(node *n);

void display(node n);

void insert(node *n, int pos, data x);
void insertfront(node *n, data x);
void insertend(node *n, data x);

data delete(node *n, int pos);
int deletevalue(node *n, data x);

void getnode(node *n)
{
    *n = (struct NODE *)malloc(sizeof(struct NODE));
}

void insert(node *n, int pos, data x)
{
    //if position is neg or exceeds the num of elements in list, insert end
    while(*n != NULL && pos != 0)
    {
        n = &((*n)->next);
        pos--;
    }
    node temp = *n;
    getnode(n);
    insertdata(&((*n)->d) ,x);
    (*n)->next = temp;
}

void insertfront(node *n, data x)
{
    node temp = *n;
    getnode(n);
    (*n)->d = x;
    (*n)->next = temp;
}

void insertend(node *n, data x)
{
    while(*n != NULL)
        n = &((*n)->next);
    getnode(n);
    (*n)->d = x;
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
        printf("-> ");
        printdata(n->d);
        n = n->next;
    }

    printf("\n\n");
}

data delete(node *n, int pos)
{
    //this checks for list empty condition
    if(*n == NULL)
    {
        //the list is empty, cant delete
        data d = getnull();
        return d;
    }

    //if position is neg or exceeds the num of elements in list, delete end
    while ((*n)->next != NULL && pos != 0)
    {
        n = &((*n)->next);
        pos--;
    }
    node temp = *n;
    data temp2 = temp->d;
    *n = (*n)->next;
    free(temp);
    return temp2;
}

int deletevalue(node *n, data x) 
{
    int count = 0;
    while(*n != NULL)
    {
        if (datacmp(x, (*n)->d))
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
    //this is an implementation of basic linked list
    //currently, for insertion and deletion, the program asks the user for the position 
    node a = NULL;

    while (1)
    {
        int n;
        printf("1 - insert, 2 - display, 3 - delete : ");
        scanf("%d", &n);

        if (n == 1)
        {
            data d = getdata();

            //use the following to insert at the front
            //insertfront(&a, d);
            //use the following to insert at the end
            //insertback(&a, d);

            //use the following to insert in user input position
            //for insert at front input pos = 0
            //for end input pos = negative (or pos exceeds number of elements in the list)
            int pos;
            printf("Enter position                      : ");
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
            //use the following to delete user input value(s) from the list
            data d = getdata();
            printf("%d elements deleted\n", deletevalue(&a, d));

            //use the following to delete from the front
            //delete(&a, 0);
            //use the following to delete from the end
            //delete(&a, -1);

            //use the following to delete from user input position
            //for delete at front input pos = 0
            //for end input pos = negative (or pos exceeds number of elements in the list)
            /* int pos;
            printf("Enter position                      : ");
            scanf("%d", &pos);
            printf("\n");
            delete(&a, pos);*/
        }
        else
        {
            return 0;
        }
    }
}
