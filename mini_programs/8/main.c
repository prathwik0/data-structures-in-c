//check char is vovel or consonent
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;
    printf("Enter a char :\n");
    scanf("%c", &c);
    switch (c) {

    case 'a' : printf("Vovel\n"); break;
    case 'e' : printf("Vovel\n"); break;
    case 'i' : printf("Vovel\n"); break;
    case 'o' : printf("Vovel\n"); break;
    case 'u' : printf("Vovel\n"); break;
    case 'A' : printf("Vovel\n"); break;
    case 'E' : printf("Vovel\n"); break;
    case 'I' : printf("Vovel\n"); break;
    case 'O' : printf("Vovel\n"); break;
    case 'U' : printf("Vovel\n"); break;

    default : printf("Consonant\n");

    };
    return 0;
}
