#include "sort.h"

node_t* construct_heap(int *array, int i, size_t size)
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

void swap_nodes(node_t *x, node_t *y)
{
	int tmp = x->value;

	x->value = y->value;
	y->value = tmp;
}

void max_heap(node_t *root)
{
	node_t *my_leaf;

	if (!root)
		return;
	if (!root->left && !root->right)
		return;
	if (root->right && (!root->right->right && !root->right->left))
	{
		if (root->right->value > root->value)
			swap_nodes(root, root->right);
		if (root->left && root->left->value > root->value)
			swap_nodes(root, root->left);
		return;
	}
	if (root->left && (!root->left->right && !root->left->left))
	{
		if (root->left->value > root->value)
			swap_nodes(root, root->left);
		return;
	}
	max_heap(root->left);
	max_heap(root->right);
	if (root->right && root->right->value > root->value)
		swap_nodes(root, root->right);
	if (root->left && root->left->value > root->value)
		swap_nodes(root, root->left);
}

void max_heapify(node_t *root)
{
	if (!root)
		return;
	if (!root->left && !root->right)
		return;
	if (root->left && root->left->value > root->value)
	{
		swap_nodes(root->left, root);
	}
	if (root->right && root->right->value > root->value)
	{
		swap_nodes(root, root->right);
	}
	max_heapify(root->left);
	max_heapify(root->right);
}

void heap_sort(int *array, size_t size)
{
	node_t *root, *t, *p;
	int i = 0;

	root = construct_heap(array, 0, size);
	max_heap(root);
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
		print_array(array, size);
		if (!root->left && !root->right)
			break;
		swap_nodes(root, t);
		if (p->left == t)
			p->left = NULL;
		else
			p->right = NULL;
		free(t);
		max_heap(root);
		i++;
	}
}
