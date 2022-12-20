#include <stdio.h>
#include <stdlib.h>

int MAX = 4;
int a[4];
int pos = -1;

void push(int x){
    if(pos == MAX - 1){
        printf("Stack Overflow\n");
    }else{
        pos++;
        a[pos] = x;
    }
}

int pop(){
    if (pos == -1){
        printf("Empty stack, can't pop\n");
        return -1;
    }else{
        int temp = a[pos];
        pos--;
        return temp;
    }
}

void display(){
    for(int i = 0; i <= pos; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(){
    while (1){
        int ch, x;
        printf("Enter 0 to push, 1 to pop, 2 to display : ");
        scanf("%d", &ch);

        if (ch == 0){
            scanf("%d", &x);
            push(x);
        }else if(ch == 1){
            x = pop();
            printf("popped %d\n", x);
        }else if (ch == 2){
            display();
        }else{
            break;
        }
    }
    return 0;
}
