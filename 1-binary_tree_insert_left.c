#include "binary_trees.h"

/**
 * binary_tree_insert_left - Create a node at the left
 *
 * @parent: Parent of the node
 * @value: value of the node
 * Return: The node
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;
	binary_tree_t *temp;

	if (!parent)
		return (NULL);

	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);
	new->n = value;
	new->right = NULL;
	new->parent = parent;

	if (parent->left)
	{
		temp = parent->left;
		new->left = temp;
		temp->parent = new;
	}
	else
		new->left = NULL;

	parent->left = new;

	return (new);
}
