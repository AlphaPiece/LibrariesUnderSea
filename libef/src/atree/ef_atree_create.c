/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ef_atree_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 18:04:49 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/05/13 22:50:01 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ef_atree.h"

t_atree	*ef_atree_create(f_cmp cmp_key, f_del del_key, f_del del_value)
{
	t_atree	*tree;

	if (!cmp_key)
		return (NULL);
	tree = ef_atree_alloc();
	tree->root = NULL;
	tree->cmp_key = cmp_key;
	tree->del_key = del_key;
	tree->del_value = del_value;
	tree->size = 0;
	return (tree);
}
