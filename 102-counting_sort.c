#include "sort.h"

/**
 * counting_sort - sorts an array of integers using the Counting sort
 * @array: input
 * @size: input
 */
void counting_sort(int *array, size_t size)
{
	int *xcount, *xsorted, xmax, xv;

	if (array == NULL || size < 2)
		return;
	xsorted = malloc(sizeof(int) * size);
	if (xsorted == NULL)
		return;
	xmax = array[0];
	for (xv = 1; xv < (int)size; xv++)
	{
		if (array[xv] > xmax)
			xmax = array[xv];
	}
	xcount = malloc(sizeof(int) * (xmax + 1));
	if (xcount == NULL)
	{
		free(xsorted);
		return;
	}
	for (xv = 0; xv < (int)size; xv++)
		xcount[xv] = 0;
	for (xv = 0; xv < (int)size; xv++)
		xcount[array[xv]] += 1;
	for (xv = 1; xv <= xmax; xv++)
		xcount[xv] += xcount[xv - 1];
	print_array(xcount, xmax + 1);
	for (xv = (int)size - 1; xv >= 0; xv--)
	{
		xsorted[xcount[array[xv]] - 1] = array[xv];
		xcount[array[xv]] -= 1;
	}
	for (xv = 0; xv < (int)size; xv++)
		array[xv] = xsorted[xv];
	free(xsorted);
	free(xcount);
}
