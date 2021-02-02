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
	size_t i, j, min;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		min = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (i - min != 0)
		{
			myswap(array, j, low);
			temp = array[min];
			array[min] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}
/**
 * myswap - swaps two values
 * @arr: array of integers
 * @a: index of value to swap
 * @b: index of value to swap
 * Return: nothing
 */
void myswap(int *arr, size_t a, size_t b)
{
	int temp = arr[a];

	arr[a] = arr[b];
	arr[b] = temp;
}
