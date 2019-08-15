/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chech_input_mouse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 10:03:28 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/15 10:06:48 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	chech_input_mouse(t_element *elem, t_point_int *mouse)
{
	return (mouse->x >= elem->pos.x && mouse->x <= (elem->pos.x + elem->size.x)
			&& mouse->y >= elem->pos.y && mouse->y <= (elem->pos.y + elem->size.y));
}