/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadTexture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyabaturin <ilyabaturin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 14:30:42 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/28 09:22:37 by ilyabaturin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

SDL_Texture*
	loadTexture(t_win *win, char *path, int type)
{
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface;
	ft_printf("type %d\n", type);
	if (type == BMP)
		loadedSurface = SDL_LoadBMP(path);
	else if (type == PNG)
	{
		IMG_Init(IMG_INIT_PNG);
		loadedSurface = IMG_Load(path);
	}
	else if (type == JPG)
	{
		IMG_Init(IMG_INIT_JPG);
		loadedSurface = IMG_Load(path);
	}
	else
	{
		ft_printf("%d type dont found\n");
		exit (0);
	}
	
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
