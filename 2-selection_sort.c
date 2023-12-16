
#include "sort.h"

/**
 * swap_nodes - swaps
 * @t1: node
 * @t2: node
*/
void swap_nodes(listint_t *t1, listint_t *t2)
{
	listint_t tmp;

	tmp.prev = t1->prev;
	tmp.next = t1->next;
	if (t1->prev)
		t1->prev->next = t2;
	if (t2->next)
		t2->next->prev = t1;

	if (t1->next == t2)
	{
		t1->prev = t2;
		t1->next = t2->next;
		t2->next = t1;
		t2->prev = tmp.prev;
		return;
	}
	t2->prev->next = t1;
	t1->next->prev = t2;
	t1->prev = t2->prev;
	t1->next = t2->next;
	t2->prev = tmp.prev;
	t2->next = tmp.next;
}

/**
 * selection_sort - insert and sort
 * @array: list
 * @size: size
*/
void selection_sort(int *array, size_t size)
{
	listint_t *t = NULL, *u = NULL, *p = NULL;

	if (!array || !*array)
		return;
	t = *array;
	if (!t->next)
		return;
	t = t->next;
	while (t)
	{
		u = t;
		p = t;
		do {
			if (u->n < p->n)
			{
				p = u;
			}
			u = u->next;
		} while (u);
		if (p != t)
		{
			u = t;
			t = t->next;
			_swap(arr, p, u);
			print_list(*array);
		}
		else
		{
			t = t->next;
		}
	}
}
