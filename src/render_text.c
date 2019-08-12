/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:11:35 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/12 17:11:20 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	render_text(t_win* win, t_element *elem, char *str)
{
	SDL_Texture	*texture1;
	SDL_Rect	rect1;
	SDL_Color textColor = { 255, 0, 0 };
	t_mydata	*mydata;
	SDL_Rect	Message_rect;

	Message_rect = (SDL_Rect){elem->pos.x, elem->pos.y, elem->size.x, elem->size.y};
	mydata = (t_mydata *)win->mydata;
	SDL_Surface* message = TTF_RenderText_Solid(mydata->font, str, textColor);
	if( message == NULL )
    {
		printf("TTF_RenderText_Solid: %s\n", TTF_GetError());
		exit(1);
    }
	SDL_Texture* MessageTex = SDL_CreateTextureFromSurface(win->ren, message);
	SDL_RenderCopy(win->ren, MessageTex, NULL, &Message_rect);
	return (0);
}
