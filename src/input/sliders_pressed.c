/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sliders_pressed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 19:54:07 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/16 08:45:51 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*sliders_pressed(void *win, void *but, SDL_Event *ev, t_point_int *mouse)
{
	t_element	*elem;
	t_point_int	delta;
	t_win		*ptr_win;

	ptr_win = (t_win *)win;
	elem = (t_element *)but;
	delta.x = mouse->x - elem->pos.x;
	delta.y = mouse->y - elem->pos.y;
	if (delta.x >= 0 && delta.x < elem->size.x
		&& delta.y >= 0 && delta.y < elem->size.y)
	{
		elem->float_par = delta.x / (float)elem->size.x;
	}
	else
		ptr_win->active_element = NULL;
	return (0);
}
