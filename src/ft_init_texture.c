/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamerd <gamerd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 19:04:52 by gamerd            #+#    #+#             */
/*   Updated: 2019/07/19 19:18:01 by gamerd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	ft_init_texture(t_win *win, char *path)
{
	SDL_Surface	*bmp;
	SDL_Texture	*tex;

	bmp = SDL_LoadBMP(path);
	if (bmp == NULL)
	{
		fprintf(stderr, "SDL_LoadBMP Error: %s\n", SDL_GetError());
		return ;
	}
	tex = SDL_CreateTextureFromSurface(win->ren, bmp);
	if (tex == NULL)
	{
		fprintf(stderr, "SDL_CreateTextureFromSurface Error: %s\n", SDL_GetError());
		return ;
	}
	SDL_FreeSurface(bmp);
}