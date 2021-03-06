/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ef_ntree_find.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 12:46:45 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/05/19 20:21:05 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ef_ntree.h"

t_ntree	*ef_ntree_in_order_find(t_ntree *tree, void *data, f_cmp cmp,
								int depth, t_flag part)
{
	t_ntree	*subtree;
	t_ntree	*node;

	if (!tree || depth == 0)
		return (NULL);
	--depth;
	node = ef_ntree_in_order_find(tree->children, data, cmp, depth, part);
	if (node)
		return (node);
	switch (part)
	{
		case LEAF:
			if (ef_ntree_is_leaf(tree) && (tree->data == data ||
									(cmp && cmp(tree->data, data) == 0)))
				return (tree);
			break ;
		case NON_LEAF:
			if (!ef_ntree_is_leaf(tree) && (tree->data == data ||
									(cmp && cmp(tree->data, data) == 0)))
				return (tree);
			break ;
		case WHOLE:
			if (tree->data == data || (cmp && cmp(tree->data, data) == 0))
				return (tree);
			break ;
	}
	if (tree->children)
		for (subtree = tree->children->next; subtree; subtree = subtree->next)
		{
			node = ef_ntree_in_order_find(subtree, data, cmp, depth, part);
			if (node)
				return (node);
		}
	return (NULL);
}

t_ntree	*ef_ntree_pre_order_find(t_ntree *tree, void *data, f_cmp cmp,
									int depth, t_flag part)
{
	t_ntree	*subtree;
	t_ntree	*node;

	if (!tree || depth == 0)
		return (NULL);
	switch (part)
	{
		case LEAF:
			if (ef_ntree_is_leaf(tree) && (tree->data == data ||
									(cmp && cmp(tree->data, data) == 0)))
				return (tree);
			break ;
		case NON_LEAF:
			if (!ef_ntree_is_leaf(tree) && (tree->data == data ||
									(cmp && cmp(tree->data, data) == 0)))
				return (tree);
			break ;
		case WHOLE:
			if (tree->data == data || (cmp && cmp(tree->data, data) == 0))
				return (tree);
			break ;
	}
	for (--depth, subtree = tree->children; subtree; subtree = subtree->next)
	{
		node = ef_ntree_pre_order_find(subtree, data, cmp, depth, part);
		if (node)
			return (node);
	}
	return (NULL);
}

t_ntree	*ef_ntree_post_order_find(t_ntree *tree, void *data, f_cmp cmp,
									int depth, t_flag part)
{
	t_ntree	*subtree;
	t_ntree	*node;

	if (!tree || depth == 0)
		return (NULL);
	for (--depth, subtree = tree->children; subtree; subtree = subtree->next)
	{
		node = ef_ntree_post_order_find(subtree, data, cmp, depth, part);
		if (node)
			return (node);
	}
	switch (part)
	{
		case LEAF:
			if (ef_ntree_is_leaf(tree) && (tree->data == data ||
									(cmp && cmp(tree->data, data) == 0)))
				return (tree);
			break ;
		case NON_LEAF:
			if (!ef_ntree_is_leaf(tree) && (tree->data == data ||
									(cmp && cmp(tree->data, data) == 0)))
				return (tree);
			break ;
		case WHOLE:
			if (tree->data == data || (cmp && cmp(tree->data, data) == 0))
				return (tree);
			break ;
	}
	return (NULL);
}

t_ntree	*ef_ntree_level_order_find(t_ntree *tree, void *data, f_cmp cmp,
									int depth, t_flag part)
{
	t_deque	*this_level;
	t_deque	*next_level;
	t_ntree	*node;

	this_level = ef_deque_create(ef_dlist_create(tree));
	while (!ef_deque_is_empty(this_level) && depth-- != 0)
	{
		next_level = ef_deque_create(NULL);
		while (!ef_deque_is_empty(this_level))
		{
			for (node = ef_deque_pop_head(this_level); node; node = node->next)
			{
				switch (part)
				{
					case LEAF:
						if (ef_ntree_is_leaf(node) && (node->data == data ||
								(cmp && cmp(node->data, data) == 0)))
						{
							ef_deque_free(this_level, NULL);
							ef_deque_free(next_level, NULL);
							return (node);
						}
						break ;
					case NON_LEAF:
						if (!ef_ntree_is_leaf(node) && (node->data == data ||
								(cmp && cmp(node->data, data) == 0)))
						{
							ef_deque_free(this_level, NULL);
							ef_deque_free(next_level, NULL);
							return (node);
						}
						break ;
					case WHOLE:
						if (node->data == data ||
								(cmp && cmp(node->data, data) == 0))
						{
							ef_deque_free(this_level, NULL);
							ef_deque_free(next_level, NULL);
							return (node);
						}
						break ;
				}
				if (node->children)
					ef_deque_push_tail(next_level, node->children);
			}
		}
		ef_deque_free(this_level, NULL);
		this_level = next_level;
	}
	ef_deque_free(this_level, NULL);
	return (NULL);
}

t_ntree	*ef_ntree_find(t_ntree *tree, void *data, f_cmp cmp, int depth,
						t_flag order, t_flag part)
{
	if (!tree || !(LEAF <= part && part <= WHOLE))
		return (NULL);
	switch (order)
	{
		case IN_ORDER:
			return (ef_ntree_in_order_find(tree, data, cmp, depth, part));
		case PRE_ORDER:
			return (ef_ntree_pre_order_find(tree, data, cmp, depth, part));
		case POST_ORDER:
			return (ef_ntree_post_order_find(tree, data, cmp, depth, part));
		case LEVEL_ORDER:
			return (ef_ntree_level_order_find(tree, data, cmp, depth, part));
		default:
			ft_dprintf(2, "Warning: invalid order flag\n");
			return (NULL);
	}
}
