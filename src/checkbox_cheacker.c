/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkbox_cheacker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 09:03:37 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/14 12:36:51 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	gr_cheacker(t_group_e *group, void *elem)
{
	int	i;

	i = -1;
	while (++i < group->count)
		if ((t_element *)group->elements[i] == elem)
			break ;
	if (i == group->count)
		return (1);
	i = -1;
	while (++i < group->count)
		if ((t_element *)group->elements[i] != elem)
			((t_element *)group->elements[i])->int_par = 0;
	return (0);
}
