#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Rotate a node to the left
 *
 * @tree: Root of the tree
 * Return: The new node
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *temp;

	if (!tree || !tree->right)
		return (NULL);

	temp = tree->right;
	tree->right = temp->left;
	if (temp->left)
		temp->left->parent = tree;
	temp->left = tree;
	temp->parent = tree->parent;
	tree->parent = temp;
	if (temp->parent)
	{
		if (temp->parent->left == tree)
			temp->parent->left = temp;
		else
			temp->parent->right = temp;
	}

	return (temp);
}
