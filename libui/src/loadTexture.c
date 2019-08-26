/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadTexture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 14:30:42 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/26 13:33:52 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

SDL_Surface* loadSurface(char *path, t_win *win)
{
	//Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	SDL_Surface	*gScreenSurface;
	if( !( IMG_Init( imgFlags ) & imgFlags ) )
	{
		printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
		exit(1);
	}
	else
	{
		gScreenSurface = SDL_GetWindowSurface(win->win);
	}
    //The final optimized image
    SDL_Surface* optimizedSurface = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path);
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError() );
    }
    else
    {
        //Convert surface to screen format
        optimizedSurface = SDL_ConvertSurface( loadedSurface, gScreenSurface->format, 0 );
        if( optimizedSurface == NULL )
        {
            printf( "Unable to optimize image %s! SDL Error: %s\n", path, SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    return optimizedSurface;
}

SDL_Texture*
	loadTexture(t_win *win, char *path, int type)
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
