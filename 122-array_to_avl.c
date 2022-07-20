#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array
 *
 * @array: Array to convert
 * @size: Size of the array
 * Return: Node to the created AVL tree
 */

avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL, *node;
	size_t i;

	for (i = 0; i < size; i++)
	{
		node = avl_insert(&tree, array[i]);
		if (!node)
			return (NULL);
	}

	return (tree);
}
