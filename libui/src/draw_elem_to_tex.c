/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_elem_to_tex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyabaturin <ilyabaturin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 19:19:36 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/09/04 09:08:37 by ilyabaturin      ###   ########.fr       */
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
	draw_elem_to_tex(t_win *win, int num_layer)
{
	t_point	mouse_down = recalc(&win->mouse_down, &win->win_rect, win->scale);
	t_point	mouse_muve = recalc(&win->mouse_muve, &win->win_rect, win->scale);
	SDL_RendererFlip flip;
	ft_putstr("draw_elem_to_tex\n");
	SDL_SetRenderTarget(win->ren, win->layers[num_layer]->texture);
	t_rect rect = (t_rect){mouse_down.x, mouse_down.y, mouse_muve.x - mouse_down.x, mouse_muve.y - mouse_down.y};
	flip = flip_t_rect(&rect);
	SDL_Rect sdl_rect = t_rect_to_sdl_rect(&rect);
	SDL_SetRenderDrawColor(win->ren, win->sdl_data->color.r, win->sdl_data->color.g, win->sdl_data->color.b, SDL_ALPHA_OPAQUE);
	if (win->sdl_data->draw_type == DRAW_ELIPSE_FILLED)
		draw_elipse(win->ren, rect, 1);
	if (win->sdl_data->draw_type == DRAW_RECT_FILLED)
		SDL_RenderFillRect(win->ren, &sdl_rect);
	SDL_SetRenderDrawColor(win->ren, win->sdl_data->color_border.r, win->sdl_data->color_border.g, win->sdl_data->color_border.b, win->sdl_data->color_border.a);
	if (win->sdl_data->draw_type == DRAW_LINE)
		ui_draw_line_width(win, mouse_down.x, mouse_down.y, mouse_muve.x, mouse_muve.y, win->sdl_data->line_width);
	if (win->sdl_data->draw_type == DRAW_RECT || win->sdl_data->draw_type == DRAW_RECT_FILLED)
		SDL_RenderDrawRect(win->ren, &sdl_rect);
	if (win->sdl_data->draw_type == DRAW_ELIPSE || win->sdl_data->draw_type == DRAW_ELIPSE_FILLED)
		draw_elipse(win->ren, rect, 0);
	if (win->sdl_data->draw_type == DRAW_TEXTURE && win->cur_texture)
		texture_render_rect(win, win->cur_texture->tex, NULL, &sdl_rect, flip);
	SDL_SetRenderTarget(win->ren, NULL);
}
