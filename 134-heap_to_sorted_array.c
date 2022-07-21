#include "binary_trees.h"

/**
 * __size - measures the size of a binary tree
 *
 * @tree: Root of the tree
 * Return: The size
 */

size_t __size(const binary_tree_t *tree)
{
	size_t s = 0;

	if (!tree)
		return (0);

	s = __size(tree->left) + __size(tree->right);

	return (s + 1);
}

/**
 * heap_to_sorted_array - Converts a Binary Max Heap
 * to a sorted array of integers
 *
 * @heap: Root of the tree
 * @size: size of the tree to initialize
 * Return: The sorted array
 */

int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *sorted = NULL;
	size_t i;

	if (!heap)
		return (NULL);
	*size = __size(heap);
	sorted = malloc(sizeof(int) * *size);
	if (!sorted)
		return (NULL);
	for (i = 0; i < *size; i++)
		sorted[i] = heap_extract(&heap);
	return (sorted);
}
