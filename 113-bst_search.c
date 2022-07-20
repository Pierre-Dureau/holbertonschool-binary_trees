#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree
 *
 * @tree: Root of the tree
 * @value: Value to search
 * Return: The node found
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *node;

	if (!tree)
		return (NULL);
	node = (bst_t *)tree;

	while (node)
	{
		if (node->n == value)
			return (node);
		if (node->n > value)
			node = node->left;
		if (node->n < value)
			node = node->right;
	}
	return (NULL);
}
