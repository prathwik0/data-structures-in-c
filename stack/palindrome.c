#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* stack;
int top = -1;

void push(char ch)
{
	stack[++top] = ch;
}

char pop()
{
	return stack[top--];
}

int main()
{
    char string[100];

    printf("Enter string: ");
    scanf(" %s", string);

    int len = strlen(string);
    int mid = len / 2;
	stack = (char*)malloc(mid * sizeof(char));

	for (int i = 0; i < mid; i++) {
		push(string[i]);
	}

    for (int i = (len + 1)/2; i < len; i++) {
		if (string[i] != pop()) 
        {
            printf("Not palindrome\n");
            return 0;
        }
	}

    printf("It is palindrome\n");

	return 0;
}
