//largest of three numbers
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[3], temp = 0;
    printf("Enter a, b, c :\n");
    scanf("%d%d%d", &a[0], &a[1], &a[2]);

    for (int i = 0; i < 3; i++){
    if (a[i]>temp) {
        temp = a[i];
        //printf("%d %d", i, a[i]);
    }}

    printf("The largest of the three numbers is : %d", temp);

    return 0;
}
