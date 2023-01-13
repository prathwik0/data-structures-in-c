#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
    struct NODE *left;
    struct NODE *right;
    int data;
}*node;

typedef struct
{
    node head;
    node tail;
}list;

void getnode(node *n,int data)
{
    *n=(struct NODE *)malloc(sizeof(struct NODE));
    (*n)->data=data;
}

void insert_element(list *l,int data)
{
    node cur;
    cur=l->head;
    if(cur==NULL)
    {
        getnode(&cur,data);
        cur->right=cur;
        cur->left=cur;
        l->head=cur;
        l->tail=cur;
        return;
    }
    getnode(&cur,data);
    cur->right=l->head;
    cur->left=l->tail;
    l->head->left=cur;
    l->tail->right=cur;
    l->head=cur;
}

void display(list *l)
{
    node cur=l->head;

    do{
        printf("%d ",cur->data);
        cur=cur->right;
    }while(cur!=l->tail);

    printf("%d\n",l->tail->data);
}

void delete_element(list *l,int data)
{
    node cur=l->head;

    if(cur==NULL)
    {
        printf("Nothing to Delete");
        return;
    }

    if(cur->data==data && cur->right==cur)
    {
        free(cur);
        l->head=NULL;
        l->tail=NULL;
        return;
    }

    if(l->head->data==data)
    {
        printf("Check");
        l->tail->right=cur->right;
        cur->right->left=l->tail;
        free(cur);
        l->head=l->tail->right;
        return;
    }
    
    cur=cur->right;

    while(cur!=l->head && cur->data!=data)
    {
        cur=cur->right;
    }

    if(cur==l->head)
    {
        printf("Not Found");
        return;
    }

    cur->left=cur->right;
    cur->right=cur->left;
    free(cur);
    l->tail=l->head->left;
}



int main()
{
    list l;
    l.head=NULL;
    l.tail=NULL;
    insert_element(&l,10);
    insert_element(&l,20);
    insert_element(&l,30);
    insert_element(&l,40);
    insert_element(&l,50);
    insert_element(&l,60);
    display(&l);
    delete_element(&l,10);
    display(&l);
    return 0;
}
