/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mouse_muve_left.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyabaturin <ilyabaturin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 12:05:08 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/26 18:02:57 by ilyabaturin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

void
	main_mouse_muve_left(t_win *win, t_point delta_mouse)
{
	win->win_rect.x -= delta_mouse.x;
	win->win_rect.y -= delta_mouse.y;
	if (win->win_rect.x < -win->full.w)
		win->win_rect.x = -win->full.w;
	if (win->win_rect.x > win->full.w)
		win->win_rect.x = win->full.w;
	if (win->win_rect.y < -win->full.h)
		win->win_rect.y = -win->full.h;
	if (win->win_rect.y > win->full.h)
		win->win_rect.y = win->full.h;
}
