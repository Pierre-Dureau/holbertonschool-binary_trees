#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 *
 * @tree: Root of the tree
 * Return: The size
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (!tree)
		return (0);

	size = binary_tree_size(tree->left) + binary_tree_size(tree->right);

	return (size + 1);
}

/**
 * is_complete - Checks each case
 *
 * @tree: Root of the tree
 * @i: Case of the tree like an array
 * @size: Size of the array
 * Return: 1 if yes, 0 otherwise
 */

int is_complete(const binary_tree_t *tree, size_t i, size_t size)
{
	if (tree == NULL)
		return (1);
	if (i >= size)
		return (0);

	return (is_complete(tree->left, 2 * i + 1, size) &&
			is_complete(tree->right, 2 * i + 2, size));
}

/**
 * is_heap - Check if the binary tree is heap
 *
 * @tree: Root of the tree
 * Return: 1 if yes, 0 otherwise
 */

int is_heap(const binary_tree_t *tree)
{
	int l = 1, r = 1;

	if (tree->left)
	{
		if (tree->n < tree->left->n)
			return (0);
		l = is_heap(tree->left);
	}
	if (tree->right)
	{
		if (tree->n < tree->right->n)
			return (0);
		r = is_heap(tree->right);
	}

	return (l && r);
}

/**
 * binary_tree_is_heap - Check if a binary tree is complete & heap
 *
 * @tree: Root of the tree
 * Return: 1 if yes, 0 otherwise
 */

int binary_tree_is_heap(const binary_tree_t *tree)
{
	size_t size;
	int is_c;

	if (!tree)
		return (0);

	size = binary_tree_size(tree);
	is_c = is_complete(tree, 0, size);
	if (!is_c)
		return (0);

	return (is_heap(tree));
}
