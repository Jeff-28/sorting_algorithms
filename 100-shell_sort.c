#include "sort.h"

/**
 * shell_sort - sorts an array of integer in acending order using the
 * Shell sort algorith
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: no return for this vid function
 */
void shell_sort(int *array, size_t size)
{
	int temp;
	size_t i, j;
	unsigned int gap = 1;

	while (gap < size)
		gap = gap * 3 + 1;

	gap = gap / 3;
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;
			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j = j - gap;
			}
			array[j] = temp;
		}
		gap = gap / 3;
		print_array(array, size);
	}
}
