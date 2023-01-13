#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

int main()
{
    char string[100];

    printf("Enter string: ");
    scanf(" %s", string);

    int len = strlen(string);

    for (int i = 0; i < len; i++)
    {
        push(string[i]);
    }

<<<<<<< Updated upstream:kaustub/palindrome.c
    /*for(int i=0;top!=-1;i++)
    printf("%c",stack[i]);*/
    for (int i = 0; top != -1; i++)
    {
        if (string[i] != pop())
=======
    for(int i=0;top!=-1;i++){
        if(string[i]!=pop())
>>>>>>> Stashed changes:palindrome.c
        {
            printf("Not a Palindrome");
            exit(0);
        }
    }
    printf("Given string is a Palindrome");
    return 0;
}