#include "sort.h"

/**
 * insertion_sort_list - sorts doubly linked list of integers in ascending order
 * using the Insertion sort algorithms
 *
 * @list: double pointer to the head of doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		next = current->next;

		while (current->prev != NULL && current->n < current->prev->n)
		{
			prev = current->prev;

			if (prev->prev != NULL)
				prev->prev->next = current;

			if (current->next != NULL)
				current->next->prev = prev;

			prev->next = current->next;
			current->prev = prev->prev;
			prev->prev = current;
			current->next = prev;

			if (current->prev == NULL)
				*list = current;

			print_list(*list);
		}

		current = next;
	}
}
