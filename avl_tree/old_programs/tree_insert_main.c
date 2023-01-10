#include <stdio.h>
#include "print2D.h"
#include "tree_insert.h"

int main()
{
    node root = NULL;

    insert_with_arranging(&(root), 1);
    insert_with_arranging(&(root), 2);
    insert_with_arranging(&(root), 3);
    insert_with_arranging(&(root), 4);
    insert_with_arranging(&(root), 5);
    insert_with_arranging(&(root), 6);
    insert_with_arranging(&(root), 7);
    insert_with_arranging(&(root), 8);
    insert_with_arranging(&(root), 9);
    insert_with_arranging(&(root), 10);
    insert_with_arranging(&(root), 11);
    insert_with_arranging(&(root), 12);
    insert_with_arranging(&(root), 13);
    insert_with_arranging(&(root), 14);
    insert_with_arranging(&(root), 15);
    insert_with_arranging(&(root), 16);
    insert_with_arranging(&(root), 17);

    printf("\nInorder:   ");
    inorder(root);

    printf("\nHeight:    %d", get_height(root));

    print2D(root);

    return 0;
}