#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tree.h"
#include "stack.h"

int main()
{
    char *expression = "345*-78/+4-";
    char *ch = expression;

    stack s1, s2;

    s1.front = NULL;
    s2.front = NULL;

    while (*ch != '\0')
    {
        if (isnumber(*ch))
        {
            node root = getNode(*ch);
            push(&s1, root);
        }
        else
        {
            node root = getNode(*ch);

            node right = pop(&s1);
            node left = pop(&s1);

            root->left = left;
            root->right = right;

            push(&s1, root);
        }

        ch++;
    }

    node root = pop(&s1);

    inorder(root);
    printf("\n");
    postorder(root);

    printf("\nEvaluated expression:\n");
    printf("%d\n", evaluate(root));

    return 0;
}