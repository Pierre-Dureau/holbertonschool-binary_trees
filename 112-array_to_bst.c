#include "binary_trees.h"

/**
 * array_to_bst - builds a Binary Search Tree from an array
 *
 * @array: Array of int
 * @size: Size of the array
 * Return: The root node
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL, *node, *temp;
	size_t i, check = 0;

	for (i = 0; i < size; i++)
	{
		if (i == 0)
			root = binary_tree_node(NULL, array[i]);
		else
		{
			node = root;
			while (1)
			{
				temp = node;
				if (node->n > array[i])
				{
					node = node->left;
					check = 1;
				}
				else if (node->n < array[i])
				{
					node = node->right;
					check = 2;
				}

				if (!node)
				{
					node = binary_tree_node(temp, array[i]);
					if (check == 1)
						temp->left = node;
					else
						temp->right = node;
					break;
				}
				if (node->n == array[i])
					break;
			}
		}
	}
	return (root);
}
