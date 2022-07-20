#include "binary_trees.h"

/**
 * binary_tree_insert_right - Create a node at the right
 *
 * @parent: Parent of the node
 * @value: value of the node
 * Return: The node
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;
	binary_tree_t *temp;

	if (!parent)
		return (NULL);

	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);
	new->n = value;
	new->left = NULL;
	new->parent = parent;

	if (parent->right)
	{
		temp = parent->right;
		new->right = temp;
		temp->parent = new;
	}
	else
		new->right = NULL;

	parent->right = new;

	return (new);
}
