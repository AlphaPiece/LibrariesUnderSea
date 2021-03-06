/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ef_ntree_append_child.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 14:23:06 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/04/30 22:46:41 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ef_ntree.h"

void	ef_ntree_append_child(t_ntree *parent, t_ntree *child)
{
	t_ntree	*last;

	if (!parent || !child)
		return ;
	else if (!parent->children)
	{
		parent->children = child;
		child->prev = NULL;
	}
	else
	{
		last = ef_ntree_last_child(parent);
		last->next = child;
		child->prev = last;
	}
	child->parent = parent;
	child->next = NULL;
}

