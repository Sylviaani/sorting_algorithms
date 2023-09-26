#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/* Comparison direction macros for bitonic sort */
#define DOWN 1.
#define UP 0.

/**
 * enum bool - the Enumeration of Boolean values
 * @false: equals 0
 * @true: equals 1
 */
typedef enum bool
{

	false = 0,
	true
} bool;

/**
 * struct listint_s - doubly linked list node
 *
 * @n: integer stored in the node
 * @prev: pointer to the previous element of the list
 * @next: pointer to the next element of the list
 */
typedef struct listint_s
{

	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Sorting algorithms */
void insertion_sort_list(listint_t **list);
void bubble_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void radix_sort(int *array, size_t size);

/* Printing helper functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

#endif /* SORT_H */
