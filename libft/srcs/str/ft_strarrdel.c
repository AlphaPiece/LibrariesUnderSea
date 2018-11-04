/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 10:51:17 by zwang             #+#    #+#             */
/*   Updated: 2018/11/04 15:04:37 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Precondition: arr is null-terminated and every element is mallocked
*/

void	ft_strarrdel(char *arr[])
{
	size_t	i;

	i = 0;
	while (arr[i])
		ft_memfree((void **)&arr[i++]);
	free(arr);
}
