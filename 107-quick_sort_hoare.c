#include "sort.h"

/**
 * quick_sort_hoare - sorts an array of integers in ascending order
 *						using the Quick sort algorithm
 * @array: array of integers to be sorted
 * @size: the size of the array
 * Return: nothing
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (size < 2)
		return;
	quick_sorting(array, 0, size - 1, size);
}
/**
 * quick_sorting - recursive function
 * @arr: array of integers
 * @lo: minimum index
 * @hi: maximum index
 * @size: size of the array
 * Return: nothing
 */
void quick_sorting(int *arr, int lo, int hi, size_t size)
{
	int pivot;

	if (lo < hi)
	{
		pivot = partition(arr, lo, hi, size);
		quick_sorting(arr, lo, pivot - 1, size);
		quick_sorting(arr, pivot, hi, size);
	}
}
/**
 * partition - helper function for quicksort
 * @arr: array of integers
 * @lo: minimum index
 * @hi: maximum index
 * @size: size of the array
 * Return: nothing
 */
int partition(int *arr, int lo, int hi, size_t size)
{
	int pivot = arr[hi], i = lo, j = hi;

	while (arr)
	{
		while (arr[i] < pivot)
		{
			i++;
		}
		while (arr[j] > pivot)
		{
			j--;
		}
		if (i >= j)
			return (i);
		myswap(arr, i, j, size);
	}
	return (j);
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
