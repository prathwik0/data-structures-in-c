#include <stdio.h>

// C recursive function to solve tower of hanoi puzzle
void toh(int n, int A, int B, int C)
{
	if (n == 1)
	{
		printf("\n Move disk 1 from rod %d to rod %d", A, B);
		return;
	}
	toh(n-1, A, C, B);
	printf("\n Move disk %d from rod %d to rod %d", n, A, B);
	toh(n-1, C, B, A);
}

int main()
{
	int n = 2; // Number of disks
	toh(n, 1, 3, 2); // A, B and C are names of rods
	return 0;
}
