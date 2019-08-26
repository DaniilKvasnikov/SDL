/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_elem_to_tex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyabaturin <ilyabaturin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 19:19:36 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/26 18:22:55 by ilyabaturin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	draw_elem_to_tex(t_win *win, int num_layer)
{
	t_point	mouse_down = diff_t_point(win->mouse_down, (t_point){win->win_rect.x, win->win_rect.y});
	t_point	mouse_muve = diff_t_point(win->mouse_muve, (t_point){win->win_rect.x, win->win_rect.y});
	SDL_RendererFlip flip;
	ft_putstr("draw_elem_to_tex\n");
	SDL_SetRenderTarget(win->ren, win->layers[num_layer]->texture);
	t_rect rect = (t_rect){mouse_down.x, mouse_down.y, mouse_muve.x - mouse_down.x, mouse_muve.y - mouse_down.y};
	flip = flip_t_rect(&rect);
	SDL_Rect sdl_rect = t_rect_to_sdl_rect(&rect);
	SDL_SetRenderDrawColor(win->ren, g_sdl_data->color.r, g_sdl_data->color.g, g_sdl_data->color.b, SDL_ALPHA_OPAQUE);
	if (g_sdl_data->draw_type == DRAW_ELIPSE_FILLED)
		draw_elipse(win->ren, rect, 1);
	if (g_sdl_data->draw_type == DRAW_RECT_FILLED)
		SDL_RenderFillRect(win->ren, &sdl_rect);
	SDL_SetRenderDrawColor(win->ren, g_sdl_data->color_border.r, g_sdl_data->color_border.g, g_sdl_data->color_border.b, g_sdl_data->color_border.a);
	if (g_sdl_data->draw_type == DRAW_LINE)
		ui_draw_line_width(win, mouse_down.x, mouse_down.y, mouse_muve.x, mouse_muve.y, g_sdl_data->line_width);
	if (g_sdl_data->draw_type == DRAW_RECT || g_sdl_data->draw_type == DRAW_RECT_FILLED)
		SDL_RenderDrawRect(win->ren, &sdl_rect);
	if (g_sdl_data->draw_type == DRAW_ELIPSE || g_sdl_data->draw_type == DRAW_ELIPSE_FILLED)
		draw_elipse(win->ren, rect, 0);
	if (g_sdl_data->draw_type == DRAW_TEXTURE && win->cur_texture)
		texture_render_rect(win, win->cur_texture->tex, NULL, &sdl_rect, flip);
	SDL_SetRenderTarget(win->ren, NULL);
}
