#include "sort.h"

void my_swap(int *arr, size_t a, size_t b);

/**
 * selection_sort - sorts an array of integers in ascending
 *					order using the Selection sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
		{
			my_swap(array, min, i);
			print_array(array, size);
		}
	}
}
/**
 * my_swap - swaps two values
 * @arr: array of integers
 * @a: index of value to swap
 * @b: index of value to swap
 * Return: nothing
 */
void my_swap(int *arr, size_t a, size_t b)
{
	int temp = arr[a];

	arr[a] = arr[b];
	arr[b] = temp;
}
