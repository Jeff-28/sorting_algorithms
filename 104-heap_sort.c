#include "sort.h"

/**
 * my_swap - swaps two values
 * @arr: array of integers
 * @a: index of value to swap
 * @b: index of value to swap
 *
 * Return: nothing
 */
void my_swap(int *arr, int a, int b)
{
	int temp = arr[a];

	arr[a] = arr[b];
	arr[b] = temp;
}
/**
 * siftdown - adjusts the heap
 * @arr: array of integers
 * @root: the initial position
 * @end: the last position
 * @size: the size of the array
 *
 * Return: nothing
 */
void siftdown(int *arr, int root, int end, size_t size)
{
	int right, temp, left;

	while ((left = (root * 2) + 1) <= end)
	{
		temp = root;
		right = left + 1;
		if (arr[temp] < arr[left])
			temp = left;
		if (right <= end && arr[temp] < arr[right])
			temp = right;
		if (temp == root)
			return;
		my_swap(arr, root, temp);
		print_array(arr, size);
		root = temp;
	}
}
/**
 * heapify - creates a heap out of an array
 * @array: an array of integers
 * @size: the size of the array
 *
 * Return: nothing
 */
void heapify(int *array, size_t size)
{
	int parent = ((size - 1) - 1) / 2;

	while (1)
	{
		siftdown(array, parent, size - 1, size);
		if (parent == 0)
			break;
		parent--;
	}
}
/**
 * heap_sort - sorts an array of integers in ascending order using
 *				the Heap sort algorithm
 * @array: array of integers
 * @size: size of the array
 *
 * Return: nothing
 */
void heap_sort(int *array, size_t size)
{
	int end = size - 1;

	if (size < 2)
		return;
	heapify(array, size);
	while (end > 0)
	{
		my_swap(array, end, 0);
		print_array(array, size);
		end--;
		siftdown(array, 0, end, size);
	}
}
