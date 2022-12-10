#include <stdio.h>
#include <stdlib.h>

//created by prathwik0
//feel free to modify or use this program in any way you desire
//
//In this linked list program, we define a custom datatype called data
//data is a structure which can have anything inside e.g. student details
//Currently data is a structure consisting of a just single integer named value
//The benefit of using this approach is that we wouldn't need to 
//change the linked list program even if we change the data definition
//
//user of this program can change the code accordingly to use whatever data they prefer
//they would also change the following functions accordingly
//
// data getdata() -- this function asks the user for the data and returns it
// data getnull() -- this function is similar to the previous one but it returns data initialized as 0 or null
// 
// void insertdata(data *d, data x) -- this function copies the data x to the location indicated by the pointer *d
// int datacmp(data x, data y) -- returns 1 if x and y are identical, else returns 0
// void printdata(data d) -- prints the data

//the following structure defines data
typedef struct
{
    int value;
}data;

//this asks the user to input the data and return it
data getdata()
{
    data d;
    printf("Enter data                          : ");
    scanf("%d", &d.value);
    return d;
}

//this returns the data with all values set to null or zero
data getnull()
{
    data d;
    d.value = 0;
    return d;
}

//this inserts the data x into location indicated by data pointer d
void insertdata(data *d, data x)
{
    d->value = x.value;
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

//----------------------------------------------------------------------//
//below, linked list is implemented for the data (which was defined above)

// this defines node to be a pointer to a structure NODE which consists of data d and pointer to the next NODE
// note the following is defined opposite of the convention where NODE is the pointer and node is the structure
// here node represents the pointer and NODE represents the structure
typedef struct NODE
{
    data d;
    struct NODE *next;
}*node;

//this function allocates a NODE from heap to the node pointer *n
//note *n is a pointer to a pointer to the structure NODE
//this is how this function should be called : getnode(&n); where n is a pointer to NODE
void getnode(node *n)
{
    *n = (struct NODE *)malloc(sizeof(struct NODE));
}

//this function prints each element of the linked list
//if there are no elements, it prints: no elements present
void display(node n);

//these are the functions that can be used adding a node to the linked list
//insert function inserts the element at the specified position pos
//if pos is negative it inserts at the end
//
//insertfront and insertend are selfexplanatory
void insert(node *n, int pos, data x);
void insertfront(node *n, data x);
void insertend(node *n, data x);


//these are the functions that can be used to delete a node in the linked list
//delete function deletes the element at the specified position pos and returns the deleted data
//if pos is negative the last element is deleted
//
//if there are no elements in the linked list, function returns data with all values set to NULL or zero
//
//deletevalue function deletes all instances of the input data x if it is present in the linked list
//it returns a count of number of elements deleted
//if there is not match, it doen't delete anything and returns a count of zero
data delete(node *n, int pos);
int deletevalue(node *n, data x);

//the following is the main function
int main()
{
    //this is an implementation linked list
    
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

// NOTE: all the following functions other than display take node *n as one of the inputs
// be careful while using node *n 
//
// inside the function n represents the local variable
// all changes to n affects only the local variable n, the linked list will not be affected
//
// **********************************************************************************
// but *n is not a local variable, all changes made to *n will modify the linked list
// **********************************************************************************

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
    insertdata(&((*n)->d) ,x);
    (*n)->next = temp;
}

void insertend(node *n, data x)
{
    while(*n != NULL)
        n = &((*n)->next);
    node temp = *n;
    getnode(n);
    insertdata(&((*n)->d) ,x);
    (*n)->next = temp;
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

    //if position is neg or exceeds the num of elements in list, deletes the last node
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

