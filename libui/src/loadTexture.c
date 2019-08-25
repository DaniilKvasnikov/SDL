/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadTexture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 14:30:42 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 14:32:16 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

SDL_Texture*
	loadTexture(t_win *win, char *path)
{
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = SDL_LoadBMP(path);
	if(loadedSurface == NULL)
	{
		ft_printf( "Unable to load image %s! SDL_image Error: %s\n", path, SDL_GetError() );
		exit (1);
	}
	else
	{
		newTexture = SDL_CreateTextureFromSurface(win->ren, loadedSurface);
		if( newTexture == NULL )
		{
			ft_printf( "Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError());
			exit (1);
		}
		SDL_FreeSurface( loadedSurface );
	}
	return newTexture;
}
