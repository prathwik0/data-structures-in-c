//reverse of a number
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    printf("Enter a number :\n");
    scanf("%d", &a);

    int temp1 = a, temp2 = 0;

    while (temp1 != 0){
        temp2 = temp2*10 + temp1%10;
        temp1 = temp1/10;
    }

    printf("The reverse of %d is %d\n", a, temp2);

    return 0;
}
