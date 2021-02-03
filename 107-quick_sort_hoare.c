#include "sort.h"

/**
 * myswap - swaps two values
 * @array: array with integer values
 * @i: denotes an index
 * @j: denotes an index
 * @size: size of the array
 *
 * Return: nothing
 */
void myswap(int *array, int i, int j, size_t size)
{
	int temp = array[i];

	if (i != j)
	{
		array[i] = array[j];
		array[j] = temp;
		print_array(array, size);
	}
}
/**
 * partition - helper function for quicksort
 * @arr: array of integers
 * @lo: minimum index
 * @hi: maximum index
 * @size: size of the array
 *
 * Return: nothing
 */
int partition(int *arr, int lo, int hi, size_t size)
{
	int pivot = arr[hi];

	while (lo <= hi)
	{
		while (arr[lo] < pivot)
		{
			lo++;
		}
		while (arr[hi] > pivot)
		{
			hi--;
		}
		if (lo <= hi)
		{
			myswap(arr, lo, hi, size);
			lo++;
			hi--;
		}
	}
	return (hi);
}
/**
 * quick_sorting - recursive function
 * @arr: array of integers
 * @lo: minimum index
 * @hi: maximum index
 * @size: size of the array
 *
 * Return: nothing
 */
void quick_sorting(int *arr, int lo, int hi, size_t size)
{
	int pivot;

	if (lo < hi)
	{
		pivot = partition(arr, lo, hi, size);
		quick_sorting(arr, lo, pivot, size);
		quick_sorting(arr, pivot + 1, hi, size);
	}
}
/**
 * quick_sort_hoare - sorts an array of integers in ascending order
 *						using the Quick sort algorithm
 * @array: array of integers to be sorted
 * @size: the size of the array
 *
 * Return: nothing
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (size < 2)
		return;
	quick_sorting(array, 0, size - 1, size);
}
