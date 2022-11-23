#include <stdio.h>
#include <stdlib.h>

int pos = -1;
int a[10];

void push(int c)
{
    if (pos < 0){
        a[0] = c;
        pos = 0;
    }
    else{
        pos++;
        a[pos] = c;
    }
}

int pop()
{
    if (pos < 0)
        return 0;
    int x = a[pos];
    //printf("\npos = %d value = %d", pos, x);
    pos--;
    return x;
}

void display(){
    for (int i = 0; i <= pos; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(){
    int val = 1;
    while(1){
        printf("PUSH(1),POP(2),DISPLAY(3): ");
        scanf("%d", &val);

        if (val == 1){
            int temp;
            printf("Enter val to push : ");
            scanf("%d", &temp);
            push(temp);
        }else if (val == 2){
            printf("Popped value : %d \n", pop());
        }else if (val == 3){
            display();
        }
        else{
            break;
        }
    }
    return 0;
}