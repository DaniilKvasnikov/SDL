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
	int w;
	int h;
	int dx;
	int dy;

	w = 0;
    while (w++ < width * 2)
    {
		h = 0;
        while (h++ < width * 2)
        {
            dx = width - w;
            dy = width - h; 
            if ((dx*dx + dy*dy) <= (width * width))
            {
                SDL_RenderDrawPoint(win->ren, x1 + dx, y1 + dy);
            }
        }
    }
}
