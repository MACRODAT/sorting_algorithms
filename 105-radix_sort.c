#include "sort.h"


/**
 * get_digit - digit
 * @number: number
 * @digit: pos
 *
 * Return: val
**/
int get_digit(long number, int digit)
{
	long i = 0L, pow = 1L, ret;

	for (i = 0; i < digit; i++)
		pow *= 10L;
	ret = ((number / pow) % 10);
	return (ret);
}

/**
 * radix_sort - sorts by radix
 * @array: asd
 * @size: das
 *
 * Return: void.
 */
void radix_sort(int *array, size_t size)
{
	int i = 0, j = 0, x = 0, p = 0, max_, digits = 1;
	int *sorted;

	if (!array)
		return;
	max_ = array[0];
	sorted = malloc(sizeof(int) * size);
	while (i < size)
	{
		if (array[i] > max_)
			max_ = array[i];
		sorted[i++] = array[i];
	}
	i = max_;
	while ((i = (i / 10)) >= 1)
		digits++;
	i = 0;
	while (j < digits)
	{
		p = 0;
		for (x = 0; x < 10; x++)
		{
			i = 0;
			while (i < size)
			{
				if (get_digit(array[i], j) == x)
				{
					sorted[p++] = array[i];
				}
				i++;
			}
		}
		i = 0;
		while (i < size)
			array[i++] = sorted[i];
		j++;
		print_array(sorted, size);
	}

	free(sorted);
}
