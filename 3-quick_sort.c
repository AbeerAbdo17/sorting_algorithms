#include "sort.h"

/**
 * lomuto - Lomuto partition scheme
 * @array: input array
 * @low: low index
 * @high: high index
 * @size: size of array
 * Return: idex
 */
int lomuto(int *array, int low, int high, size_t size)
{
	int xpv = array[high];
	int xtmp, yv, xv = low;

	for (yv = low; yv < high; yv++)
	{
		if (array[yv] < xpv)
		{
			if (xv != yv)
			{
				xtmp = array[xv];
				array[xv] = array[yv];
				array[yv] = xtmp;

				print_array(array, size);
			}
			xv++;
		}
	}

	if (xv != high)
	{
		xtmp = array[xv];
		array[xv] = array[high];
		array[high] = xtmp;

		print_array(array, size);
	}

	return (xv);
}

/**
 * quickRec - Recursive function
 * @array: input array
 * @low: low index
 * @high: high index
 * @size: size of array
 */
void quickRec(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int xpv;

		xpv = lomuto(array, low, high, size);
		quickRec(array, low, xpv - 1, size);
		quickRec(array, xpv + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers using Quick sort
 * @array: input array
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quickRec(array, 0, size - 1, size);
}
