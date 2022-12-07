#include <stdio.h>
#include <stdlib.h>

int MAX = 10;
int a[10];
int pos = -1;

void push(int x){
    if(pos == MAX - 1){
        printf("The stack if full\n%d was not pushed\n", x);
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
        int choice = -1, x;
        printf("Enter 0 to push, 1 to pop, 2 to display : \n");
        scanf("%d", &choice);

        if (choice == 0){
            printf("Enter number to push : ");
            scanf("%d", &x);
            push(x);
        }else if(choice == 1){
            x = pop();
            printf("The popped value is : %d\n", x);
        }else if (choice == 2){
            display();
        }else{
            break;
        }
    }
}
