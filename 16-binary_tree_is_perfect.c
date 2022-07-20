#include "binary_trees.h"

/**
 * recursion - Do the recursion
 *
 * @tree: Root of the tree
 * Return: Int
 */

int recursion(const binary_tree_t *tree)
{
	int l = 0, r = 0;

	if (!tree)
		return (0);

	l = recursion(tree->left);
	r = recursion(tree->right);

	if (!tree->left && !tree->right)
		return (1);
	else if (l == r)
		return (1 + l + r);
	else
		return (0);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 *
 * @tree: Root of the tree
 * Return: 1 if yes, 0 otherwise
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (recursion(tree) != 0)
		return (1);
	else
		return (0);
}
