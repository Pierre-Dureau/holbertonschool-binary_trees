#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full
 *
 * @tree: Root of the tree
 * Return: 1 if yes, 0 otherwise
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	int l = 0, r = 0;

	if (!tree)
		return (0);

	l = binary_tree_is_full(tree->left);
	r = binary_tree_is_full(tree->right);

	if (!tree->left && !tree->right)
		return (1);
	else if (l != r)
		return (0);
	else
		return (1);
}
