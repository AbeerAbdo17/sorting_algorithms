#include "sort.h"

/**
 * shell_sort - sorts an array of integers using the Shell sort algorithm
 * with the Knuth sequence
 * @array: input
 * @size: input
 */
void shell_sort(int *array, size_t size)
{
	size_t xgap = 1, xv, yv;
	int xtmp;

	while (xgap < size / 3)
		xgap = xgap * 3 + 1;

	while (xgap > 0)
	{
		for (xv = xgap; xv < size; xv++)
		{
			xtmp = array[xv];
			yv = xv;

			while (yv >= xgap && array[yv - xgap] > xtmp)
			{
				array[yv] = array[yv - xgap];
				yv -= xgap;
			}

			array[yv] = xtmp;
		}

		print_array(array, size);
		xgap /= 3;
	}
}
