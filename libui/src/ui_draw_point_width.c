/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_draw_point_width.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 21:50:19 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 21:50:39 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	ui_draw_point_width(t_win *win, int x1, int y1, int width)
{
	SDL_RenderDrawPoint(win->ren, x1, y1);
}
