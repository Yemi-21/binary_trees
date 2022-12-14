#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stdlib.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;

binary_tree_t *binary_trees_ancestor(const binary_tree_t *prmFirst, const binary_tree_t *prmSecond);
int binary_tree_balance(const binary_tree_t *prmTree);
int binary_tree_is_complete(const binary_tree_t *prmTree);
void binary_tree_delete(binary_tree_t *prmTree);
size_t binary_tree_depth(const binary_tree_t *prmTree);
size_t binary_tree_height(const binary_tree_t *tree);
void binary_tree_inorder(const binary_tree_t *prmTree, void (*prmFunc)(int));
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
int binary_tree_is_bst(const binary_tree_t *prmTree);
int binary_tree_is_full(const binary_tree_t *prmTree);
int binary_tree_is_leaf(const binary_tree_t *prmNode);
int binary_tree_is_perfect(const binary_tree_t *prmTree);
int binary_tree_is_root(const binary_tree_t *prmNode);
size_t binary_tree_leaves(const binary_tree_t *prmTree);
void binary_tree_levelorder(const binary_tree_t *prmTree, void (*prmFunc)(int));
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
size_t binary_tree_nodes(const binary_tree_t *tree);
void binary_tree_postorder(const binary_tree_t *prmTree, void (*prmFunc)(int));
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_print(const binary_tree_t *);
binary_tree_t *binary_tree_rotate_left(binary_tree_t *prmTree);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *prmTree);
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
size_t binary_tree_size(const binary_tree_t *tree);
binary_tree_t *binary_tree_uncle(binary_tree_t *node);
bst_t *array_to_bst(int *prmArray, size_t prmSize);
bst_t *bst_insert(bst_t **prmTree, int prmValue);
bst_t *bst_search(const bst_t *prmTree, int prmValue);
bst_t *inorder_successor(bst_t *root);
bst_t *bst_delete(bst_t *root, bst_t *node);
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value);
bst_t *bst_remove(bst_t *root, int value);
size_t height(const binary_tree_t *tree);
int is_avl_helper(const binary_tree_t *tree, int lo, int hi);
int binary_tree_is_avl(const binary_tree_t *tree);
size_t height(const binary_tree_t *tree);
int balance(const binary_tree_t *tree);
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,avl_t **new, int value);
avl_t *avl_insert(avl_t **tree, int value);
avl_t *aux_sort(avl_t *parent, int *array, int begin, int last);
avl_t *sorted_array_to_avl(int *array, size_t size);
size_t binary_tree_height(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
int tree_is_perfect(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);
int binary_tree_is_heap(const binary_tree_t *tree);
heap_t *array_to_heap(int *array, size_t size);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
heap_t *check_new_root(heap_t **root, heap_t *new_root);
void if_check(heap_t *new_root, heap_t *tmp, heap_t *current);
void loop_heap(heap_t **root, heap_t *new_root);
int heap_extract(heap_t **root);

#endif
