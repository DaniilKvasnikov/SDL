/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_text_to_target_tex.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 01:09:44 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/20 15:11:02 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	draw_text_to_target_tex(t_win *win, t_texture *tex, int num_layer, t_rect *rect_win, t_rect *rect_img)
{
	SDL_Rect			sdl_rect_win;
	SDL_Rect			sdl_rect_img;
	SDL_Rect			*ptr_sdl_rect_win;
	SDL_Rect			*ptr_sdl_rect_img;
	SDL_RendererFlip	flip;
	t_rect				rect;

	if (num_layer >= win->layers.count)
		return ;
	ptr_sdl_rect_win = NULL;
	ptr_sdl_rect_img = NULL;
	flip = SDL_FLIP_NONE;
	if (rect_win != NULL)
	{
		rect = (t_rect){rect_win->x, rect_win->y, rect_win->w, rect_win->h};
		flip = flip_t_rect(&rect);
		sdl_rect_win = t_rect_to_sdl_rect(&rect);
		ptr_sdl_rect_win = &sdl_rect_win;
	}
	if (rect_img != NULL)
	{
		rect = (t_rect){rect_img->x, rect_img->y, rect_img->w, rect_img->h};
		flip = flip_t_rect(&rect);
		sdl_rect_img = t_rect_to_sdl_rect(&rect);
		ptr_sdl_rect_img = &sdl_rect_img;
	}
	SDL_SetRenderTarget(win->ren, win->layers.textures[num_layer]);
	SDL_RenderCopyEx(win->ren, tex->tex, ptr_sdl_rect_img, ptr_sdl_rect_win, 0, NULL, flip);
	SDL_SetRenderTarget(win->ren, NULL);
}