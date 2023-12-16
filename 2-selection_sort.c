#include "sort.h"
#include "0-bubble_sort.c"

/**
 * selection_sort - insert and sort
 * @array: list
 * @size: size
*/
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, min_ind;

	if (!array || !*array || !size)
		return;
	while (i < size)
	{
		min_ind = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_ind])
				min_ind = j;
		}
		if (i != min_ind)
		{
			_swap(array, i, min_ind);
			print_array(array, size);
		}
		i++;
	}
}
