/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 19:48:05 by zwang             #+#    #+#             */
/*   Updated: 2018/09/11 10:35:34 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_chr.h"

int		ft_tolower(int c)
{
	return ((c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c);
}