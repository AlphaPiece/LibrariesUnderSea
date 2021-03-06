/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ef_slist_insert_after.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 13:13:26 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/05/10 10:48:46 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ef_slist.h"

t_slist	*ef_slist_insert_after(t_slist *list, void *data, t_slist *node)
{
	return (ef_slist_insert_list_after(list, ef_slist_create(data), node));
}
