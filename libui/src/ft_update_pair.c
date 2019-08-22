/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_pair.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 11:19:18 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/22 12:33:05 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	ft_update_pair(t_pair_of_int *pair)
{
	if (pair->old_from != *pair->ptr_from)
	{
		pair->old_from = *pair->ptr_from;
		*pair->ptr_to = *pair->ptr_from;
		pair->old_to = *pair->ptr_from;
	}
	if (!pair->one_way && pair->old_to != *pair->ptr_to)
	{
		pair->old_from = *pair->ptr_to;
		*pair->ptr_from = *pair->ptr_to;
		pair->old_to = *pair->ptr_to;
	}
}