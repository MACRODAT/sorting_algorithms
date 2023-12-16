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
 * insertion_sort_list - insert and sort
 * @list: list
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *t = NULL, *u = NULL, *p = NULL;

	if (!list || !*list)
		return;
	t = *list;
	if (!t->next)
		return;
	t = t->next;
	while (t)
	{
		u = t;
		p = t;
		t = t->next;
		do {
			if (u->n > p->n)
			{
				swap_nodes(u, p);
				print_list(*list);
				if (!p->prev)
					*list = p;
				u = p;
			}
			u = u->prev;
		} while (u);
	}
}
