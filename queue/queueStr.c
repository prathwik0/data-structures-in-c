#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct{
    int front;
    int rear;
    int q[MAX];
}queue;


void enqueue(queue *Q, int x)
{
    if (Q->front == -1){
        Q->front = 0;
        Q->q[++Q->rear] = x;
    }
    else if (Q->rear == MAX - 1)
    {
        printf("Queue overflow!\n");
    }
    else
    {
        Q->q[++Q->rear] = x;
    }
}

int dequeue(queue *Q)
{
    if (Q->front == -1)
    {
        printf("Queue empty, can't dequeue!\n");
        return -1;
    }

    if (Q->front == Q->rear)
    {
        int temp = Q->front;
        Q->front = -1;
        Q->rear = -1;
        return Q->q[temp];
    }
    else
    {
        return Q->q[Q->front++];
    }
}

void display(queue *Q){
    if (Q->front == -1)
        return;

    for (int i = Q->front; i <= Q->rear; i++){
        printf("%d ", Q->q[i]);
    }
    printf("\n");
}

void arrange(queue *Q){
    for (int i = Q->front; i <= Q->rear; i++)
    {
        Q->q[i - Q->front] = Q->q[i]; 
    }
    Q->rear = Q->rear - Q->front;
    Q->front = 0;

    printf("Queue arranged! front = %d rear = %d\n", Q->front, Q->rear);
    display(Q);
}

int main(){
    
    queue q;
    q.front = -1;
    q.rear = -1;

    int ch, x;

    while(1){
        printf("Enqueue(1),Dequeue(2),Display(3): ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            scanf("%d", &x);
            enqueue(&q, x);
            break;
        case 2:
            printf("dequeued %d\n", dequeue(&q));
            break;
        case 3:
            display(&q);
            break;
        default:
            exit(0);
        }
    }
    return 0;
}