//number of digits in a integer
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    printf("Enter a integer :\n");
    scanf("%d", &a);

    int n = 0, temp = a;

    while (temp != 0){
    temp = temp/10;
    n++;
    }

    printf("The number of digits in %d is %d\n", a, n);

    return 0;
}
