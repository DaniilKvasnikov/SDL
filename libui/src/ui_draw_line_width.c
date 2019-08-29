/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_draw_line_width.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 21:13:24 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 21:20:40 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	ui_draw_line_width(t_win *win, int x1, int y1, int x2, int y2, int width)
{
	int		w;
	int		dx;

	w = 0;
	while (w++ < width * 2)
    {
        dx = width - w; // horizontal offset
        SDL_RenderDrawLine(win->ren, x1 + dx, y1 + dx, x2 + dx, y2 + dx);
    }

}
