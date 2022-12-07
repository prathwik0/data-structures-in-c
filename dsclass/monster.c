# include <stdio.h>
void main()
{
    int a[5]= {10, 20, 30, 40, 50};
    printf("%p%p%p\n", &a[0], a, a+2);
}