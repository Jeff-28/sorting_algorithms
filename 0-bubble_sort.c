#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order using Bubble
 * Sort Algorithm
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: no return for this void function
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int count, finder;
	int temp;

	if (size <= 2)
		return;

	for (count = 0; count < (size - 1); count++)
	{
		for (finder = 0; finder < (size - 1); finder++)
		{
			if (array[finder] > array[finder + 1])
			{
				temp = array[finder];
				array[finder] = array[finder + 1];
				array[finder + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
