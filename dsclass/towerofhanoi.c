#include <stdio.h>

// C recursive function to solve tower of hanoi puzzle
void toh(int n, char rod1, char rod2, char rod3)
{
	if (n > 0)
	{
		toh(n-1, rod1, rod3, rod2);
		printf("\n Move disk from rod %c to rod %c",rod1, rod3);
		toh(n-1, rod2, rod1, rod3);
	}
}

int main()
{
	int n = 3; // Number of disks
	toh(n, 'A', 'B', 'C'); // A, B and C are names of rods
	return 0;
}
