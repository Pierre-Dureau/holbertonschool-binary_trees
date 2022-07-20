#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree
 *
 * @tree: Root of the tree
 * Return: The count
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t l = 0, r = 0;

	if (!tree)
		return (0);

	l = binary_tree_nodes(tree->left);
	r = binary_tree_nodes(tree->right);

	if (tree->left || tree->right)
		return (l + r + 1);
	else
		return (l + r);
}
