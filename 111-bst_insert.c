#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 *
 * @tree: Root of the tree
 * @value: Value to insert
 * Return: The inserted node
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *node, *temp;
	int check = 0;

	if (!(*tree))
	{
		node = binary_tree_node(NULL, value);
		*tree = node;
		return (node);
	}
	node = *tree;
	while (1)
	{
		temp = node;
		if (node->n > value)
		{
			node = node->left;
			check = 1;
		}
		else if (node->n < value)
		{
			node = node->right;
			check = 2;
		}

		if (!node)
		{
			node = binary_tree_node(temp, value);
			if (check == 1)
				temp->left = node;
			else
				temp->right = node;
			return (node);
		}
		if (node->n == value)
			return (NULL);
	}
}
