#include "binary_trees.h"

/**
 * recursion - Do the recursion
 *
 * @tree: Root of the tree
 * Return: The maximal height
 */

size_t recursion(const binary_tree_t *tree)
{
	size_t l = 0, r = 0;

	if (!tree)
		return (0);

	l = recursion(tree->left) + 1;
	r = recursion(tree->right) + 1;

	if (l > r)
		return (l);
	else
		return (r);
}

/**
 * binary_tree_height - Measures the height of a binary tree
 *
 * @tree: Root of the tree
 * Return: The height
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (recursion(tree) - 1);
}
