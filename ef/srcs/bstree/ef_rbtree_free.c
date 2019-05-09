/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ef_rbtree_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 15:52:31 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/05/08 23:16:03 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libef.h"

void	ef_rbtree_free(t_rbtree *tree, f_del del_key, f_del del_value)
{
	if (tree)
	{
		if (del_key)
			del_key(tree->key);
		if (del_value)
			del_value(tree->value);
		free(tree);
	}
}