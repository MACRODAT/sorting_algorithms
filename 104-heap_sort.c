#include "sort.h"
#define parent(x) (((x) - 1) / 2)
#define leftchild(x) (((x) * 2) + 1)

/**
 * wsp - wsps 2 int values
 * @array: the integer array to sort
 * @size: the size of the array
 * @a: address of first value
 * @b: address of second value
 *
 * Return: void
 */
void wsp(int *array, size_t size, int *a, int *b)
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
*siftdown - sss
*
*@array: adsad
*@start: stsda
*@end: asd
*@size: asd
*
*/
void siftdown(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start, _wsp, child;

	while (leftchild(root) <= end)
	{
		child = leftchild(root);
		_wsp = root;
		if (array[_wsp] < array[child])
			_wsp = child;
		if (child + 1 <= end &&
			array[_wsp] < array[child + 1])
			_wsp = child + 1;
		if (_wsp == root)
			return;
		wsp(array, size, &array[root], &array[_wsp]);
		root = _wsp;
	}
}

/**
*heapify - makes heap in-place
*
*@array: array to be sorted
*@size: size of array
*
*/
void heapify(int *array, size_t size)
{
	ssize_t start;

	start = parent(size - 1);
	while (start >= 0)
	{
		siftdown(array, start, size - 1, size);
		start--;
	}
}
/**
*heap_sort - heap sort algorithm
*
*@array: array to sort
*@size: size of array
*
*/
void heap_sort(int *array, size_t size)
{
	size_t end;

	if (!array || size < 2)
		return;
	heapify(array, size);
	end = size - 1;
	while (end > 0)
	{
		wsp(array, size, &array[end], &array[0]);
		end--;
		siftdown(array, 0, end, size);
	}
}