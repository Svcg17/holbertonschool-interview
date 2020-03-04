#include "sandpiles.h"
/**
 * print_grid - prints a 3x3 grid
 * @grid: 3x3 array of integers
 */
static void print_grid(int grid[3][3])
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
 * handle_topple - Handles when a grid is unstable
 * @grid: 3x3 array of integers
 * @i: index, rows
 * @j: index, columns
 * Return: 1 if grid is still unstable, 0 if stable
 */
int handle_topple(int grid[3][3], int i, int j)
{
	int still_unstable = 0;

	grid[i][j] -= 4;
	if (i + 1 >= 0 && i + 1 <= 2)
	{
		grid[i + 1][j]++;
		if (grid[i + 1][j] > 3)
			still_unstable++;
	}
	if (j + 1 >= 0 && j + 1 <= 2)
	{
		grid[i][j + 1]++;
		if (grid[i][j + 1] > 3)
			still_unstable++;
	}
	if (i - 1 >= 0 && j - 1 <= 2)
	{
		grid[i - 1][j]++;
		if (grid[i - 1][j] > 3)
			still_unstable++;
	}
	if (j - 1 >= 0 && j - 1 <= 2)
	{
		grid[i][j - 1]++;
		if (grid[i][j - 1] > 3)
			still_unstable++;
	}
	return (still_unstable);
}
/**
 * loop_grid - Loops the grid as long as the grid is unstable
 * @grid: 3x3 array of integers, grid to check
 */
void loop_grid(int grid[3][3])
{
	int i, j, unstable = 1, t = 0;
	int cpy_grid[3][3];

	while (unstable)
	{

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				cpy_grid[i][j] = grid[i][j];
			}
		}
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (cpy_grid[i][j] > 3)
				{
					t = handle_topple(grid, i, j);
				}
			}
		}
		if (!t || (!t && i == 0))
			unstable = 0;
		else
			print_grid(grid);
	}
}

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * By the end of the function, grid1 must be stable.
 * @grid1: stable double arrray
 * @grid2: stable double array
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, temp, over3 = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			temp = grid1[i][j];
			grid1[i][j] = temp + grid2[i][j];
			if (grid1[i][j] > 3)
			{
				over3 = 1;
			}
		}
	}
	if (over3)
	{
		print_grid(grid1);
		loop_grid(grid1);
	}
	else
		loop_grid(grid1);
}
