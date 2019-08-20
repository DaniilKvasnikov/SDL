/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:05:43 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/20 15:06:01 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	texture_render(t_win *win, t_element *elem, SDL_Texture *texture)
{
	SDL_Rect			sdl_rect;
	SDL_RendererFlip	flip;
	t_rect				rect;

	if (texture != NULL)
	{
		rect = (t_rect){elem->pos.x, elem->pos.y, elem->size.x, elem->size.y};
		flip = flip_t_rect(&rect);
		sdl_rect = t_rect_to_sdl_rect(&rect);
		texture_render_rect(win, texture, NULL, &sdl_rect, flip);
	}
	return (0);
}
