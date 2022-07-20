#include "binary_trees.h"

/**
 * array_to_heap - Builds a Max Binary Heap tree from an array
 *
 * @array: Array
 * @size: Size of the array
 * Return: Root of the tree
 */

heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *root = NULL;
	size_t i;

	for (i = 0; i < size; i++)
	{
		heap_insert(&root, array[i]);
	}
	return (root);
}
