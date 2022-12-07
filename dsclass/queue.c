#include <stdio.h>
#include <stdlib.h>

int front = -1;
int back = -2;
const int max = 100;
int arr[max];

void enqueue(int val)
{
    //initialises the queue if not already initialized
    if (front == -1){
        front = 0;
        back = 0;
        arr[back] = val;
    }
    else if (back < max){
        back++;
        arr[back] = val;
    }else{
        printf("Queue overflow! Consider ARRANGE\n");
    }
}

int dequeue()
{
    if (front < back){
        front++;
        printf("front = %d ", front);
        return arr[front - 1];
    }else if (front == back){
        printf("The queue is now empty\n");
        int temp = front;
        front = -1;
        back = -2;
        return arr[temp];
    }
    printf("The queue is empty\n");
    return 0;
}

void display(){
    for (int i = front; i <= back; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void arrange(){
    if(front > 0){
        for (int i = front; i <= back; i++){
            arr[i - front] = arr[i]; 
        }
        back = back - front;
        front = 0;

        printf("The queue is now arranged! front = %d back = %d\n", front, back);
        display();
    }
}

int main(){
    int val = 1;
    while(1){
        printf("Enqueue(1),Dequeue(2),DISPLAY(3),ARRANGE(4): ");
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
        }else if (val == 4){
            arrange();
        }
        else{
            break;
        }
    }
    return 0;
}