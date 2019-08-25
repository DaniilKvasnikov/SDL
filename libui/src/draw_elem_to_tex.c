/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_elem_to_tex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 19:19:36 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 21:20:15 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	draw_elem_to_tex(t_win *win, int num_layer)
{
	if (num_layer + 1 >= get_layers_count(win))
		return ;
	ft_putstr("draw_elem_to_tex\n");
	SDL_SetRenderTarget(win->ren, win->layers[num_layer]->texture);
	t_rect rect = (t_rect){win->mouse_down.x, win->mouse_down.y, win->mouse_muve.x - win->mouse_down.x, win->mouse_muve.y - win->mouse_down.y};
	SDL_Rect sdl_rect = t_rect_to_sdl_rect(&rect);
	flip_t_rect(&rect);
	SDL_SetRenderDrawColor(win->ren, g_sdl_data->color.r, g_sdl_data->color.g, g_sdl_data->color.b, SDL_ALPHA_OPAQUE);
	if (g_sdl_data->draw_type == DRAW_ELIPSE_FILLED)
		draw_elipse(win->ren, rect, 1);
	if (g_sdl_data->draw_type == DRAW_RECT_FILLED)
		SDL_RenderFillRect(win->ren, &sdl_rect);
	SDL_SetRenderDrawColor(win->ren, g_sdl_data->color_border.r, g_sdl_data->color_border.g, g_sdl_data->color_border.b, g_sdl_data->color_border.a);
	if (g_sdl_data->draw_type == DRAW_LINE)
		ui_draw_line_width(win, win->mouse_down.x, win->mouse_down.y, win->mouse_muve.x, win->mouse_muve.y, g_sdl_data->line_width);
	if (g_sdl_data->draw_type == DRAW_RECT || g_sdl_data->draw_type == DRAW_RECT_FILLED)
		SDL_RenderDrawRect(win->ren, &sdl_rect);
	if (g_sdl_data->draw_type == DRAW_ELIPSE || g_sdl_data->draw_type == DRAW_ELIPSE_FILLED)
		draw_elipse(win->ren, rect, 0);
	SDL_SetRenderTarget(win->ren, NULL);
}
