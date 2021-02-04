#include "sort.h"

/**
 * merge - merges the sorted elements that were split
 * @source: source of values
 * @dest: destination of values
 * @start: the beginning index
 * @mid: the middle index
 * @end: the ending index
 *
 * Return: nothing
 */
void merge(int start, int mid, int end, int *dest, int *source)
{
	int i = start, j = mid, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(source + start, mid - start);
	printf("[right]: ");
	print_array(source + mid, end - mid);
	for (k = start; k < end; k++)
	{
		if (i < mid && (j >= end || source[i] <= source[j]))
		{
			dest[k] = source[i];
			i++;
		}
		else
		{
			dest[k] = source[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_array(dest + start, end - start);
}
/**
 * split - splits an array using top-down implementation
 * @arr: array of integers
 * @copy: copy of the array
 * @start: the beginning index
 * @end: the ending index
 *
 * Return: nothing
 */
void split(int start, int end, int *arr, int *copy)
{
	int mid, i;

	if ((end - start) <= 1)
		return;
	mid = (end + start) / 2;
	split(start, mid, arr, copy);
	split(mid, end, arr, copy);
	merge(start, mid, end, arr, copy);
	for (i = start; i < end; i++)
		copy[i] = arr[i];
}
/**
 * merge_sort - sorts an array of integers in ascending order
 *				using the Merge sort algorithm
 * @array: an array of integers
 * @size: the size of the array
 *
 * Return: nothing
 */
void merge_sort(int *array, size_t size)
{
	int *copy;
	size_t i;

	if (size < 2)
		return;
	copy = malloc(sizeof(int) * size);
	if (!copy)
		return;
	for (i = 0; i < size; i++)
	{
		copy[i] = array[i];
	}
	split(0, size, array, copy);
	free(copy);
}
