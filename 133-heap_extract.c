#include "binary_trees.h"

/**
 * binary_tree_node - Create a node
 *
 * @parent: Parent of the node
 * @value: value of the node
 * Return: The node
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	node = malloc(sizeof(binary_tree_t));
	if (!node)
		return (NULL);

	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	node->n = value;

	return (node);
}

/**
 * get_last - get the last node of the tree
 *
 * @root: Root of the tree
 * @i: Index of the last node
 * @size: size of the array
 * Return: The last node
 */

heap_t *get_last(heap_t *root, size_t i, size_t size)
{
	heap_t *left, *right;

	if (i == size)
		return (root);
	if (i > size)
		return (NULL);

	left = get_last(root->left, 2 * i + 1, size);
	right = get_last(root->right, 2 * i + 2, size);

	if (left)
		return (left);
	else if (right)
		return (right);
	else
		return (NULL);
}

/**
 * heap_extract - Extract the root of a Heap Binary Tree
 *
 * @root: Root of the tree
 * Return: The number extract
 */

int heap_extract(heap_t **root)
{
	heap_t *last, *temp = *root;
	size_t size;
	int extract;

	if (!*root)
		return (0);
	extract = (*root)->n;
	size = binary_tree_size(*root);
	last = get_last(*root, 0, size - 1);
	while (temp->left)
	{
		if (!temp->right || temp->left->n > temp->right->n)
		{
			temp->n = temp->left->n;
			temp = temp->left;
		}
		else
		{
			temp->n = temp->right->n;
			temp = temp->right;
		}
	}
	temp->n = last->n;
	if (last->parent->left && last->parent->left->n == last->n)
		last->parent->left = NULL;
	else
		last->parent->right = NULL;
	free(last);
	return (extract);
}
