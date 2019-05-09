/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bstree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 09:23:07 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/05/08 22:55:39 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libef.h"

#define COUNT	10

void	btview(t_bstree *tree, t_rbtree *node, int space)
{
	if (node == tree->nil)
		return ;
	space += COUNT;
	btview(tree, node->right, space);
	ft_putchar('\n');
	ft_putnchar(' ', space - COUNT);
    ft_printf("%d-", *(int *)node->key);
    ft_printf((node->color == R) ? "R, " : "B, ");
	ft_putchar('\n');
	btview(tree, node->left, space);
}

void	view_tree(t_bstree *tree)
{
	btview(tree, tree->root, 0);
}

int		cmp_int(void *n1, void *n2)
{
	if (*(int *)n1 > *(int *)n2)
		return (1);
	else if (*(int *)n1 < *(int *)n2)
		return (-1);
	else
		return (0);
}

void	*print_both(void *key, void *value)
{
	ft_printf("%d, %s\n", *(int *)key, (char *)value);
	return (value);
}

void	*print_key(void *key, void *value)
{
	ft_printf("%d, ", *(int *)key);
	return (value);
}

void	print_node(t_bstree *tree, t_rbtree *node)
{
	if (node == tree->nil)
		return ;
	print_node(tree, node->left);
	ft_printf("%d-", *(int *)node->key);
	ft_printf((node->color == R) ? "R, " : "B, ");
	print_node(tree, node->right);
}

void	print_tree(t_bstree *tree)
{
	print_node(tree, tree->root);
	ft_printf("\n");
}

void	test(void)
{
	t_bstree	*tree;
	t_rbtree	*node;
	int			arr[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	int			i;

	tree = ef_bstree_new(cmp_int, NULL, NULL);
	for (i = 0; i < 17; i++)
		ef_bstree_set(tree, &arr[i], &arr[i]);
	print_tree(tree);

/*	ef_bstree_remove(tree, &arr[7]);
	print_tree(tree);
	ft_printf("root: %d\n", *(int *)tree->root->key);
	ef_bstree_remove(tree, &arr[3]);
	print_tree(tree);
	ft_printf("root: %d\n", *(int *)tree->root->key);
*/
	view_tree(tree);
	ft_printf("size: %d\n", ef_bstree_size(tree));
	ft_printf("height: %d\n", ef_bstree_height(tree));

//	ft_printf("%d\n", *(int *)ef_bstree_get(tree, &arr[3]));
//	ft_printf("%d\n", *(int *)ef_bstree_get(tree, &arr[6]));

	ef_bstree_free(tree);
}

int		main(void)
{
	test();

	while (1);

	return (0);
}