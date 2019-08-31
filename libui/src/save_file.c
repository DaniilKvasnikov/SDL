/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 15:01:00 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/31 11:26:11 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

static int
	select_file_type(t_win *win)
{
	const SDL_MessageBoxButtonData buttons[] = {
		{ 0, PNG, "PNG" },
		{ 0, BMP, "BMP" },
		{ 0, JPG, "JPG" }
	};
	const SDL_MessageBoxColorScheme colorScheme = {
		{ /* .colors (.r, .g, .b) */
			/* [SDL_MESSAGEBOX_COLOR_BACKGROUND] */
			{ win->sdl_data->color_back.r, win->sdl_data->color_back.g, win->sdl_data->color_back.b},
			/* [SDL_MESSAGEBOX_COLOR_TEXT] */
			{ 255, 0, 0},
			/* [SDL_MESSAGEBOX_COLOR_BUTTON_BORDER] */
			{ 0, 255, 0},
			/* [SDL_MESSAGEBOX_COLOR_BUTTON_BACKGROUND] */
			{ 0, 0, 255 },
			/* [SDL_MESSAGEBOX_COLOR_BUTTON_SELECTED] */
			{ 255, 255, 255}
		}
	};
	const SDL_MessageBoxData messageboxdata = {
		SDL_MESSAGEBOX_INFORMATION, /* .flags */
		NULL, /* .window */
		"Type of file", /* .title */
		"Select type of file", /* .message */
		SDL_arraysize(buttons), /* .numbuttons */
		buttons, /* .buttons */
		&colorScheme /* .colorScheme */
	};
	int buttonid;
	if (SDL_ShowMessageBox(&messageboxdata, &buttonid) < 0) {
		ft_putstr("error displaying message box\n");
		return (-1);
	}
	return (buttonid);
}

void
	save_file(t_win *win, int type, int num_layer, char *path)
{
	SDL_Texture* target = SDL_GetRenderTarget(win->ren);
	SDL_SetRenderTarget(win->ren, win->layers[num_layer]->texture);
	int width, height;
	SDL_QueryTexture(win->layers[num_layer]->texture, NULL, NULL, &width, &height);
	SDL_Surface* surface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
	SDL_RenderReadPixels(win->ren, NULL, surface->format->format, surface->pixels, surface->pitch);
	type = select_file_type(win);
	if (type == PNG)
		IMG_SavePNG(surface, path);
	else if (type == BMP)
		SDL_SaveBMP(surface, path);
	else if (type == JPG)
		IMG_SaveJPG(surface, path, 100);
	SDL_FreeSurface(surface);
	SDL_SetRenderTarget(win->ren, target);
}
