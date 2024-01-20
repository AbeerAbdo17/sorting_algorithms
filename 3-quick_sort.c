#include "sort.h"

/**
 * lomuto - Lomuto partition scheme
 * @array: input array
 * @low: low index of the partition
 * @high: high index of the partition
 * @size: size of the array
 * Return: index of the pivot after partitioning
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
 * quickRec - Recursive function for Quick sort
 * @array: input array
 * @low: low index of the partition
 * @high: high index of the partition
 * @size: size of the array
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
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * @array: input array
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quickRec(array, 0, size - 1, size);
}
