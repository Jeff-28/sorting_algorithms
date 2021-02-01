#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending
 *					order using the Selection sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	int i, j, min, len, swap;

	if (size < 2)
		return;

	for (len = 0; array[len] != '\0'; len++)
		;
	for (i = 0; i < len; i++)
	{
		min = i;
		for (j = i + 1; j < len; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
		{
			swap = array[min];
			array[min] = array[i];
			array[i] = swap;
			print_array(array, size);
		}
	}
}
