#include "binary_trees.h"

/**
 * sorted_array_to_avl - builds an AVL tree from an sorted array
 *
 * @array: Sorted array
 * @size: Size of the array
 * Return: Root of the tree
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *node = NULL, *left = NULL, *right = NULL;
	size_t i;

	if (!array)
		return (NULL);

	i = (size - 1) / 2;
	node = binary_tree_node(NULL, array[i]);
	if (i > 0)
		left = sorted_array_to_avl(array, i);
	if (left)
	{
		node->left = left;
		left->parent = node;
	}
	if (i < size - 1)
		right = sorted_array_to_avl(&array[i + 1], size - (i + 1));
	if (right)
	{
		node->right = right;
		right->parent = node;
	}

	return (node);
}
