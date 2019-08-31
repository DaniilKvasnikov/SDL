/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 13:24:17 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/31 11:07:08 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	draw_wins(t_sdl_data *data)
{
	int			win_i;
	t_win		*win;
	int			elem_i;
	t_element	*elem;

	win_i = -1;
	while (data->wins[++win_i] != NULL)
	{
		win = data->wins[win_i];
		SDL_SetRenderDrawColor(win->ren, data->color_back.r, data->color_back.g, data->color_back.b, data->color_back.a);
		SDL_SetRenderDrawColor(win->ren, 255, 0, 0, 255);
		SDL_RenderClear(win->ren);
		draw_layers(win);
		elem_i = -1;
		while (win->elements[++elem_i] != NULL)
			;
		while (--elem_i >= 0)
		{
			elem = win->elements[elem_i];
			if (*elem->active && elem->draw)
				elem->draw(elem, win);
		}
		if (data->drawing)
			draw_elements(win, data->draw_type, 0);
	}
}
