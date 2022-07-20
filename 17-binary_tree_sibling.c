#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node
 *
 * @node: The node
 * Return: The sibling
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !(node->parent) || !(node->parent->left) ||
		!(node->parent->right))
		return (NULL);

	if (node->parent->left->n != node->n)
		return (node->parent->left);
	else
		return (node->parent->right);
}
