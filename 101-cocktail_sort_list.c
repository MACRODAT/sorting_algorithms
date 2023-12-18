#include "sort.h"

/**
 * swap_nodes - swap the nodes themselves.
 * @cur: pointer.
 * @cur_old: pointer.
 * @list: doubly linked list
 */
void swap_nodes(listint_t *cur, listint_t *cur_old, listint_t **list)
{
	listint_t *t1 = cur->next;
	listint_t *t2 = cur_old->prev;

	if (t1 != NULL)
		t1->prev = cur_old;
	if (t2 != NULL)
		t2->next = cur;
	cur->prev = t2;
	cur_old->next = t1;
	cur->next = cur_old;
	cur_old->prev = cur;
	if (*list == cur_old)
		*list = cur;
	print_list(*list);
}

/**
 * cocktail_sort_list - cocktail_sort_list
 *
 * @list: doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head = *list, *first = NULL, *last = NULL;

	if (!list || !(*list) || !(*list)->next)
		return;
	do {
		while (head->next)
		{
			if (head->n > head->next->n)
				swap_nodes(head->next, head, list);
			else
				head = head->next;
		}
		last = head;
		while (head->prev != first)
		{
			if (head->n < head->prev->n)
				swap_nodes(head, head->prev, list);
			else
				head = head->prev;
		}
		first = head;
	} while (first != last);
}
