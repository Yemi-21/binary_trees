#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @prmTree: tree to measure
 * Return: tree height
 */
size_t binary_tree_height(const binary_tree_t *prmTree)
{
	size_t lHeight, rHeight;

	if (prmTree == NULL)
		return (0);

	lHeight = prmTree->left ? 1 + binary_tree_height(prmTree->left) : 0;
	rHeight = prmTree->right ? 1 + binary_tree_height(prmTree->right) : 0;
	return (lHeight > rHeight ? lHeight : rHeight);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 *
 * @prmTree: tree to balance
 * Return: left height - right balance
 */
int binary_tree_balance(const binary_tree_t *prmTree)
{
	int lHeight, rHeight;

	if (prmTree == NULL)
		return (0);

	lHeight = prmTree->left ? (int) binary_tree_height(prmTree->left) : -1;
	rHeight = prmTree->right ? (int) binary_tree_height(prmTree->right) : -1;

	return (lHeight - rHeight);
}
