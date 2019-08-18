/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:05:43 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/18 01:08:08 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	texture_render(t_win *win, t_element *elem, SDL_Texture *texture)
{
	SDL_Rect	rect;

	if (texture != NULL)
	{
		rect = (SDL_Rect){elem->pos.x, elem->pos.y, elem->size.x, elem->size.y};
		texture_render_rect(win, texture, NULL, &rect);
	}
	return (0);
}
