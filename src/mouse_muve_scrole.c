/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_muve_scrole.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyabaturin <ilyabaturin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 17:29:16 by ilyabaturin       #+#    #+#             */
/*   Updated: 2019/08/26 18:07:13 by ilyabaturin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

void
	mouse_muve_scrole(t_win *win, t_point delta_mouse)
{
	float	delta;

	delta = 1.5f;
	if (delta_mouse.y > 0 && win->win_rect.w > 1 && win->win_rect.h > 1)
	{
		win->win_rect.w /= delta;
		win->win_rect.h /= delta;
		win->scale /= delta;
	}
	else if (delta_mouse.y < 0 && win->win_rect.w < win->full.w * 4 && win->win_rect.h < win->full.h * 4)
	{
		win->win_rect.w *= delta;
		win->win_rect.h *= delta;
		win->scale *= delta;
	}
}
