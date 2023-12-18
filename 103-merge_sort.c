#include "sort.h"

/**
 * mg_cmp - comp
 * @array: the
 * @start: the start
 * @stop: the stop
 * @new: output
 *
 * Return: void.
 */
void mg_cmp(int *array, size_t start, size_t stop, int *new)
{
	size_t i = start, j, k, mid;

	j = mid = (start + stop) / 2;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start, mid - start);
	printf("[right]: ");
	print_array(array + mid, stop - mid);
	for (k = start; k < stop; k++)
		if (i < mid && (j >= stop || array[i] <= array[j]))
		{

			new[k] = array[i++];
		}
		else
		{
			new[k] = array[j++];
		}
	printf("[Done]: ");
	print_array(new + start, stop - start);
}

/**
 * mg_td - soe
 * @array: the
 * @start: t
 * @stop: e
 * @new: t
 *
 * Return: void.
 */
void mg_td(int *array, size_t start, size_t stop, int *new)
{
	size_t mid;

	mid = (start + stop) / 2;
	if (stop - start < 2)
	{
		return;
	}
	mg_td(new, start, mid, array);
	mg_td(new, mid, stop, array);
	mg_cmp(new, start, stop, array);
}


/**
 * merge_sort - sore
 * @array: te
 * @size: te
 *
 * Return: void.
 */
void merge_sort(int *array, size_t size)
{
	int *new;
	size_t i;


	if (!array || size < 2)
		return;

	new = malloc(sizeof(int) * size);
	if (!new)
		return;
	for (i = 0; i < size; i++)
		new[i] = array[i];
	mg_td(array, 0, size, new);
	free(new);
}
