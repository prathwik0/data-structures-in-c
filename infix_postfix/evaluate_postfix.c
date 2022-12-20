#include <stdio.h>
int top = -1, stack [100];

void push (int n){
   top++;
   stack [top] = n;
}

int pop (){
   int res ;
   res = stack [top];
   top--;
   return res;
}

int eval (char ch, int op1, int op2){
   switch (ch){
      case '+' : return (op1+op2);
      case '-' : return (op1-op2);
      case '*' : return (op1*op2);
      case '/' : return (op1/op2);
      default: return 0;
   }
}

int is_num(char ch){
    if(ch>='0' && ch<='9') return 1;
    else return 0;
}

int main (){
   char a[50];
   int i,op1,op2,res,x;

   printf("enter a postfix expression:");
   scanf("%s",a);
   //char a[] = {'3',' ', '5', ' ', '2', '*', ' ', '+', '\0'};

   for(i=0; a[i]!='\0'; i++)
   {
      char ch = a[i];
      if(is_num(ch))
         push(ch - '0');
      else if (ch != 32)
      {
         op2 = pop ( );
         op1 = pop ( );
         res = eval (ch, op1, op2);
         push (res);
      }
   }

   x = pop ( );
   printf("evaluated value = %d", x);
   return 0;
}

