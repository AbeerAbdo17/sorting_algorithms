#include "sort.h"

/**
 * bubble_sort -  sorts an array of integers using the Bubble sort
 * @array: inputs
 * @size: input
 */
void bubble_sort(int *array, size_t size)
{
	int swaptm;
	size_t xv, yv;

	if (array || size)
	{
		for (xv = 0; xv < size; xv++)
		{
			for (yv = 0; yv < size - 1; yv++)
			{
				if (array[yv] > array[yv + 1])
				{
					swaptm = array[yv];
					array[yv] = array[yv + 1];
					array[yv + 1] = swaptm;
					print_array(array, size);
				}
			}
		}
	}
}
