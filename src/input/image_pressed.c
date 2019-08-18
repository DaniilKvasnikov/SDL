/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_pressed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 05:52:38 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/18 16:39:58 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*image_pressed(void *ptr_win, void *ptr_elem, SDL_Event *ev, t_point_int *mouse)
{
	t_win 		*win;
	t_element	*elem;
	t_point		delta_mouse;

	win =(t_win *)ptr_win;
	elem = (t_element *)ptr_elem;
	if (win->active_element == elem)
	{
		delta_mouse = (t_point){elem->last_delta.x - (mouse->x - elem->pos.x),
								elem->last_delta.y - (mouse->y - elem->pos.y)};
		if (elem->last_delta.x >= elem->size.x - 10 &&
			elem->last_delta.y >= elem->size.y - 10)
		{
			elem->size = (t_point){elem->size.x - delta_mouse.x, elem->size.y - delta_mouse.y};
			elem->last_delta.x -= delta_mouse.x;
			elem->last_delta.y -= delta_mouse.y;
		}
		else if (elem->last_delta.x <= 10 &&
			elem->last_delta.y <= 10)
		{
			elem->pos = (t_point){mouse->x - elem->last_delta.x, mouse->y - elem->last_delta.y};
			elem->size = (t_point){elem->size.x + delta_mouse.x, elem->size.y + delta_mouse.y};
		}
		else
			elem->pos = (t_point){mouse->x - elem->last_delta.x, mouse->y - elem->last_delta.y};
	}
	return (elem);
}