/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_render_full.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyabaturin <ilyabaturin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 15:07:29 by ilyabaturin       #+#    #+#             */
/*   Updated: 2019/08/27 15:15:55 by ilyabaturin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	text_render_full(t_win *win, t_rect rect, char *str, t_ttf ttf, t_color color)
{
	SDL_Rect	Message_rect;

	if (str == NULL || ft_strlen(str) == 0)
		return(0);
	SDL_Surface* message = TTF_RenderText_Blended(ttf.font, str, t_color_to_sdl_color(&color));
	if(message == NULL)
    {
		ft_printf("TTF_RenderText_Blended: %s\n", TTF_GetError());
		exit(1);
    }
	SDL_Texture* MessageTex = SDL_CreateTextureFromSurface(win->ren, message);
	if(MessageTex == NULL)
    {
		ft_printf("SDL_CreateTextureFromSurface: %s\n", TTF_GetError());
		exit(1);
    }
	SDL_FreeSurface(message);
	int w, h;
	SDL_QueryTexture(MessageTex, NULL, NULL, &w, &h);
	Message_rect = (SDL_Rect){
		rect.x + rect.w / 2 - w / 2,
		rect.y + rect.h / 2 - h / 2,
		w, h};
	SDL_RenderCopy(win->ren, MessageTex, NULL, &Message_rect);
	SDL_DestroyTexture(MessageTex);
	return (0);
}
