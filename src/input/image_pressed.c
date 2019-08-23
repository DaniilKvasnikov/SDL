/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_pressed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 05:52:38 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/23 19:24:39 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*image_pressed(void *ptr_win, t_element *elem, SDL_Event *ev, t_point_int *mouse)
{
	t_win 		*win;
	t_point		delta_mouse;

	win =(t_win *)ptr_win;
	if (win->active_element == elem)
	{
		delta_mouse = (t_point){elem->last_delta.x - (mouse->x - elem->rect.x),
								elem->last_delta.y - (mouse->y - elem->rect.y)};
		if (elem->last_delta.x >= elem->rect.w - 10 &&
			elem->last_delta.y >= elem->rect.h - 10)
		{
			elem->rect.w = elem->rect.w - delta_mouse.x;
			elem->rect.h = elem->rect.h - delta_mouse.y;
			elem->last_delta.x -= delta_mouse.x;
			elem->last_delta.y -= delta_mouse.y;
		}
		else if (elem->last_delta.x <= 10 &&
			elem->last_delta.y <= 10)
		{
			elem->rect = (t_rect){mouse->x - elem->last_delta.x, mouse->y - elem->last_delta.y, elem->rect.w + delta_mouse.x, elem->rect.h + delta_mouse.y};
		}
		else
		{
			elem->rect.x = mouse->x - elem->last_delta.x;
			elem->rect.y = mouse->y - elem->last_delta.y;
		}
	}
	return (elem);
}