/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:10:34 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/09 16:15:17 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"
#include <SDL2/SDL_ttf.h>

void get_text_and_rect(SDL_Renderer *renderer, int x, int y, char *text,
        TTF_Font *font, SDL_Texture **texture, SDL_Rect *rect) {
    int text_width;
    int text_height;
    SDL_Surface *surface;
    SDL_Color textColor = {255, 255, 255, 0};

    surface = TTF_RenderText_Solid(font, text, textColor);
    *texture = SDL_CreateTextureFromSurface(renderer, surface);
    text_width = surface->w;
    text_height = surface->h;
    SDL_FreeSurface(surface);
    rect->x = x;
    rect->y = y;
    rect->w = text_width;
    rect->h = text_height;
}

void
	draw_text(t_win* win)
{
	SDL_Texture	*texture1;
	SDL_Rect	rect1;
	TTF_Font	*font = TTF_OpenFont("/home/rrhaenys/SDL/fonts/FreeSans.ttf", 24);
	get_text_and_rect(win->ren, 0, 0, "hello", font, &texture1, &rect1);
	SDL_SetRenderDrawColor(win->ren, 0, 0, 0, 0);
	SDL_RenderClear(win->ren);

	/* Use TTF textures. */
	SDL_RenderCopy(win->ren, texture1, NULL, &rect1);

	SDL_RenderPresent(win->ren);
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
