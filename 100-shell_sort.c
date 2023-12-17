#include "sort.h"
#include "0-bubble_sort.c"

/**
 * shell_sort - insert and sort
 * @array: list
 * @size: size
*/
void shell_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, k;

	if (!array || !*array || !size)
		return;
	k = 1, i = size / 2;
	while ((j = k * 3 + 1) < i)
		k = j;
	i = j = 0;
	while (k > 0)
	{
		for (i = size - 1; i - k < size; i--)
		{
			j = 1;
			if (k > 0)
			{
				while (i >= k * j)
				{
					if (array[i] < array[i - k * j])
						_swap(array, i, i - j * k);
					j++;
				}
			}
			else
			{
				j = i;
				while (1)
				{
					if (array[j] > array[j + 1])
					{
						_swap(array, j, j + 1);
					}
					if (j == 0)
						break;
					j--;
				}
			}
		}
		k = (k - 1) / 3;
		print_array(array, size);
	}
}
