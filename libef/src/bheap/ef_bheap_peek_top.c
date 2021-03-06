/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ef_bheap_peek_top.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 17:39:44 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/05/17 15:47:48 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ef_bheap.h"

t_kvpair	*ef_bheap_peek_top(t_bheap *heap)
{
	if (heap && ef_bheap_size(heap) > 0)
		return ((t_kvpair *)ef_darray_get(heap->array, 1));
	return (NULL);
}
