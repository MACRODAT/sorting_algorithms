#include "sort.h"
#include "0-bubble_sort.c"

/**
 * partition_func - function to partition the splits
 * @l: low
 * @h: high
 * @a: array
 * @size: ind
 * Return: soem
*/
int partition_func(int *a, int l, int h, int size)
{
	int pivot = a[h], i = l, j;

	for (j = l; j < h; j++)
	{
		if (a[j] < pivot)
		{
			if (l != j && i != j)
			{
				_swap(a, i, j);
				print_array(a, size);
			}
			i++;
		}
	}
	if (i != h)
	{
		_swap(a, i, h);
		print_array(a, size);
	}
	return (i);
}

/**
 * quick_sort_helper - sorter
 * @array: arr
 * @l: ind
 * @h: ind
 * @size: ind
*/
void quick_sort_helper(int *array, int l, int h, int size)
{
	int i = 0;

	if (l < h)
	{
		i = partition_func(array, l, h, size);
		quick_sort_helper(array, l, i - 1, size);
		quick_sort_helper(array, i + 1, h, size);
	}
}

/**
 * quick_sort - insert and sort
 * @array: list
 * @size: size
*/
void quick_sort(int *array, size_t size)
{
	quick_sort_helper(array, 0, size - 1, size);
}
