/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousebuttondown_win.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 13:09:06 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/31 11:20:43 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	mousebuttondown_win(t_win *win, SDL_Event *event)
{
	int			i;
	t_element	*elem;
	t_element	*prev;

	prev = win->active_elem;
	win->active_elem = NULL;
	i = -1;
	while (win->elements[++i])
	{
		elem = win->elements[i];
		if (*elem->active && chech_input_mouse(elem, &win->sdl_data->mouse))
		{
			if (elem->mouse_down)
				elem->mouse_down(elem, event);
			win->active_elem = elem;
			break;
		}
	}
	if (win->active_elem != prev && prev && prev->active_other)
		prev->active_other(prev, win->active_elem);
	win->sdl_data->drawing = (win->active_elem == NULL);
	win->mouse_down = win->sdl_data->mouse;
	win->mouse_muve = win->sdl_data->mouse;
}
