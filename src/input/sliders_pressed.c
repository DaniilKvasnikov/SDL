/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sliders_pressed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 19:54:07 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/23 19:16:13 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*sliders_pressed(void *win, t_element *elem, SDL_Event *ev, t_point_int *mouse)
{
	t_point_int	delta;
	t_win		*ptr_win;

	ptr_win = (t_win *)win;
	delta.x = mouse->x - elem->rect.x;
	delta.y = mouse->y - elem->rect.y;
	if (delta.x >= 0 && delta.x < elem->rect.w && delta.y >= 0 && delta.y < elem->rect.h)
		*elem->float_par = delta.x / (float)elem->rect.w;
	*elem->int_par = 255 * (*elem->float_par);
	return (elem);
}
