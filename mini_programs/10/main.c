//check if a char is alphabet or not
#include <stdio.h>
#include <stdlib.h>

int main()
{
   char a;
   printf("Enter char:\n");
   scanf("%c",&a);

   if (a < 65) printf("Not alphabet");
   else if (a < 91) printf("Capital letter");
   else if (a < 97) printf("Not alphabet");
   else if (a < 123) printf("Small letter");
   else printf("Not alphabet");

   return 0;
}

