/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ef_trnode_right_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 19:10:39 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/05/23 19:14:13 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ef_treap.h"

/*
** x: the node getting rotated down
** y: x's left child which is going to be rotated up
*/

void	ef_trnode_right_rotate(t_treap *tree, t_trnode *x)
{
	t_trnode	*y;

	if (tree && x && (y = x->left))
	{
		x->left = y->right;
		if (y->right)
			y->right->parent = x;
		y->parent = x->parent;
		if (!x->parent)
			tree->root = y;
		else if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
		y->right = x;
		x->parent = y;
	}
}
