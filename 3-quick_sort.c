#include "sort.h"
/**
 * quick_sort - sorts an array of integers in ascending order using
 *				the Quick sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	quick_sorting(array, 0, size - 1, size);
}
/**
 * myswap - swaps two values
 * @array: array with integer values
 * @i: denotes an index
 * @j: denotes an index
 * @size: size of the array
 * Return: nothing
 */
void myswap(int *array, int i, int j, size_t size)
{
	int temp;

	if (array[i] != array[j])
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		print_array(array, size);
	}
}
/**
 * quick_sorting - recursive helper for quick_sort function
 * @array: array with integer values
 * @lo: minimum index
 * @hi: maximum index
 * @size: size of the array
 * Return: nothing
 */
void quick_sorting(int *array, int lo, int hi, size_t size)
{
	int pivot;

	if (lo < hi)
	{
		pivot = partition(array, lo, hi, size);
		quick_sorting(array, lo, pivot - 1, size);
		quick_sorting(array, pivot + 1, hi, size);
	}
}
/**
 * partition - recursive helper for quick_sort function
 * @array: array with integer values
 * @lo: minimum index
 * @hi: maximum index
 * @size: size of the array
 * Return: nothing
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi];
	int j, i = lo;

	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			myswap(array, i, j, size);
			i++;
		}
	}
	myswap(array, i, hi, size);
	return (i);
}
