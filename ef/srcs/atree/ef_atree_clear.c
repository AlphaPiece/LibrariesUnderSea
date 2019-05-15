/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ef_atree_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 23:15:28 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/05/15 09:43:30 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libef.h"

void	ef_atree_clear(t_atree *tree)
{
	t_deque	*stack;
	t_anode	*node;

	if (tree)
	{
		stack = ef_deque_create(ef_dlist_create(tree->root));
		while (!ef_deque_is_empty(stack))
		{
			node = ef_deque_pop_head(stack);
			ft_printf("%d\n", *(int *)node->key);
			if (node->right)
				ef_deque_push_head(stack, node->right);
			if (node->left)
				ef_deque_push_head(stack, node->left);
			ef_anode_free(node, tree->del_key, tree->del_value);
		}
		ef_deque_free(stack, NULL);
		tree->size = 0;
	}
}
