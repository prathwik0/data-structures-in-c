#include <stdio.h>

int const MAX = 4;

int main ()
{
    char *names[] = {
        "Zara Ali  a",
        "Hina Alia",
        "Nuha Ali",
        "Sara Ali"
    };

    char *a = "fuck c";

    printf("%s\n", a);
    printf("%lu\n", sizeof(a));

    printf("%d\n", sizeof(names));
    printf("%d\n", sizeof(names[1]));

    int i = 0;
    for (i = 0; i < MAX; i++)
    {
        printf("Value of names[%d]=%s\n",i,names[i]);
    }
    return 0;
}