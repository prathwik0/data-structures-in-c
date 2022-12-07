#include <stdio.h>

int main ()
{
    int a[][3] = {
        1,2,3,4,
        5,6,7,8,
        9,0,0,0
    };
    
    printf("%d\n", sizeof(a));
    printf("%d\n", sizeof(a[1]));

    return 0;
}