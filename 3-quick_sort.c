#include "sort.h"

/**
 * lomuto - partition scheme
 * @array: input
 * @low: input
 * @high: input
 * @size: input
 * Return: index
 */
int lomuto(int *array, int low, int high, size_t size)
{
	int xpv = array[high];
	int xtmp, yv, xv = low - 1;

	for (yv = low; yv <= high - 1; yv++)
	{
		if (array[yv] < xpv)
		{
			xv++;
			if (xv != yv)
			{
				xtmp = array[xv];
				array[xv] = array[yv];
				array[yv] = xtmp;

				print_array(array, size);
			}
		}
	}

	xv++;
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
 * @array: input
 * @low: input
 * @high: input
 * @size: input
 */
void quickRec(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int xpv = lomuto(array, low, high, size);

		quickRec(array, low, xpv - 1, size);
		quickRec(array, xpv + 1, high, size);
	}
}

/**
 * quick_sort -  sorts an array of integers using the Quick sort
 * @array: input
 * @size: input
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quickRec(array, 0, size - 1, size);
}
