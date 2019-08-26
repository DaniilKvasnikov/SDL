/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_layers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyabaturin <ilyabaturin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 20:32:59 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/26 17:57:56 by ilyabaturin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	draw_layers(t_win *win)
{
	int			i;
	SDL_Rect	sdl_rect;

	sdl_rect = t_rect_to_sdl_rect(&win->win_rect);
	i = -1;
	while (win->layers[++i] != NULL)
		texture_render_rect(win, win->layers[i]->texture, NULL, &sdl_rect, SDL_FLIP_NONE);
}
