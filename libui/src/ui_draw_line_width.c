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
	SDL_RenderDrawLine(win->ren, x1, y1, x2, y2);
}
