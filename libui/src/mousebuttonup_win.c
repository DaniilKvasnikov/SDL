/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousebuttonup_win.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 13:08:31 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/26 11:13:19 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	mousebuttonup_win(t_win *win, SDL_Event *event)
{
	ft_putstr("up\n");
	if ((win->mouse_down.x != win->mouse_muve.x ||
		win->mouse_down.y != win->mouse_muve.y) &&
		get_layers_count(win) > 1 && g_sdl_data->drawing)
		draw_elem_to_tex(win, 0);
	else if (get_layers_count(win) > 1 && g_sdl_data->drawing)
		cur_texture_draw(win, 0);
	g_sdl_data->drawing = 0;
	win->mouse_muve = win->mouse_down;
}
