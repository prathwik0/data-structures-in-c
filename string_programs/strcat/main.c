#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s1[100], s2[100], s3[200];
    printf("Enter two strings : ");
    scanf("%s%s", s1, s2);

    int  i = 0, j = 0;
    while(s1[i] != 0){
        s3[i] = s1[i];
        i++;
    }
    while(s2[j] != 0){
        s3[i] = s2[j];
        j++;
        i++;
    }
    s3[i+1] = 0;


    printf("\nThe concatenated string is : %s", s3);

    return 0;
}
