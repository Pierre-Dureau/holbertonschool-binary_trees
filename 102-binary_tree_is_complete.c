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
 * recursion - Checks each case
 *
 * @tree: Root of the tree
 * @i: Case of the tree like an array
 * @size: Size of the array
 * Return: if a case is not in the range of the size return 0
 */

int recursion(const binary_tree_t *tree, size_t i, size_t size)
{
	if (tree == NULL)
		return (1);
	if (i >= size)
		return (0);

	return (recursion(tree->left, 2 * i + 1, size) &&
			recursion(tree->right, 2 * i + 2, size));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 *
 * @tree: Root of the tree
 * Return: 1 if yes, 0 otherwise
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);

	size = binary_tree_size(tree);
	return (recursion(tree, 0, size));
}
