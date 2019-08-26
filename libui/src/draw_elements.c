/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 19:27:40 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/26 11:04:44 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	draw_elements(t_win *win, int type, int num_layer)
{
	SDL_RendererFlip flip;
	if (num_layer + 1 >= get_layers_count(win))
		return ;
	if (win->mouse_down.x != win->mouse_muve.x ||
		win->mouse_down.y != win->mouse_muve.y)
	{
		t_rect rect = (t_rect){win->mouse_down.x, win->mouse_down.y, win->mouse_muve.x - win->mouse_down.x, win->mouse_muve.y - win->mouse_down.y};
		flip = flip_t_rect(&rect);
		SDL_Rect sdl_rect = t_rect_to_sdl_rect(&rect);
		SDL_SetRenderDrawColor(win->ren, g_sdl_data->color.r, g_sdl_data->color.g, g_sdl_data->color.b, SDL_ALPHA_OPAQUE);
		if (type == DRAW_ELIPSE_FILLED)
			draw_elipse(win->ren, rect, 1);
		if (type == DRAW_RECT_FILLED)
			SDL_RenderFillRect(win->ren, &sdl_rect);
		SDL_SetRenderDrawColor(win->ren, g_sdl_data->color_border.r, g_sdl_data->color_border.g, g_sdl_data->color_border.b, SDL_ALPHA_OPAQUE);
		if (type == DRAW_LINE)
			ui_draw_line_width(win, win->mouse_down.x, win->mouse_down.y, win->mouse_muve.x, win->mouse_muve.y, g_sdl_data->line_width);
		if (type == DRAW_RECT || type == DRAW_RECT_FILLED)
			SDL_RenderDrawRect(win->ren, &sdl_rect);
		if (type == DRAW_ELIPSE || type == DRAW_ELIPSE_FILLED)
			draw_elipse(win->ren, rect, 0);
		if (type == DRAW_TEXTURE && win->cur_texture)
		{
			texture_render_rect(win, win->cur_texture->tex, NULL, &sdl_rect, flip);
		}
	}
	if (type == DRAW_POINT || type == DRAW_ERASER)
	{
		SDL_SetRenderDrawColor(win->ren, g_sdl_data->color_border.r, g_sdl_data->color_border.g, g_sdl_data->color_border.b, g_sdl_data->color_border.a);
		if (type == DRAW_ERASER)
			SDL_SetRenderDrawColor(win->ren, g_sdl_data->color_back.r, g_sdl_data->color_back.g, g_sdl_data->color_back.b, g_sdl_data->color_back.a);
		SDL_SetRenderTarget(win->ren, win->layers[num_layer]->texture);
		if (win->mouse_down.x != win->mouse_muve.x ||
			win->mouse_down.y != win->mouse_muve.y)
			ui_draw_line_width(win, win->mouse_muve.x, win->mouse_muve.y, win->mouse_down.x, win->mouse_down.y, g_sdl_data->line_width);
		else
			ui_draw_point_width(win, win->mouse_down.x, win->mouse_down.y, g_sdl_data->line_width);
		SDL_SetRenderTarget(win->ren, NULL);
		win->mouse_down = win->mouse_muve;		
	}
}
