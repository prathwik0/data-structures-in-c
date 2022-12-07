#include <stdio.h>
#include <stdlib.h>

void strcat(char *s, char *s1, char *s2);

int main()
{
    char s1[100], s2[100], s3[200];
    printf("Enter two strings : ");
    scanf("%s%s", s1, s2);

    strcat(s3,s1,s2);

    printf("\nThe concatenated string is : %s", s3);

    return 0;
}

void strcat(char *s, char *s1, char *s2){
    while(*s1 != 0)
        *s++ = *s1++;
    while(*s2 != 0)
        *s++ = *s2++;
    *(++s) = '\0';
}
