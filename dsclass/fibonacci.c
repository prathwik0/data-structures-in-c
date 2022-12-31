#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n)
{
    if (n == 1)
        return 1;
    if (n == 0)
        return 0;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("The nth term of fibonacci series is: %d", fibonacci(n));
}