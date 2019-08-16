/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_parent_active_elem.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 08:50:06 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/16 08:51:47 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	is_parent_active_elem(t_element *elem, t_element *parent)
{
	t_element *tmp;

	tmp = elem;
	while (tmp != NULL)
	{
		if (tmp == parent)
			return (1);
		tmp = (t_element *)elem->parent;
	}
	return (0);
}