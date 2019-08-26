/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 13:24:17 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/26 13:43:23 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	draw_wins(void)
{
	int			win_i;
	t_win		*win;
	int			elem_i;
	t_element	*elem;

	win_i = -1;
	while (g_sdl_data->wins[++win_i] != NULL)
	{
		win = g_sdl_data->wins[win_i];
		SDL_SetRenderDrawColor(win->ren, g_sdl_data->color_back.r, g_sdl_data->color_back.g, g_sdl_data->color_back.b, g_sdl_data->color_back.a);
		SDL_RenderClear(win->ren);
		draw_layers(win);
		elem_i = -1;
		while (win->elements[++elem_i] != NULL)
			;
		while (--elem_i >= 0)
		{
			elem = win->elements[elem_i];
			if (elem->active && elem->draw)
				elem->draw(elem, win);
		}
		if (g_sdl_data->drawing)
			draw_elements(win, g_sdl_data->draw_type, 0);
	}
}
