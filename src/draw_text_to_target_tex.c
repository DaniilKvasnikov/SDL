/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_text_to_target_tex.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 01:09:44 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/18 01:31:19 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	draw_text_to_target_tex(t_win *win, t_texture *tex, t_rect *rect_win, t_rect *rect_img)
{
	SDL_Rect sdl_rect_win;
	SDL_Rect sdl_rect_img;
	SDL_Rect *ptr_sdl_rect_win;
	SDL_Rect *ptr_sdl_rect_img;

	ptr_sdl_rect_win = NULL;
	ptr_sdl_rect_img = NULL;
	if (rect_win != NULL)
	{
		sdl_rect_win = (SDL_Rect){rect_win->x, rect_win->y, rect_win->w, rect_win->h};
		ptr_sdl_rect_win = &sdl_rect_win;
	}
	if (rect_img != NULL)
	{
		sdl_rect_img = (SDL_Rect){rect_img->x, rect_img->y, rect_img->w, rect_img->h};
		ptr_sdl_rect_img = &sdl_rect_img;
	}
	SDL_SetRenderTarget(win->ren, win->texTarget);
	SDL_RenderCopy(win->ren, tex->tex, ptr_sdl_rect_img, ptr_sdl_rect_win);
	SDL_SetRenderTarget(win->ren, NULL);
}