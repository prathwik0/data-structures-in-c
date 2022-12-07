//sum of n numbers
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, sum = 0, temp;
    printf("enter the number of entries : \n");
    scanf("%d", &n);

    for (int i = 0; i < n; i ++){
        printf("Enter number :\n");
        scanf("%d", &temp);
        sum += temp;

    }

    printf("Your final sum is : %d", sum);

    return 0;
}
