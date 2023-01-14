#include <stdio.h>
#include <stdlib.h>

int search(int *a, int start, int stop, int key);

int main()
{
    int n;
    printf("Enter n:");
    scanf("%d", &n);

    int *a = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }

    int key;
    printf("Enter number to search: ");
    scanf("%d", &key);

    int pos = search(a, 0, n, key);

    if (pos == -1)
    {
        printf("element not present\n");
    }
    else
    {
        printf("Element found at position %d\n", pos);
    }
}

int search(int *a, int start, int stop, int key)
{
    if (start > stop)
    {
        return -1;
    }

    int mid = (start + stop) / 2;

    if (a[mid] == key)
    {
        return mid;
    }
    else if (a[mid] > key)
    {
        return search(a, start, mid - 1, key);
    }
    else
    {
        return search(a, mid + 1, stop, key);
    }
}