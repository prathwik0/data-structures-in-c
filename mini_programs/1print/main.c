//print an integer, float, character
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    float b;
    char c;

    printf("Enter int, float and char :\n");
    scanf("%d %f %c", &a,&b,&c);
    printf("int : %d\nfloat : %f\nchar : %c\n", a, b, c);
    return 0;
}
