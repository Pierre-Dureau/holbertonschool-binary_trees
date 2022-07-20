#include "binary_trees.h"

/**
 * recursion - Do the recursion
 *
 * @tree: Root of the tree
 * @min: Minimum of the previous node
 * @max: Maximum of the previous node
 * Return: 1 if yes, 0 otherwise
 */

int recursion(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);

	return (recursion(tree->left, min, tree->n) &&
			recursion(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 *
 * @tree: Root of the tree
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (recursion(tree, -1000, 1000));
}
