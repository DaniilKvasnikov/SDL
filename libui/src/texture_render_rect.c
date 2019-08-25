/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_render_rect.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 14:15:36 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 14:15:41 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	texture_render_rect(t_win *win, SDL_Texture *texture, SDL_Rect *dust, SDL_Rect *src, SDL_RendererFlip flip)
{
	if (texture != NULL)
		SDL_RenderCopyEx(win->ren, texture, dust, src, 0, NULL, flip);
	return (0);
}
