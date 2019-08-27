/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_render_by_rect.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyabaturin <ilyabaturin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 13:58:45 by ilyabaturin       #+#    #+#             */
/*   Updated: 2019/08/27 14:01:16 by ilyabaturin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	texture_render_by_rect(t_win *win, t_rect rect, SDL_Texture *texture)
{
	SDL_Rect			sdl_rect;
	SDL_RendererFlip	flip;

	if (texture != NULL)
	{
		flip = flip_t_rect(&rect);
		sdl_rect = t_rect_to_sdl_rect(&rect);
		texture_render_rect(win, texture, NULL, &sdl_rect, flip);
		return (1);
	}
	return (0);
}
