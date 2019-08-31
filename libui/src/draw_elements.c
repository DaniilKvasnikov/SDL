/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 19:27:40 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/31 11:06:05 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

static t_point
	recalc(t_point *old, t_rect *rect, float delta)
{
	return ((t_point){
		(old->x - rect->x) / delta,
		(old->y - rect->y) / delta
	});
}

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
		SDL_SetRenderDrawColor(win->ren, win->sdl_data->color.r, win->sdl_data->color.g, win->sdl_data->color.b, SDL_ALPHA_OPAQUE);
		if (type == DRAW_ELIPSE_FILLED)
			draw_elipse(win->ren, rect, 1);
		if (type == DRAW_RECT_FILLED)
			SDL_RenderFillRect(win->ren, &sdl_rect);
		SDL_SetRenderDrawColor(win->ren, win->sdl_data->color_border.r, win->sdl_data->color_border.g, win->sdl_data->color_border.b, SDL_ALPHA_OPAQUE);
		if (type == DRAW_LINE)
			ui_draw_line_width(win, win->mouse_down.x, win->mouse_down.y, win->mouse_muve.x, win->mouse_muve.y, win->sdl_data->line_width);
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
		t_point	mouse_down = recalc(&win->mouse_down, &win->win_rect, win->scale);
		t_point	mouse_muve = recalc(&win->mouse_muve, &win->win_rect, win->scale);
		SDL_SetRenderDrawColor(win->ren, win->sdl_data->color_border.r, win->sdl_data->color_border.g, win->sdl_data->color_border.b, win->sdl_data->color_border.a);
		if (type == DRAW_ERASER)
			SDL_SetRenderDrawColor(win->ren, win->sdl_data->color_back.r, win->sdl_data->color_back.g, win->sdl_data->color_back.b, win->sdl_data->color_back.a);
		SDL_SetRenderTarget(win->ren, win->layers[num_layer]->texture);
		if (mouse_down.x != mouse_muve.x ||
			mouse_down.y != mouse_muve.y)
			ui_draw_line_width(win, mouse_muve.x, mouse_muve.y, mouse_down.x, mouse_down.y, win->sdl_data->line_width);
		else
			ui_draw_point_width(win, mouse_down.x, mouse_down.y, win->sdl_data->line_width);
		SDL_SetRenderTarget(win->ren, NULL);
		win->mouse_down = win->mouse_muve;
	}
}
