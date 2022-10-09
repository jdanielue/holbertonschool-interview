#include "sandpiles.h"

/**
 * _print_grid - Prints a sand pile grid
 * @grid: Grid to print
 *
 * Return: No Return
 */
void _print_grid(int grid[3][3])
{
	int i, j, frontera = 3;

	for (i = 0; i < frontera; i++)
	{
		for (j = 0; j < frontera; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * grid_sum - Computes the sum of two sandpiles
 * @grid1: Pile 1
 * @grid2: Pile 2
 *
 * Return: No Return
 */
void grid_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, frontera = 3;

	for (i = 0; i < frontera; i++)
		for (j = 0; j < frontera; j++)
			grid1[i][j] += grid2[i][j];
}

/**
 * funct_one - Checks if sand pile is stable
 * @grid: validation
 *
 * Return: No Return
 */
int funct_one(int grid[3][3])
{
	int x, y, frontera = 3;

	for (x = 0; x < frontera; x++)
		for (y = 0; y < frontera; y++)
			if (grid[x][y] > frontera)
				return (0);

	return (1);
}

/**
 * sec_func - Distributes sand grains
 * @grid: Grid to process
 *
 * Return: No Return
 */
void sec_func(int grid[3][3])
{
	int i, j, frontera = 3, wall = 2;

	int grid_tmp[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	for (i = 0; i < frontera; i++)
	{
		for (j = 0; j < frontera; j++)
		{
			if (grid[i][j] > frontera)
			{
				(i - 1) >= 0 ? grid_tmp[i - 1][j]++ : 0;

				(i + 1) <= wall ? grid_tmp[i + 1][j]++ : 0;

				(j - 1) >= 0 ? grid_tmp[i][j - 1]++ : 0;

				(j + 1) <= wall ? grid_tmp[i][j + 1]++ : 0;

				grid[i][j] -= 4;
			}
		}
	}

	grid_sum(grid, grid_tmp);
}

/**
 * sandpiles_sum - new info for the func
 * @grid1: one col
 * @grid2: sec col
 *
 * Return: No Return
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	grid_sum(grid1, grid2);
	while (!funct_one(grid1))
	{
		printf("=\n");
		_print_grid(grid1);
		sec_func(grid1);
	}
}
