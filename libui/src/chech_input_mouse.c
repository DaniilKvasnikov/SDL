/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chech_input_mouse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 15:04:15 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 15:04:27 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	chech_input_mouse(t_element *elem, t_point *mouse)
{
	int	min_x;
	int	max_x;
	int	min_y;
	int	max_y;

	min_x = ft_min_int(elem->rect.x, elem->rect.x + elem->rect.w);
	max_x = ft_max_int(elem->rect.x, elem->rect.x + elem->rect.w);
	min_y = ft_min_int(elem->rect.y, elem->rect.y + elem->rect.h);
	max_y = ft_max_int(elem->rect.y, elem->rect.y + elem->rect.h);
	return (mouse->x >= min_x && mouse->x <= max_x
			&& mouse->y >= min_y && mouse->y <= max_y);
}
