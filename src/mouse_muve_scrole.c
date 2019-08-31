/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_muve_scrole.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 17:29:16 by ilyabaturin       #+#    #+#             */
/*   Updated: 2019/08/31 11:43:54 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

void
	mouse_muve_scrole(t_win *win, t_point delta_mouse)
{
	float	delta;

	if (win->sdl_data->draw_type != NO_DRAW)
		return ;
	delta = 1.1f;
	if (delta_mouse.y > 0 && win->win_rect.w > 1 && win->win_rect.h > 1)
		win->scale /= delta;
	else if (delta_mouse.y < 0 && win->win_rect.w < win->full.w * 4 && win->win_rect.h < win->full.h * 4)
		win->scale *= delta;
	win->win_rect.w = win->scale * win->full.w;
	win->win_rect.h = win->scale * win->full.h;
}
