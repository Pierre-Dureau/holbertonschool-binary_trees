#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Rotate a node to the right
 *
 * @tree: Root of the tree
 * Return: The new node
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *temp;

	if (!tree || !tree->left)
		return (NULL);

	temp = tree->left;
	tree->left = temp->right;
	if (temp->right)
		temp->right->parent = tree;
	temp->right = tree;
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
