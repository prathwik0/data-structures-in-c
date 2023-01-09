#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "treeNode.h"
#include "traversal.h"
#include "print2D.h"
#include "insert.h"

int main()
{
    /*gives the seed for the rng*/
    // time_t t;
    // srand((unsigned)time(&t));

    node root = NULL;

    // inserts 10 integers
    for (int i = 0; i < 10; i++)
    {
        int num = rand() % 100;
        printf("inserted %d\n", num);
        insert(&root, num);
    }

    //                 (3)
    //            /            \
    //         (2)              (5)
    //       /      \          /    \
    //    (1)        (4)     (-)     (-)
    //   /   \      /   \
    // (10) (11)  (12)  (13)

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

    return 0;
}