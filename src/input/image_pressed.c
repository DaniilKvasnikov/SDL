/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_pressed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 05:52:38 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/17 06:09:20 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*image_pressed(void *ptr_win, void *ptr_elem, SDL_Event *ev, t_point_int *mouse)
{
	t_win 		*win;
	t_element	*elem;

	win =(t_win *)ptr_win;
	elem = (t_element *)ptr_elem;
	if (win->active_element == elem)
	{
		elem->pos = (t_point){mouse->x - elem->last_delta.x, mouse->y - elem->last_delta.y};
		ft_printf("image pressed\n");
	}
	return (elem);
}