/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 16:50:32 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 17:04:16 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	render_text(t_element *elem, t_win *win)
{
	SDL_Rect	Message_rect;

	if (elem->str == NULL || elem->ttf == NULL || ft_strlen(elem->str) == 0)
		return(0);
	SDL_Surface* message = TTF_RenderText_Blended(elem->ttf->font, elem->str, t_color_to_sdl_color(elem->color));
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
		elem->rect.x + elem->rect.w / 2 - w / 2,
		elem->rect.y + elem->rect.h / 2 - h / 2,
		w, h};
	SDL_RenderCopy(win->ren, MessageTex, NULL, &Message_rect);
	SDL_DestroyTexture(MessageTex);
	return (0);
}
