//factorial of a number
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, fac = 1, temp;
    printf("enter the number : \n");
    scanf("%d", &a);

    for (int i = 1; i <= a; i ++){
        fac *= i;
    }

    printf("factorial is : %d", fac);

    return 0;
}
