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
    printf("Enter data                            : ");
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

//the stack is defined as a structure named stack
typedef struct 
{
    node front; //in this queue, front is where the new elements are inserted
    node rear;  //in this queue, rear is where the elements are dequeued
}queue;

void display(node n);
void displayqueue(queue q);

void enqueue(queue *q, data x);
data dequeue(queue *q);

//the following is the main function
int main()
{
    //this is an implementation of queue using linked-list
    
    queue q;
    q.front = NULL;
    q.rear = NULL;

    while (1)
    {
        int n;
        printf("1 - enqueue, 2 - display, 3 - dequeue : ");
        scanf("%d", &n);

        if (n == 1)
        {
            data d = getdata();
            //use the following to enqueue
            enqueue(&q, d);
        }
        else if (n == 2)
        {
            //circular queue obviously requires another diplay function 
            //but its fun to look at the output created by the regular display function!
            //display(q.rear);

            displayqueue(q);
        }
        else if (n == 3)
        {
            //the following dequeues last element and prints it
            printf("dequeued element : ");
            printdata(dequeue(&q));
            printf("\n\n");
        }
        else
        {
            return 0;
        }
    }
}

void enqueue(queue *q, data x)
{
    //this initializes the queue if there are no elements
    if (q->front == NULL)
    {
        //this gives a node to the front
        getnode(&(q->front));
        //the following sets up the circular queue
        q->front->next = q->front;
        //this initializes the rear
        q->rear = q->front->next; //here q->front is same as q->front->next but the way i hve written is easier to visualize

        insertdata(&(q->front->d), x);
    }
    else
    {
        getnode(&(q->front->next));

        insertdata(&(q->front->next->d), x);
        q->front->next->next = q->rear;

        //this sets front to the new front 
        q->front = q->front->next;

        //we could have done the above before initializing the new node but 
        //but then I wouldn't get to use ...->...->...->...
    }
}

data dequeue(queue *q)
{
    if (q->front == NULL)
    {
        return getnull();
    }

    if (q->rear == q->front)
    {
        data temp = q->front->d;
        free(q->front);
        q->front = NULL;
        q->rear = NULL;
        return temp;
    }

    q->rear = q->rear->next;

    data temp = q->front->next->d;
    free(q->front->next);
    q->front->next = q->rear;

    return temp;
}

void displayqueue(queue q)
{
    if (q.front == NULL)
    {
        printf("no elements present\n\n");
        return;
    }

    while (q.front != q.rear)
    {
        printdata(q.rear->d);
        printf("<- ");
        q.rear = q.rear->next;
    }
    printdata(q.rear->d);

    printf("\n\n");
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
