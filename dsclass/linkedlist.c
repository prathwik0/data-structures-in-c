#include<stdio.h>
#include<stdlib.h>


struct NODE{
    int data;
    struct NODE *next;
};

typedef struct NODE *node;

void insert(node *s, int x){

}


int main(){
    int a;
    while(1){
        printf("Enter the choice: 1 for insert\n2 for deleting a specific item\n4 for display\n5 for exit\n");
        scanf("%d",&a);
        if(a==1)
        lastinsert();
        else if(a==2)
        firstinsert();
        else if(a==3)
        delete();
        else if(a==4)
        display();
        else 
        exit(0);
    }
    return 0;
}
    

