#include <stdio.h>
#include <stdlib.h>

int front = -1;
int back = -2;
const int n = 5;
int arr[n];
int full = 0;

void enqueue(int val)
{
    //initialises the queue if not already initialized
    if (front == -1){
        front = 0;
        back = 0;
        arr[back] = val;
    }
    //queue full : (back + 1)%n = front
    else if((back + 1)%n == front) {
        full = 1;
        printf("Queue overflow! \n");
    }
    //inserts the element in the queue
    else 
    {
        back = (back + 1)%n;
        arr[back] = val;
    }
}

int dequeue()
{
    //returns 0 if the queue is empty
    if (front == -1){
        printf("The queue is empty\n");
        return 0;
    }
    //if there is only one element left, it returns the element and resets the queue
    else if (front == back)
    {
        printf("This is the last element from the queue\n");
        int temp = front;
        front = -1;
        back = -2;
        return arr[temp];
    }
    //dequeues the element
    else
    {
        int temp = front;
        front = (front + 1)%n;
        return arr[temp];
    }

}

//prints the queue
/*
void display(){
    if (front < 0)
        return;

    int i = front;
    printf("%d ", arr[i]);
    i = (i+1)%n;
    for (; i != (back + 1)%n; i = (i+1)%n){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
*/

//prints the queue

void display(){
    if (front < 0)
        return;

    int i = front;
    do
    {
        printf("%d ", arr[i]);
        i = (i+1)%n;
    } while (i != (back + 1)%n);
    printf("\n");
}


int main(){
    int val = 1;
    while(1){
        printf("Enqueue(1),Dequeue(2),DISPLAY(3): ");
        scanf("%d", &val);

        if (val == 1){
            int temp;
            printf("Enter val to push : ");
            scanf("%d", &temp);
            enqueue(temp);
        }else if (val == 2){
            printf("dequeued value : %d \n", dequeue());
        }else if (val == 3){
            display();
        }else{
            break;
        }
    }
    return 0;
}