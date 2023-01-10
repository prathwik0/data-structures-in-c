#include <stdio.h>
#include "data.h"

void printdata(data x)
{
    printf("%d", x->i);
}

int datacmp(data x, data y)
{
    if (x->i == y->i)
    {
        return 0;
    }
    else if (x->i > y->i)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
