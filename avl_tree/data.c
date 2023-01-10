#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "data.h"

void printData(data x)
{
    printf("%d", x->i);
}

int dataCmp(data x, data y)
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

data getData(int n)
{
    /*gives the seed for the rng*/
    time_t t;
    srand((unsigned)time(&t));

    data x = (struct DATA *)malloc(sizeof(struct DATA) * n);

    for (int i = 0; i < n; i++)
    {
        x[i].i = rand() % 1000000;
    }

    return x;
}

data getBadData(int n)
{
    data x = (struct DATA *)malloc(sizeof(struct DATA) * n);

    for (int i = 0; i < n; i++)
    {
        x[i].i = i;
    }

    return x;
}
