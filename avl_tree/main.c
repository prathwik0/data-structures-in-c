#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "treeNode.h"
#include "data.h"
#include "insert.h"
#include "print2D.h"

int main()
{
    // this displays the time taken for the function to execute
    // start the clock
    clock_t start, end;
    double elapsed;
    start = clock();

    node root = NULL;

    data x = getBadData(100000);

    // for (int i = 0; i < 100000; i++)
    // {
    //     printf("-- > %d\n", x[i].i);
    // }

    for (int i = 0; i < 10000; i++)
    {
        insert(&root, x + i);
    }

    // print2D(root);

    // stop the clock and calculate elapsed time
    end = clock();
    elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Elapsed time: %f seconds\n", elapsed);

    return 0;
}