#include "sort.h"

/**
 * swap_nodes - must swap two nodes in a listint_t doubly-linked list
 * @k: the head of the doubly-linked list pointer
 * @n1: a pointer to the first node to swap
 * @n2: swapped second node isa must
 */
void swap_nodes(listint_t **k, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*k = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - func that uses the insertion to sort out algorithms
 * sorts a doubly linked list of the said ints
 * @list: pointer of the doubly-linked list of ints.
 *
 * Desc: function that prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swap_nodes(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
