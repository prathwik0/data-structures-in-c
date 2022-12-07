//fibonacci series
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the number of terms in the fibonacci series you need : \n");
    scanf("%d", &n);

    int a = 0, b = 1, temp;

    for (int i = 0; i < n; i ++){
        printf("%d\n", a);
        temp = b;
        b = a + b;
        a = temp;
    }

    return 0;
}
