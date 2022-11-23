#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[100], *str;
    printf("Enter a string : ");
    scanf("%s", s);
    str = s;

    int i = 0;
    while(*str != 0){
        i++;
        str++;
    }

    printf("\nThe length of the string is : %d", i);

    return 0;
}
