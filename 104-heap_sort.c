#include "sort.h"

node_t *construct_heap(int *array, int i, size_t size)
{
	node_t *n;

	if (i < size)
	{
		n = (node_t *)malloc(sizeof(node_t *));
		n->value = array[i];
		n->left = construct_heap(array, 2 * i + 1, size);
		n->right = construct_heap(array, 2 * i + 2, size);
		return (n);
	}
	return (NULL);
}

void swap_nodes(node_t *x, node_t *y, int *array, size_t size)
{
	int tmp = x->value;

	x->value = y->value;
	y->value = tmp;
	print_array(array, size);
}

void max_heap(node_t *root, int *array, size_t size)
{
	node_t *my_leaf;

	if (!root)
		return;
	if (!root->left && !root->right)
		return;
	if (root->right && (!root->right->right && !root->right->left))
	{
		if (root->right->value > root->value)
			swap_nodes(root, root->right, array, size);
		if (root->left && root->left->value > root->value)
			swap_nodes(root, root->left, array, size);
		return;
	}
	if (root->left && (!root->left->right && !root->left->left))
	{
		if (root->left->value > root->value)
			swap_nodes(root, root->left, array, size);
		return;
	}
	max_heap(root->left, array, size);
	max_heap(root->right, array, size);
	if (root->right && root->right->value > root->value)
		swap_nodes(root, root->right, array, size);
	if (root->left && root->left->value > root->value)
		swap_nodes(root, root->left, array, size);
}

void heap_sort(int *array, size_t size)
{
	node_t *root, *t, *p;
	int i = 0;

	root = construct_heap(array, 0, size);
	max_heap(root, array, size);
	while (root)
	{
		t = root;
		array[i] = root->value;
		while (t)
		{
			if (!t->left && !t->right)
				break;
			if (!t->left)
			{
				p = t;
				t = t->right;
			}
			else if (!t->right)
			{
				p = t;
				t = t->left;
			}
			else
			{
				p = t;
				if (t->left->value > t->right->value)
					t = t->left;
				else
					t = t->right;
			}
		}
		if (!root->left && !root->right)
			break;
		swap_nodes(root, t, array, size);
		if (p->left == t)
			p->left = NULL;
		else
			p->right = NULL;
		free(t);
		max_heap(root, array, size);
		i++;
	}
}
