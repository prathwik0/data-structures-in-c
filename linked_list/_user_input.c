#include <stdio.h>
#include "doubly.h"

int main()
{
    list a;
    a.front = NULL;

    while (1)
    {
        int choice;
        printf("1 - insert, 2 - display, 3 - delete : ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int data;
            scanf("%d", &data);

            insertRear(&a, data);
        }
        else if (choice == 2)
        {
            display(&a);
        }
        else if (choice == 3)
        {
            int key;
            scanf("%d", &key);
            deleteElement(&a, key);
        }
        else
        {
            return 0;
        }
    }
}