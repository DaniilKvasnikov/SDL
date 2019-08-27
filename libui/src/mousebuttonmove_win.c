/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousebuttonmove_win.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyabaturin <ilyabaturin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 13:09:23 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/27 10:53:04 by ilyabaturin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	mousebuttonmove_win(t_win *win, SDL_Event *event)
{
	t_point	last_mouse;
	if (event->button.button == SDL_BUTTON_LEFT)
	{
		last_mouse = win->mouse_muve;
		win->mouse_muve = g_sdl_data->mouse;
		if (win->mouse_muve_left && g_sdl_data->draw_type == NO_DRAW)
			win->mouse_muve_left(win,
			(t_point){last_mouse.x - win->mouse_muve.x,
						last_mouse.y - win->mouse_muve.y});
		if (win->active_elem->mouse_move)
			win->active_elem->mouse_move(win->active_elem, event);
	}
}
