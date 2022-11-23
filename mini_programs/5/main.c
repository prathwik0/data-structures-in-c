//size of int float double and char
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 1;
    float b = 4.5;
    double c = 5.33;
    char d = "a";
    printf("Size of int : %d\n", sizeof(a));
    printf("Size of float : %d\n", sizeof(b));
    printf("Size of double : %d\n", sizeof(c));
    printf("Size of char : %d\n", sizeof(d));
    return 0;
}
