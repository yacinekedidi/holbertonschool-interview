#include "sandpiles.h"


/**
 * checksame - compute 3x3 grids sum
 * @grid: Left 3x3 grid
 * Return: aa
 */
int checksame(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
{
	for (j = 0; j < 3; j++)
	{
		if (grid[0][0] != grid[i][j])
			return(0);

	}
}

return (1);
}


/**
 * print_sandpile - compute 3x3 grids sum
 * @grid: Left 3x3 grid
 * Return: aa
 */
void print_sandpile(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * sandpiles_sum - compute 3x3 grids sum
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 *
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{int i, j, f, x = 0;
for (i = 0; i < 3; i++)
{
	for (j = 0; j < 3; j++)
	{
	grid1[i][j] += grid2[i][j];
	if (grid1[i][j] > 3)
		x = 1;
	}
}
if (x == 0)
	return;
f = 1;
while (f == 1)
{f = 0;
	if (checksame(grid1) == 1)
		return;
	if (grid1[0][0] == grid1[0][2]
	&& grid1[0][0] == grid1[2][0]
	&& grid1[0][0] == grid1[2][2])
	print_sandpile(grid1);
for (i = 0; i < 3; i++)
{
	for (j = 0; j < 3; j++)
	{
		if (grid1[i][j] > 3)
		{
			f = 1;
			grid1[i][j] -= 4;
			if (i + 1 < 3)
				grid1[i + 1][j] += 1;
			if (j + 1 < 3)
				grid1[i][j + 1] += 1;
			if (i - 1 > -1)
				grid1[i - 1][j] += 1;
			if (j - 1 > -1)
				grid1[i][j - 1] += 1;
}}}}}