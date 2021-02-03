#include "sort.h"

/**
 * my_swap - swaps two nodes
 * @list: doubly linked list
 * @node: pointer to node
 *
 * Return: nothing
 */
void my_swap(listint_t **list, listint_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
	print_list(*list);
}
/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 *						order using the Cocktail shaker sort algorithm
 * @list: a doubly linked list
 *
 * Return: nothing
 */
void cocktail_sort_list(listint_t **list)
{
	int flag = 1;
	listint_t *temp;

	if (!list || !*list)
		return;
	temp = *list;
	while (flag)
	{
		flag = 0;
		while (temp->next)
		{
			if (temp->n > temp->next->n)
			{
				my_swap(list, temp);
				flag = 1;
			}
			else
				temp = temp->next;
		}
		if (!flag)
			break;
		flag = 0;
		while (temp->prev)
		{
			if (temp->n < temp->prev->n)
			{
				my_swap(list, temp->prev);
				flag = 1;
			}
			else
				temp = temp->prev;
		}
	}
}
