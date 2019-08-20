/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chech_input_mouse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 10:03:28 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/20 14:56:05 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	chech_input_mouse(t_element *elem, t_point_int *mouse)
{
	int	min_x;
	int	max_x;
	int	min_y;
	int	max_y;

	min_x = ft_min_int(elem->pos.x, elem->pos.x + elem->size.x);
	max_x = ft_max_int(elem->pos.x, elem->pos.x + elem->size.x);
	min_y = ft_min_int(elem->pos.y, elem->pos.y + elem->size.y);
	max_y = ft_max_int(elem->pos.y, elem->pos.y + elem->size.y);
	return (mouse->x >= min_x && mouse->x <= max_x
			&& mouse->y >= min_y && mouse->y <= max_y);
}