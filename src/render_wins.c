/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:10:34 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/12 09:55:46 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	draw_text(t_win* win, SDL_Rect *Message_rect, char *str)
{
	SDL_Texture	*texture1;
	SDL_Rect	rect1;
	SDL_Color textColor = { 255, 0, 0 };
	t_mydata	*mydata;

	mydata = (t_mydata *)win->mydata;
	SDL_Surface* message = TTF_RenderText_Solid(mydata->font, str, textColor);
	if( message == NULL )
    {
		printf("TTF_RenderText_Solid: %s\n", TTF_GetError());
		exit(1);
    }
	SDL_Texture* MessageTex = SDL_CreateTextureFromSurface(win->ren, message);
	SDL_RenderCopy(win->ren, MessageTex, NULL, Message_rect);
}

void
	render_wins(t_mydata *mydata)
{
	int			i;
	int			j;
	SDL_Rect	rect;
	
	i = -1;
	while (++i < mydata->win_count)
	{
		SDL_RenderClear( mydata->wins[i]->ren );
		j = -1;
		while (++j < mydata->wins[i]->element_count)
		{
			rect = (SDL_Rect){mydata->wins[i]->elements[j]->pos.x, mydata->wins[i]->elements[j]->pos.y,
				mydata->wins[i]->elements[j]->size.x, mydata->wins[i]->elements[j]->size.y};
			if (mydata->wins[i]->elements[j]->num_tex == 0)
				SDL_RenderCopy( mydata->wins[i]->ren, mydata->wins[i]->elements[j]->texture1, NULL, &rect );
			else if (mydata->wins[i]->elements[j]->num_tex == 1)
				SDL_RenderCopy( mydata->wins[i]->ren, mydata->wins[i]->elements[j]->texture2, NULL, &rect );
			if (mydata->wins[i]->elements[j]->str != NULL)
				draw_text(mydata->wins[i], &rect, mydata->wins[i]->elements[j]->str);
		}
		SDL_RenderPresent( mydata->wins[i]->ren );
	}
}
