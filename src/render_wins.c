/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:10:34 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/11 18:08:00 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination )
{
    //Make a temporary rectangle to hold the offsets
    SDL_Rect offset;
    
    //Give the offsets to the rectangle
    offset.x = x;
    offset.y = y;
	//Blit the surface
    SDL_BlitSurface( source, NULL, destination, &offset );
}

void
	draw_text(t_win* win)
{
	SDL_Texture	*texture1;
	SDL_Rect	rect1;
	SDL_Surface *message = NULL;
	SDL_Color textColor = { 255, 255, 255 };
	t_mydata	*mydata;

	mydata = (t_mydata *)win->mydata;
	message = TTF_RenderText_Solid( mydata->font, "My text", textColor );
	if( message == NULL )
    {
		printf("TTF_RenderText_Solid: %s\n", TTF_GetError());
		exit(1);
    }
	apply_surface( 0, 150, message, win->screen );
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
		draw_text(mydata->wins[i]);
		// SDL_RenderClear( mydata->wins[i]->ren );
		// j = -1;
		// while (++j < mydata->wins[i]->buttons_count)
		// {
		// 	rect = (SDL_Rect){mydata->wins[i]->buttons[j]->pos.x, mydata->wins[i]->buttons[j]->pos.y,
		// 		mydata->wins[i]->buttons[j]->size.x, mydata->wins[i]->buttons[j]->size.y};
		// 	SDL_RenderCopy( mydata->wins[i]->ren, mydata->wins[i]->buttons[j]->texture, NULL, &rect );
		// }
		// SDL_RenderPresent( mydata->wins[i]->ren );
	}
}
