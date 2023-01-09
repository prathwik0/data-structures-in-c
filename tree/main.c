#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "treeNode.h"
#include "traversal.h"
#include "print2D.h"
#include "insert.h"
#include "search.h"

int main()
{
    // this displays the time taken for the function to execute
    // start the clock
    clock_t start, end;
    double elapsed;
    start = clock();

    /*gives the seed for the rng*/
    time_t t;
    srand((unsigned)time(&t));

    // initializes the root node
    node root = NULL;

    // gets 25 integers
    int num[25];
    for (int i = 0; i < 25; i++)
    {
        num[i] = rand() % 1000;
    }

    for (int i = 0; i < 10; i++)
    {
        printf("inserted %d\n", num[i]);
        insert(&root, num[i]);
    }

    printf("\nPreorder:   ");
    preorder(root);

    printf("\nPostorder:  ");
    postorder(root);

    printf("\nInorder:    ");
    inorder(root);

    printf("\nLevelorder: ");
    levelorder(root);

    printf("\n2D: ");
    print2D(root);

    printf("\n\n");

    // search for a node and print the result
    node temp;
    temp = rsearch(root, 100);
    if (temp == NULL)
        printf("100 was not found\n");
    else
        printf("Node found - %d\n", temp->data);

    temp = rsearch(root, num[3]);
    if (temp == NULL)
        printf("%d was not found\n", num[3]);
    else
        printf("Node found - %d\n", temp->data);

    // stop the clock and calculate elapsed time
    end = clock();
    elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Elapsed time: %f seconds\n", elapsed);

    return 0;
}