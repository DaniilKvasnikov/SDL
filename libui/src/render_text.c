/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:11:35 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/14 08:37:01 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	render_text(t_win* win, t_element *elem, char *str)
{
	SDL_Color textColor = { 255, 0, 0 };
	t_mydata	*mydata;
	SDL_Rect	Message_rect;

	if (ft_strlen(str) == 0)
		return(0);
	mydata = (t_mydata *)win->mydata;
	SDL_Surface* message = TTF_RenderText_Blended(mydata->font, str, textColor);
	if( message == NULL )
    {
		printf("TTF_RenderText_Solid: %s\n", TTF_GetError());
		exit(1);
    }
	SDL_Texture* MessageTex = SDL_CreateTextureFromSurface(win->ren, message);
	SDL_FreeSurface(message);
	int w, h;
	SDL_QueryTexture(MessageTex, NULL, NULL, &w, &h);
	Message_rect = (SDL_Rect){
		elem->pos.x + elem->size.x / 2 - w / 2,
		elem->pos.y + elem->size.y / 2 - h / 2,
		w, h};
	SDL_RenderCopy(win->ren, MessageTex, NULL, &Message_rect);
	SDL_DestroyTexture(MessageTex);
	return (0);
}
