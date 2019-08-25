/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_layers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 20:32:59 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 20:34:31 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	draw_layers(t_win *win)
{
	int i;

	i = -1;
	while (win->layers[++i] != NULL)
		texture_render_rect(win, win->layers[i]->texture, NULL, NULL, SDL_FLIP_NONE);
}
