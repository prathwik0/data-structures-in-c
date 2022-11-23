#include <stdio.h>
#include <stdlib.h>

void strcpy(char *s1, char *s2);

int main()
{
    char s1[100], s2[100];
    printf("Enter a string : ");
    scanf("%s", s1);

    strcpy(s1,s2);

    printf("\nThe copied string is : %s", s2);

    return 0;
}

void strcpy(char *s1, char *s2){
    while(*s1 != '\0')
        *s2++ = *s1++;
    s2++;
    *s2 = '\0';
}
