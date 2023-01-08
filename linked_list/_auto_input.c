#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "singly.h"

int main()
{
    /*gives the seed for the rng*/
    time_t t;
    srand((unsigned)time(&t));

    list a;
    a.front = NULL;

    // inserts 10 numbers in the list
    for (int i = 0; i < 10; i++)
    {
        int num = rand() % 100;
        printf("inserted %d\n", num);
        insertRear(&a, num);
    }
    display(&a);

    // deletes elements in the list
    for (int i = 0; i < 5; i++)
    {
        printf("deleted\n");
        deleteRear(&a);
    }
    display(&a);

    return 0;
}