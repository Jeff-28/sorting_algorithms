#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list in ascending order using
 * the Insertion sort algorith
 * @list: list to be sorted
 *
 * Return: no return for this void function
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *forward, *curr_hold, *forw_hold;

	if (list == NULL || (*list)->next == NULL)
		return;

	current = *list;
	forward = current->next;

	while (forward)
	{
		if (current->n > forward->n)
		{
			node_swapper(current, forward);
			if (*list == current)
				*list = forward;
			forward = forward->next;
			current = forward->prev;
			print_list(*list);
			forw_hold = current;
			curr_hold = forw_hold->prev;
			while (curr_hold && curr_hold->n > forw_hold->n)
			{
				node_swapper(curr_hold, forw_hold);
				if (curr_hold == *list)
					*list = forw_hold;
				print_list(*list);
				curr_hold = forw_hold->prev;
			}
		}
		current = forward;
		forward = forward->next;
	}
}

/**
 * node_swapper - takes two nodes and compares them for sorting
 * @to_back: value to move back in the list
 * @to_front: value to move forward in the list
 *
 * Return: no return for this void function
 */
void node_swapper(listint_t *to_back, listint_t *to_front)
{
	to_back->next = to_front->next;
	to_front->prev = to_back->prev;
	if (to_front->prev)
		to_front->prev->next = to_front;
	to_back->prev = to_front;
	if (to_back->next)
		to_back->next->prev = to_back;
	to_front->next = to_back;
}
