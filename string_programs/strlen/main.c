#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[100];
    printf("Enter a string : ");
    scanf("%s", s);

    int  i = 0;
    while(s[i] != 0){
        i++;
    }

    printf("\nThe length of the string is : %d", i);

    return 0;
}
