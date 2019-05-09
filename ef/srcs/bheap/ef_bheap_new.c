/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ef_bheap_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 13:00:46 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/05/09 00:02:32 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libef.h"

t_bheap	*ef_bheap_new(f_cmp cmp)
{
	t_bheap	*heap;

	heap = ef_bheap_alloc();
	heap->array = ef_darray_new(sizeof(void *));
	heap->cmp = cmp;
	return (heap);
}
