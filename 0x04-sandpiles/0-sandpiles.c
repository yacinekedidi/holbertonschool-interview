#include "sandpiles.h"

/**
 * sandpiles_sum - compute 3x3 grids sum
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 *
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
int i, j, f = 1;

for (i = 0; i < 3; i++)
{
	for (j = 0; j < 3; j++)
	{
	grid1[i][j] += grid2[i][j];
	}
}
while (f == 1)
{
	f = 0;
for (i = 0; i < 3; i++)
{
	for (j = 0; j < 3; j++)
	{
		if (grid1[i][j] > 3)
		{
			f = 1;
			grid1[i][j] -= 4;
			if (i + 1 < 3)
			{
				grid1[i + 1][j] += 1;
			}
			if (j + 1 < 3)
			{
				grid1[i][j + 1] += 1;
			}
			if (i - 1 > -1)
			{
				grid1[i - 1][j] += 1;
			}
			if (j - 1 > -1)
			{
				grid1[i][j - 1] += 1;
			}
		}
	}
}
}
}
