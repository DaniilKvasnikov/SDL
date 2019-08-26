/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_layer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 13:47:09 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/26 13:47:33 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	clear_layer(t_win *win, int num_layer)
{
	SDL_SetRenderTarget(win->ren, win->layers[num_layer]->texture);
	SDL_SetRenderDrawColor(win->ren, g_sdl_data->color_back.r, g_sdl_data->color_back.g, g_sdl_data->color_back.b, g_sdl_data->color_back.a);
	SDL_RenderClear(win->ren);
	SDL_SetRenderTarget(win->ren, NULL);
}
