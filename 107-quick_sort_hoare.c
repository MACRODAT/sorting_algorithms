#include "sort.h"

/**
 * swap - swaps 2 int values
 * @array: thedast
 * @size: asdasd
 * @a: asdae
 * @b: addasdlue
 *
 * Return: void
 */
void swap(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
	}
	print_array((const int *)array, size);
}

/**
 * hoare_partition - psdf
 * @array: dsf
 * @size: asdasd
 * @lo: sdfa
 * @hi: dasge
 *
 * Return: void
 */
size_t hoare_partition(int *array, size_t size, size_t lo, size_t hi)
{
	size_t i = lo - 1, j = hi + 1;
	int pivot = array[hi];

	while (i < size)
	{
		while (array[++i] < pivot)
			;
		while (array[--j] > pivot)
			;
		if (i < j)
			swap(array, size, &array[i], &array[j]);
		else if (i >= j)
			break;
	}
	return (i);
}

/**
 * quicksort - qd scheme
 * @array: dsort
 * @size: asdasd
 * @lo: tdrt range
 * @hi: d sort range
 *
 */
void quicksort(int *array, size_t size, size_t lo, size_t hi)
{
	if (lo < hi)
	{
		size_t p = hoare_partition(array, size, lo, hi);

		quicksort(array, size, lo, p - 1);
		quicksort(array, size, p, hi);
	}
}

/**
 * quick_sort_hoare - casd
 * @array: tasdrt
 * @size: tdas
 *
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quicksort(array, size, 0, size - 1);
}
