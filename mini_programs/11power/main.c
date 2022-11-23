#include <stdio.h>
#include <stdlib.h>
#import <math.h>

int main()
{
    int n,p,pwr = 1;
    printf("Enter a number and the power :\n");
    scanf("%d%d", &n ,&p );

    for(int i = 1; i <= p; i++)
        pwr = pwr*n;

    printf("The power without built in functions is : %d\n", pwr);

    printf("The power with built in functions is : %d", pow(2,4));

    return 0;
}
