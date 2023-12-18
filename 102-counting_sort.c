#include "sort.h"

/**
*counting_sort - counting sort
*
*@array: array
*@size: size
*/
void counting_sort(int *array, size_t size)
{
	int *cat;
	size_t i = 0, counter = 0, sz = 0, j = 0;

	while (i < size)
		if ((int)counter < array[i++])
			counter = array[i - 1];
	cat = malloc(sizeof(int) * (counter + 1));
	sz = counter + 1;
	while (i < size)
		cat[i++] = 0;
	i = 0;
	while (i < size)
	{
		cat[array[i]] += 1;
		i++;
	}
	i = counter = 0;
	while (i < size)
	{
		j = cat[counter];
		while (j > 0)
		{
			array[i++] = counter;
			j -= 1;
		}
		counter++;
	}
	i = counter = 0;
	while (i < sz)
	{
		counter += cat[i];
		cat[i++] = counter;
	}
	print_array(cat, sz);
	free(cat);
}
