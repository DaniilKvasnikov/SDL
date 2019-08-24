/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 14:22:36 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/24 14:58:28 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	draw_elements(t_win *win, int type, int num_layer)
{
	t_rect rect = (t_rect){win->lst_mouse.x, win->lst_mouse.y, win->cur_mouse.x - win->lst_mouse.x, win->cur_mouse.y - win->lst_mouse.y};
	SDL_Rect sdl_rect = t_rect_to_sdl_rect(&rect);
	flip_t_rect(&rect);
	SDL_SetRenderDrawColor(win->ren, win->mydata->color.r, win->mydata->color.g, win->mydata->color.b, SDL_ALPHA_OPAQUE);
	if (type == DRAW_ELIPSE_FILLED)
		draw_elipse(win->ren, rect, 1);
	if (type == DRAW_RECT_FILLED)
		SDL_RenderFillRect(win->ren, &sdl_rect);
	SDL_SetRenderDrawColor(win->ren, win->mydata->color_border.r, win->mydata->color_border.g, win->mydata->color_border.b, SDL_ALPHA_OPAQUE);
	if (type == DRAW_LINE)
		SDL_RenderDrawLine(win->ren, win->lst_mouse.x, win->lst_mouse.y, win->cur_mouse.x, win->cur_mouse.y);
	if (type == DRAW_RECT || type == DRAW_RECT_FILLED)
		SDL_RenderDrawRect(win->ren, &sdl_rect);
	if (type == DRAW_ELIPSE || type == DRAW_ELIPSE_FILLED)
		draw_elipse(win->ren, rect, 0);
	if (type == DRAW_POINT || type == DRAW_ERASER)
	{
		if (type == DRAW_ERASER)
			SDL_SetRenderDrawColor(win->ren, win->mydata->back_color.r, win->mydata->back_color.g, win->mydata->back_color.b, SDL_ALPHA_OPAQUE);
		SDL_SetRenderTarget(win->ren, win->layers.textures[num_layer]);
		SDL_RenderDrawLine(win->ren, win->cur_mouse.x, win->cur_mouse.y, win->lst_mouse.x, win->lst_mouse.y);
		SDL_SetRenderTarget(win->ren, NULL);
		win->lst_mouse = win->cur_mouse;		
	}
}
