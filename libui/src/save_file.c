/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 15:01:00 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/26 15:16:42 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	save_file(t_win *win, int type, int num_layer, char *path)
{
	SDL_Texture* target = SDL_GetRenderTarget(win->ren);
    SDL_SetRenderTarget(win->ren, win->layers[num_layer]->texture);
    int width, height;
    SDL_QueryTexture(win->layers[num_layer]->texture, NULL, NULL, &width, &height);
    SDL_Surface* surface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
    SDL_RenderReadPixels(win->ren, NULL, surface->format->format, surface->pixels, surface->pitch);
	if (type == PNG)
	    IMG_SavePNG(surface, path);
	else if (type == BMP)
		SDL_SaveBMP(surface, path);
	else if (type == JPG)
		IMG_SaveJPG(surface, path, 100);
    SDL_FreeSurface(surface);
    SDL_SetRenderTarget(win->ren, target);
}
