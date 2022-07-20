#include "binary_trees.h"

/**
 * recursion_height - Do the recursion
 *
 * @tree: Root of the tree
 * Return: The maximal height
 */

size_t recursion_height(const binary_tree_t *tree)
{
	size_t l = 0, r = 0;

	if (!tree)
		return (0);

	l = recursion_height(tree->left) + 1;
	r = recursion_height(tree->right) + 1;

	if (l > r)
		return (l);
	else
		return (r);
}

/**
 * _height - Measures the height of a binary tree
 *
 * @tree: Root of the tree
 * Return: The height
 */

size_t _height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (recursion_height(tree) - 1);
}

/**
 * print_each_level - Print each level
 *
 * @tree: The tree
 * @func: The print function
 * @l: The level
 */

void print_each_level(const binary_tree_t *tree, void (*func)(int), size_t l)
{
	if (!tree)
		return;
	if (l == 0)
		func(tree->n);
	else
	{
		print_each_level(tree->left, func, l - 1);
		print_each_level(tree->right, func, l - 1);
	}
}

/**
 * binary_tree_levelorder - goes through a binary tree using
 * level-order traversal
 *
 * @tree: Root of the tree
 * @func: func to print
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t h, i;

	if (!tree || !func)
		return;

	h = _height(tree);
	for (i = 0; i <= h; i++)
		print_each_level(tree, func, i);
}
