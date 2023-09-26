#include "sort.h"

int lomuto_partition(int *array, size_t size, int left, int right);
void swap_ints(int *a, int *b);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * lomuto_partition - should order a subset of an array of integers
 * @size: the size of an array
 * @right: the subset to order the starting index
 * @left: the subset to order the starting index
 * @array: the integers of an array
 * Return: the final partition index to be returned
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}
	return (above);
}

/**
 * swap_ints - two integers in an array to be swapped
 * @j: swap the second integer
 * @i: swap the first integer
 */
void swap_ints(int *i, int *j)
{
	int tmp;

	tmp = *i;
	*i = *j;
	*j = tmp;
}

/**
 * lomuto_sort - through recurssion implement the quicksort algorithm
 * @size: the array size
 * @right: the ending index of the array partition to order
 * @left: the starting index of the array partition to order
 * @array: to sort an array of integers
 *
 * Desc: should use the lomuto partition scheme
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - in ascending order using the quicksort algorithm
 * @array: the integers of the array
 * @size: the array size
 *
 * Desc: uses the lomuto partition scheme. Prints
 * the array after each swap of two elements
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
