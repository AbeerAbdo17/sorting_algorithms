#include "sort.h"

/**
 * selection_sort - sorts an array of integers using the Selection sort
 * @array: input
 * @size: input
 */
void selection_sort(int *array, size_t size)
{
	size_t xv, yv, minidx;
	int xtmp;

	for (xv = 0; xv < size - 1; xv++)
	{
		minidx = xv;

		for (yv = xv + 1; yv < size; yv++)
		{
			if (array[yv] < array[minidx])
			{

				xtmp = array[xv];
				array[xv] = array[yv];
				array[yv] = xtmp;


				print_array(array, size);
			}
		}
	}
}

