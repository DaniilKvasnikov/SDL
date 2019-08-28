/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_muve_scrole.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyabaturin <ilyabaturin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 17:29:16 by ilyabaturin       #+#    #+#             */
/*   Updated: 2019/08/28 09:14:05 by ilyabaturin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

void
	mouse_muve_scrole(t_win *win, t_point delta_mouse)
{
	float	delta;

	if (g_sdl_data->draw_type != NO_DRAW)
		return ;
	delta = 1.1f;
	if (delta_mouse.y > 0 && win->win_rect.w > 1 && win->win_rect.h > 1)
		win->scale /= delta;
	else if (delta_mouse.y < 0 && win->win_rect.w < win->full.w * 4 && win->win_rect.h < win->full.h * 4)
		win->scale *= delta;
	win->win_rect.w = win->scale * win->full.w;
	win->win_rect.h = win->scale * win->full.h;
}
