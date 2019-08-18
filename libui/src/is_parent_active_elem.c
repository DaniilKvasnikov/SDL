/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_parent_active_elem.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 08:50:06 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/16 10:00:24 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	is_parent_active_elem(t_element *active, t_element *curr)
{
	t_element *tmp;

	tmp = active;
	while (tmp != NULL)
	{
		if (tmp == curr)
			return (1);
		tmp = (t_element *)tmp->parent;
	}
	return (0);
}