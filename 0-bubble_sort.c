#include "sort.h"

/**
 * _swap - element swapper
 * @i: first
 * @j: second
 * @array: arr
*/
void _swap(int *array, int i, int j)
{
	int tmp = array[i];

	array[i] = array[j];
	array[j] = tmp;
}

/**
 * bubble_sort - sorting algorithm
 * @array: the array to sort
 * @size: size of the array
*/
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = 0;
	int flag = 0;

	if (!array || !size)
		return;
	for (i = 0; i < size; i++)
	{
		flag = 1;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				_swap(array, j, j + 1), print_array(array, size);
				flag = 0;
			}
		}
		if (flag)
			return;
	}
}
