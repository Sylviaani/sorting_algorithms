#include "sort.h"

/**
 * swap_ints - in the array swap two integers
 * @g: swap the first integer.
 * @j: to swap the second integer
 */
void swap_ints(int *g, int *j)
{
	int tmp;

	tmp = *g;
	*g = *j;
	*j = tmp;
}

/**
 * selection_sort - in ascending order sort array of integers
 * using the selection sort algorithms.
 * @array: an integer of arrays
 * @size: the array size
 * Desc: must print array after each swap
 */
void selection_sort(int *array,  size_t size)
{
	int *min;
	size_t y, z;

	if (array == NULL || size < 2)
		return;

	for (y = 0; y < size - 1; y++)
	{
		min = array + y;
		for (z = y + 1; z < size; z++)
			min = (array[z] < *min) ? (array + z) : min;

		if ((array + y) != min)
		{
			swap_ints(array + y, min);
			print_array(array, size);
		}
	}
}
