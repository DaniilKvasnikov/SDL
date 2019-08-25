/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flip_t_rect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 14:13:26 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 14:13:29 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_sdl.h"

SDL_RendererFlip
	flip_t_rect(t_rect *rect)
{
	SDL_RendererFlip flip = SDL_FLIP_NONE;
	if (rect->w < 0 && rect->h < 0)
		flip = SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL;
	else if (rect->w < 0)
		flip = SDL_FLIP_HORIZONTAL;
	else if (rect->h < 0)
		flip = SDL_FLIP_VERTICAL;
	if (rect->w < 0)
	{
		rect->x += rect->w;
		rect->w = -rect->w;
	}
	if (rect->h < 0)
	{
		rect->y += rect->h;
		rect->h = -rect->h;
	}
	return (flip);
}
