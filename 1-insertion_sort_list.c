#include "sort.h"

/**
 * node_swap - Swaps two nodes in a listint_t doubly-linked list.
 * @head: A pointer to the head of the doubly-linked list.
 * @first: A pointer to the first node to swap.
 * @second: The second node to swap.
 */
void node_swap(listint_t **head, listint_t **first, listint_t *second)
{
	(*first)->next = second->next;
	if (second->next != NULL)
		second->next->prev = *first;
	second->prev = (*first)->prev;
	second->next = *first;
	if ((*first)->prev != NULL)
		(*first)->prev->next = second;
	else
		*head = second;
	(*first)->prev = second;
	*first = second->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
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
			node_swap(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
