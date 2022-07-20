#include "binary_trees.h"

/**
 * get_node - Get the node to remove
 *
 * @root: Root of the tree
 * @value: Value to search
 * Return: The node
 */

bst_t *get_node(bst_t *root, int value)
{
	bst_t *node = root;

	while (node->n != value)
	{
		if (node->n > value)
			node = node->left;
		if (node->n < value)
			node = node->right;
		if (!node)
			return (NULL);
	}

	return (node);
}

/**
 * remove_no_child - Remove the node when it got no child
 *
 * @root: Root of the tree
 * @node: The node
 */

void remove_no_child(bst_t **root, bst_t *node)
{
	if (node->parent)
	{
		if (node->parent->left && node->parent->left->n == node->n)
			node->parent->left = NULL;
		else
			node->parent->right = NULL;
		(void)root;
	}
	else
		*root = NULL;
	free(node);
}

/**
 * remove_one_child - Remove the node when it got one child
 *
 * @root: Root of the tree
 * @node: Node to remove
 */

void remove_one_child(bst_t **root, bst_t *node)
{
	bst_t *temp;

	if (!node->left)
		temp = node->right;
	else
		temp = node->left;
	if (node->parent)
	{
		if (node->parent->left && node->parent->left->n == node->n)
			node->parent->left = temp;
		else
			node->parent->right = temp;
	}
	temp->parent = node->parent;
	if (node == *root)
		*root = temp;
	free(node);
}

/**
 * remove_two_childs - Remove the node when it got two childs
 *
 * @node: The node
 */

void remove_two_childs(bst_t *node)
{
	bst_t *temp;

	temp = node->right;
	while (temp->left)
		temp = temp->left;
	node->n = temp->n;
	if (temp->parent == node)
	{
		temp->parent->right = temp->right;
		if (temp->right)
			temp->right->parent = temp->parent;
	}
	else if (temp->right)
	{
		temp->parent->left = temp->right;
		temp->right->parent = temp->parent;
	}
	else
		temp->parent->left = NULL;
	free(temp);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree
 *
 * @root: Root of the tree
 * @value: Value to remove
 * Return: The new node at the removed place
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node;

	if (!root)
		return (NULL);
	node = get_node(root, value);
	if (!node)
		return (root);
	if (!node->left && !node->right)
		remove_no_child(&root, node);
	else if (!node->left || !node->right)
		remove_one_child(&root, node);
	else
		remove_two_childs(node);
	return (root);
}
