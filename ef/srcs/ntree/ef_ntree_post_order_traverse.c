/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ef_ntree_post_order_traverse.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 14:20:18 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/04/29 21:19:34 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libef.h"

void	ef_ntree_post_order_traverse(t_ntree *tree, int depth, f_trv trv,
										t_traverse_flag part)
{
	t_ntree	*subtree;

	if (!tree || depth == 0)
		return ;
	for (--depth, subtree = tree->children; subtree; subtree = subtree->next)
		ef_ntree_post_order_traverse(subtree, depth, trv, part);
	switch (part)
	{
		case LEAF:
			if (!tree->children)
				tree->data = trv(tree->data);
			break ;
		case NON_LEAF:
			if (tree->children)
				tree->data = trv(tree->data);
			break ;
		case ALL:
			tree->data = trv(tree->data);
			break ;
	}
}