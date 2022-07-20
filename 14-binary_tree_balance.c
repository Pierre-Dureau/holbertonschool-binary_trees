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
 * _height - Measures the height of a binary tree
 *
 * @tree: Root of the tree
 * Return: The height
 */

size_t _height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (recursion(tree));
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 *
 * @tree: Root of the tree
 * Return: The balance
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (_height(tree->left) - _height(tree->right));
}
