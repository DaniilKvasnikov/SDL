/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamerd <gamerd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 19:04:52 by gamerd            #+#    #+#             */
/*   Updated: 2019/07/20 12:28:27 by gamerd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

SDL_Texture* loadTexture(char *path, t_win *win)
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = SDL_LoadBMP(path);
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path, SDL_GetError() );
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(win->ren, loadedSurface);
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}

void
	ft_init_texture(t_win *win, char *path, t_point_int pos)
{
	SDL_Texture	*tex;

	tex = loadTexture(path, win);

	//Clear screen
	SDL_RenderClear( win->ren );

	SDL_Rect dstrect = (SDL_Rect){pos.x - 50, pos.y - 50, 100, 100};
	// SDL_Rect srcrect = (SDL_Rect){0,0, 100, 100};
	//Render texture to screen
	SDL_RenderCopy( win->ren, tex, NULL, &dstrect );

	//Update screen
	SDL_RenderPresent( win->ren );
}