/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 13:13:40 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/31 13:15:03 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	check_texture(t_win *win, char *path, int type)
{
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface;
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
		return (0);
	}
	
	if(loadedSurface == NULL)
	{
		ft_printf( "Unable to load image %s! SDL_image Error: %s\n", path, SDL_GetError() );
		return (0);
	}
	SDL_FreeSurface( loadedSurface );
	return (1);
}
