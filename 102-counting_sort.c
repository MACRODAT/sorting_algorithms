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
	size_t i = 0, counter = 0;

	while (i < size)
		if ((int)counter < array[i++])
			counter = array[i - 1];
	cat = malloc(sizeof(int) * (counter + 1));
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
		while (cat[counter] > 0)
		{
			array[i++] = counter;
			cat[counter] -= 1;
		}
		counter++;
	}
	free(cat);
}
