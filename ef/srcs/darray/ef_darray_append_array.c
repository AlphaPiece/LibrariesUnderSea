/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ef_darray_append_array.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:13:35 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/04/25 20:30:36 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libef.h"

void	ef_darray_append_array(t_darray *darr, void *arr, int arr_len)
{
	t_rdarray	*rdarr;

	if (!darr || !arr || !arr_len)
		return ;
	rdarr = (t_rdarray *)darr;
	if (rdarr->elem_no + arr_len > rdarr->capacity)
		ef_darray_expand_capacity(darr, arr_len);
	ft_memcpy(rdarr->data + rdarr->elem_size * rdarr->elem_no, arr,
				rdarr->elem_size * arr_len);
	rdarr->elem_no += arr_len;
}