#include <stdio.h>
#include <stdlib.h>

void strrev(char *rev, char *s);

int main()
{
    char s[100], rev[100];
    printf("Enter a string : ");
    scanf("%s", s);

    strrev(rev, s);

    printf("\nThe reverse of string is : %s", rev);

    return 0;
}

/*
void strrev(char *rev, char *s){
    int i = 0;
    while(*s != 0){
        s++;
        i++;
    }
    s--;
    while(i != 0){
        *rev++ = *s--;
        i--;
    }
    rev++;
    *rev = '\0';
}
*/

//or

void strrev(char *rev, char *s){
    char *temp;
    temp = s;
    while(*s != 0)
        s++;
    s--;
    while(s != temp)
        *rev++ = *s--;
    *rev++ = *temp;
    rev++;
    *rev = '\0';
}
