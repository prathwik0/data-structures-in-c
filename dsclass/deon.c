#include <stdio.h>
#include <stdbool.h>

char a[10];
int ind=-1;
bool stackempty=true;

void push(char c){//To push an element a element into a stack.
    if(ind>=10){
        printf("Stack Overflow");
        return;

    }
    ind++;
    a[ind]=c;
    stackempty=false;
}

char pop(){//To remove an element
    ind--;
    if (ind==-1)
        stackempty=true;
    return a[ind+1];
}
int main() {
    int cho;
    char c;
    while(1){
        printf("Enter your choice(1 for push , 2 for pop and 3 to exit)=");
        scanf("%d",&cho);
        if (cho==1){
            printf("Enter the element=\n");
            scanf("%c",&c);
            push(c);
        }
        else if (cho==2){
            if (stackempty){
                printf("The stack is empty.Push some elements\n");
            }
            else
            {
                c=pop();
                printf("The element is %d",(int)c);
            }
        }
        else
            break;
        }
    }