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
			xtmp = array[xv];
			array[xv] = array[yv];
			array[yv] = xtmp;

			print_array(array, size);
		}
	}

	xtmp = array[xv + 1];
	array[xv + 1] = array[high];
	array[high] = xtmp;

	print_array(array, size);

	return (xv + 1);
}

/**
 *  quickRec - Recursive function
 * @array: input
 * @low: input
 * @high: input
 * @size: input
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
 * quick_sort -  sorts an array of integers using the Quick sort
 * @array: input
 * @size: input
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	print_array(array, size);

	quickRec(array, 0, size - 1, size);

	print_array(array, size);
}

