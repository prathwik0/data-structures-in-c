#include <stdio.h>
#include <stdlib.h>

#define MAX 10

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
    else if ((Q->rear + 1) % MAX == Q->front)
    {
        printf("Queue overflow!\n");
    }
    else
    {
        Q->rear = (Q->rear + 1) % MAX;
        Q->q[Q->rear] = x;
    }
}

int dequeue(queue *Q)
{
    if (Q->front == -1)
    {
        printf("Queue empty!\n");
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
        int temp = Q->front;
        Q->front = (Q->front + 1) % MAX;
        return Q->q[temp];
    }
}

void display(queue *Q){
    if (Q->front == -1)
        return;

    int i = Q->front;
    printf("-> %d ", Q->q[i]);
    
    while (i != Q->rear)
    {
        i = (i + 1) % MAX;
        printf("-> %d ", Q->q[i]);
    }
    printf("\n");
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
        case 1: scanf("%d", &x);
                enqueue(&q, x);
                break;
        case 2: x = dequeue(&q);
                if (x != -1) printf("dequeued %d\n", x);
                break;
        case 3: display(&q);
                break;
        default: exit(0);
        }
    }
    return 0;
}
