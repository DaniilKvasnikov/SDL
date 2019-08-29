/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousebuttondown_win.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyabaturin <ilyabaturin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 13:09:06 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/29 09:21:31 by ilyabaturin      ###   ########.fr       */
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
		if (*elem->active && chech_input_mouse(elem, &g_sdl_data->mouse))
		{
			if (elem->mouse_down)
				elem->mouse_down(elem, event);
			win->active_elem = elem;
			break;
		}
	}
	if (win->active_elem != prev && prev && prev->active_other)
		prev->active_other(prev, win->active_elem);
	g_sdl_data->drawing = (win->active_elem == NULL);
	win->mouse_down = g_sdl_data->mouse;
	win->mouse_muve = g_sdl_data->mouse;
}
