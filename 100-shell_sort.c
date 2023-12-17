#include "sort.h"
#include "0-bubble_sort.c"

/**
 * gesx - dze
 * @size: the size of the array
 *
 * Return: the gap size
 */
size_t gesx(size_t size)
{
	size_t n;

	n = 1;
	while (n < size)
		n = n * 3 + 1;
	return ((n - 1) / 3);
}

/**
 * shell_sort - shell_sort
 * @array: to sort
 * @size: tay
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

	if (!array || !size)
		return;


	for (gap = gesx(size); gap; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j > gap - 1 && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		print_array(array, size);
	}
}
