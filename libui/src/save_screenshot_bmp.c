/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_screenshot_bmp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 03:49:09 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/17 04:15:05 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"
int
	save_screenshot_bmp(char *filepath, SDL_Window* SDLWindow, SDL_Renderer* SDLRenderer)
{
	SDL_Surface* saveSurface = NULL;
	SDL_Surface* infoSurface = NULL;
	infoSurface = SDL_GetWindowSurface(SDLWindow);
	if (infoSurface == NULL) {
		ft_printf("SDL_GetError() - %s\n", SDL_GetError());
	} else {
		unsigned char * pixels = (unsigned char *)malloc(sizeof(unsigned char) * infoSurface->w * infoSurface->h * infoSurface->format->BytesPerPixel);
		if (pixels == 0) {
			ft_putstr("Memory error\n");
			return 0;
		} else {
			if (SDL_RenderReadPixels(SDLRenderer, &infoSurface->clip_rect, infoSurface->format->format, pixels, infoSurface->w * infoSurface->format->BytesPerPixel) != 0) {
				ft_printf("SDL_GetError() - %s\n", SDL_GetError());
				free(pixels);
				return 0;
			} else {
				saveSurface = SDL_CreateRGBSurfaceFrom(pixels, infoSurface->w, infoSurface->h, infoSurface->format->BitsPerPixel, infoSurface->w * infoSurface->format->BytesPerPixel, infoSurface->format->Rmask, infoSurface->format->Gmask, infoSurface->format->Bmask, infoSurface->format->Amask);
				if (saveSurface == NULL) {
					ft_printf("SDL_GetError() - %s\n", SDL_GetError());
					free(pixels);
					return 0;
				}
				SDL_SaveBMP(saveSurface, filepath);
				SDL_FreeSurface(saveSurface);
				saveSurface = NULL;
			}
			free(pixels);
		}
		SDL_FreeSurface(infoSurface);
		infoSurface = NULL;
	}
	return 1;
}