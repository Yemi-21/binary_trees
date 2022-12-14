#include "binary_trees.h"

size_t height(const binary_tree_t *prmTree);
int balance(const binary_tree_t *prmTree);
avl_t *avl_insert_recursive(avl_t **prmTree, avl_t *prmParent,
				avl_t **new, int prmValue);
avl_t *avl_insert(avl_t **prmTree, int prmValue);

/**
 * height - Measures the height of a binary tree.
 * @prmTree: A pointer to the root node of the tree to measure the height.
 * Return: If tree is NULL, your function must return 0, else return height.
 */

size_t height(const binary_tree_t *prmTree)
{
	if (prmTree != NULL)
	{
		size_t l = 0, r = 0;

		l = prmTree->left ? 1 + binary_tree_height(prmTree->left) : 1;
		r = prmTree->right ? 1 + binary_tree_height(prmTree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}

/**
 * balance - Measures the balance factor of a binary tree.
 * @prmTree: A pointer to the root node of the tree to measure the balance factor.
 * Return: If tree is NULL, return 0, else return balance factor.
 */

int balance(const binary_tree_t *prmTree)
{
	return (prmTree != NULL ? height(prmTree->left) - height(prmTree->right) : 0);
}

/**
 * avl_insert_recursive - Inserts a value into an AVL tree recursively.
 * @prmTree: A double pointer to the root node of the AVL tree to insert into.
 * @prmParent: The parent node of the current working node.
 * @new: A double pointer to store the new node.
 * @prmValue: The value to insert into the AVL tree.
 * Return: A pointer to the new root after insertion, or NULL on failure.
 */

avl_t *avl_insert_recursive(avl_t **prmTree, avl_t *prmParent,
				avl_t **new, int prmValue)
{
	int bfactor;

	if (*prmTree == NULL)
		return (*new = binary_tree_node(prmParent, prmValue));
	if ((*prmTree)->n > prmValue)
	{
		(*prmTree)->left = avl_insert_recursive(&(*prmTree)->left, *prmTree, new, prmValue);
		if ((*prmTree)->left == NULL)
			return (NULL);
	}
	else if ((*prmTree)->n < prmValue)
	{
		(*prmTree)->right = avl_insert_recursive(&(*prmTree)->right, *prmTree, new, prmValue);
		if ((*prmTree)->right == NULL)
			return (NULL);
	}
	else
		return (*prmTree);

	bfactor = balance(*prmTree);

	if (bfactor > 1 && (*prmTree)->left->n > prmValue)
		*prmTree = binary_tree_rotate_right(*prmTree);
	else if (bfactor < -1 && (*prmTree)->right->n < prmValue)
		*prmTree = binary_tree_rotate_left(*prmTree);
	else if (bfactor > 1 && (*prmTree)->left->n <prmValue)
	{
		(*prmTree)->left = binary_tree_rotate_left((*prmTree)->left);
		*prmTree = binary_tree_rotate_right(*prmTree);
	}
	else if (bfactor < -1 && (*prmTree)->right->n > prmValue)
	{
		(*prmTree)->right = binary_tree_rotate_right((*prmTree)->right);
		*prmTree = binary_tree_rotate_left(*prmTree);
	}
	return (*prmTree);
}

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @prmTree: A double pointer to the root node of the AVL tree to insert into.
 * @prmValue: The value to insert into the AVL tree.
 * Return: A pointer to the inserted node, or NULL on failure.
 */

avl_t *avl_insert(avl_t **prmTree, int prmValue)
{
	avl_t *new = NULL;

	if (prmTree == NULL)
		return (NULL);
	if (*prmTree == NULL)
	{
		*prmTree = binary_tree_node(NULL, prmValue);
		return (*tree);
	}
	avl_insert_recursive(prmTree, *prmTree, &new, prmValue);
	return (new);
}
