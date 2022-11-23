//swap two numbers
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b, temp;
    printf("Enter two numbers :\n");
    scanf("%d%d",&a,&b);
    temp =a;
    a=b;
    b= temp;
    printf("a - %d\nb - %d\n", a, b);
    return 0;
}
