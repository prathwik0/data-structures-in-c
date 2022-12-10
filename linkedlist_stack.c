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
    printf("Enter data                     : ");
    scanf("%d", &d.value);
    printf("\n");
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

//the stack is defined as a structure named stack
typedef struct 
{
    node head;
}stack;

//push function inserts the element at start of the list
//it is similar to insertfront function in linkedlist_pure
void push(stack *s, data x);

//pop function deletes the element at the specified position pos and returns the deleted data
//if pos is negative the last element is deleted
//it is similar to deletefront function in linkedlist_pure
//if there are no elements in the linked list, function returns data with all values set to NULL or zero
data pop(stack *s);

//the following is the main function
int main()
{
    //this is an implementation of stack using linked list
    
    stack s;
    s.head = NULL;

    while (1)
    {
        int n;
        printf("1 - push, 2 - display, 3 - pop : ");
        scanf("%d", &n);

        if (n == 1)
        {
            data d = getdata();

            //use the following to push
            push(&s, d);
        }
        else if (n == 2)
        {
            display(s.head);
        }
        else if (n == 3)
        {
            //the following pops the top of stack and prints it
            printf("popped element : ");
            printdata(pop(&s));
            printf("\n\n");
        }
        else
        {
            return 0;
        }
    }
}

void push(stack *s, data x)
{
    node temp = s->head;
    getnode(&(s->head));
    insertdata(&(s->head->d) ,x);
    s->head->next = temp;
}


//I have used the same display function as in linked list and haven't written a new one
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

data pop(stack *s)
{
    //this checks for list empty condition
    if(s->head == NULL)
    {
        //the list is empty, cant delete
        data d = getnull();
        return d;
    }

    node temp = s->head;
    data temp2 = temp->d;
    s->head = s->head->next;
    free(temp);
    return temp2;
}
