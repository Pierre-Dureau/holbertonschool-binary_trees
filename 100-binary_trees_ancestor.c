#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 *
 * @tree: Root of tree
 * Return: The depth
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t d = 0;

	if (!tree)
		return (0);

	while (tree->parent)
	{
		tree = tree->parent;
		d++;
	}

	return (d);
}


/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 *
 * @first: First node
 * @second: Second node
 * Return: The ancestor
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	size_t d_fir, d_sec;

	if (!first || !second)
		return (NULL);

	d_fir = binary_tree_depth(first);
	d_sec = binary_tree_depth(second);

	while (d_fir < d_sec)
	{
		second = second->parent;
		d_sec--;
	}
	while (d_fir > d_sec)
	{
		first = first->parent;
		d_fir--;
	}
	while (first != second)
	{
		first = first->parent;
		second = second->parent;
	}
	return ((binary_tree_t *)first);
}
