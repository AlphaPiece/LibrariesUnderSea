/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ef_rbtree_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:47:26 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/05/10 10:57:02 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libef.h"

void	ef_rbtree_clear(t_rbtree *tree)
{
	t_rbnode	*node;
	t_deque		*stack;

	if (tree)
	{
		node = tree->root;
		stack = ef_deque_create(ef_dlist_create(node));
		while (!ef_deque_is_empty(stack))
		{
			node = ef_deque_pop_head(stack);
			if (node->left != tree->nil)
				ef_deque_push_head(stack, node->left);
			if (node->right != tree->nil)
				ef_deque_push_head(stack, node->right);
			ef_rbnode_free(node, tree->del_key, tree->del_value);
		}
		ef_deque_free(stack, NULL);
		tree->size = 0;
	}
}