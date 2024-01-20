#include "sort.h"

/**
 * lomuto - partition scheme
 * @array: input
 * @xfirst: First element
 * @xlast: Last element
 * @size: Size
 * Return: position of last element sorted
 */
int lomuto(int *array, ssize_t xfirst, ssize_t xlast, size_t size)
{
	int xpivot = array[xlast];
	ssize_t xcurrent = xfirst, xfinder;

	for (xfinder = xfirst; xfinder < xlast; xfinder++)
	{
		if (array[xfinder] < xpivot)
		{
			if (array[xcurrent] != array[xfinder])
			{

				int xtmp = array[xcurrent];

				array[xcurrent] = array[xfinder];
				array[xfinder] = xtmp;

				print_array(array, size);
			}
			xcurrent++;
		}
	}

	if (array[xcurrent] != array[xlast])
	{
		int xtmp = array[xcurrent];

		array[xcurrent] = array[xlast];
		array[xlast] = xtmp;

		print_array(array, size);
	}

	return (xcurrent);
}

/**
 * quickRec - Quicksort
 * @array: input
 * @xfirst: First element
 * @xlast: Last element
 * @size: size
 */
void quickRec(int *array, ssize_t xfirst, ssize_t xlast, int size)
{
	ssize_t xpv = 0;

	if (xfirst < xlast)
	{
		xpv = lomuto(array, xfirst, xlast, size);

		quickRec(array, xfirst, xpv - 1, size);
		quickRec(array, xpv + 1, xlast, size);
	}
}

/**
 * quick_sort -  sorts an array of integers using the Quick sort
 * @array: Array
 * @size: Array size
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quickRec(array, 0, size - 1, size);
}
