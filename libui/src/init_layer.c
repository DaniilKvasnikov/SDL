/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_layer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 20:05:18 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/31 11:20:02 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_layer
	*init_layer(t_win *win, char *name)
{
	t_layer	*layer;

	layer = (t_layer *)ui_checkmalloc(malloc(sizeof(t_layer)), "layer", __LINE__, __FILE__);
	layer->name = name;
	layer->texture = SDL_CreateTexture(win->ren, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, win->full.w, win->full.h);
	ui_checkmalloc(layer->texture, "texture", __LINE__, __FILE__);
	SDL_SetRenderTarget(win->ren, layer->texture);
	SDL_SetRenderDrawColor(win->ren, win->sdl_data->color_back.r, win->sdl_data->color_back.g, win->sdl_data->color_back.b, win->sdl_data->color_back.a);
	SDL_RenderClear(win->ren);
	SDL_SetRenderTarget(win->ren, NULL);
	return (layer);
}
