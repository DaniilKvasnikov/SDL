/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_screenshot_bmp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 03:49:09 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/17 04:04:22 by rrhaenys         ###   ########.fr       */
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
//		std::cerr << "Failed to create info surface from window in saveScreenshotBMP(string), SDL_GetError() - " << SDL_GetError() << "\n";
	} else {
		unsigned char * pixels = (unsigned char *)malloc(sizeof(unsigned char) * infoSurface->w * infoSurface->h * infoSurface->format->BytesPerPixel);
		if (pixels == 0) {
			//std::cerr << "Unable to allocate memory for screenshot pixel data buffer!\n";
			return 0;
		} else {
			if (SDL_RenderReadPixels(SDLRenderer, &infoSurface->clip_rect, infoSurface->format->format, pixels, infoSurface->w * infoSurface->format->BytesPerPixel) != 0) {
				//std::cerr << "Failed to read pixel data from SDL_Renderer object. SDL_GetError() - " << SDL_GetError() << "\n";
				free(pixels);
				return 0;
			} else {
				saveSurface = SDL_CreateRGBSurfaceFrom(pixels, infoSurface->w, infoSurface->h, infoSurface->format->BitsPerPixel, infoSurface->w * infoSurface->format->BytesPerPixel, infoSurface->format->Rmask, infoSurface->format->Gmask, infoSurface->format->Bmask, infoSurface->format->Amask);
				if (saveSurface == NULL) {
					//std::cerr << "Couldn't create SDL_Surface from renderer pixel data. SDL_GetError() - " << SDL_GetError() << "\n";
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