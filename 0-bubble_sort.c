#include "sort.h"

/**
 * swap_ints - function that swaps two ints in an array.
 * @c: the int to swap first.
 * @d: the int to swap second
 */
void swap_ints(int *c, int *d)
{
	int tmp;

	tmp = *c;
	*c = *d;
	*d = tmp;
}

/**
 * bubble_sort - in ascending order sort an array of ints
 * @array: sort an array of integers
 * @size: the array size
 *
 * Desc: must print array from each swap
 */
void bubble_sort(int *array, size_t size)
{
	size_t j, length = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{

		bubbly = true;
		for (j = 0; j < length - 1; j++)
		{

			if (array[j] > array[j + 1])
			{

				swap_ints(array + j, array + j + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		length--;
	}
}
