/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:10:34 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/22 12:43:52 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	render_wins(t_mydata *mydata)
{
	int			i;
	int			j;
	SDL_Rect	rect;
	t_win		*win;
	
	i = -1;
	while (++i < mydata->win_count)
	{
		win = mydata->wins[i];
		SDL_SetRenderDrawColor(win->ren, 0, 255, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear( win->ren );
		j = -1;
		while (++j < win->layers.count)
			texture_render_rect(win, win->layers.textures[j], NULL, NULL, SDL_FLIP_NONE);
		j = -1;
		while (++j < win->element_count)
			if (win->elements[j]->draw != NULL)
				win->elements[j]->draw(win, win->elements[j]);
		SDL_SetRenderDrawColor(win->ren, 255, 255, 255, SDL_ALPHA_OPAQUE);
		if (win->cur_mouse.x != win->lst_mouse.x ||
			win->cur_mouse.y != win->lst_mouse.y)
		{
			SDL_RenderDrawLine(win->ren, win->lst_mouse.x, win->lst_mouse.y, win->cur_mouse.x, win->cur_mouse.y);
			t_rect rect = (t_rect){win->lst_mouse.x, win->lst_mouse.y, win->cur_mouse.x - win->lst_mouse.x, win->cur_mouse.y - win->lst_mouse.y};
			SDL_Rect sdl_rect = t_rect_to_sdl_rect(&rect);
			SDL_RenderDrawRect(win->ren, &sdl_rect);
			flip_t_rect(&rect);
	SDL_SetRenderDrawColor(win->ren, ((t_mydata *)win->mydata)->color.r, ((t_mydata *)win->mydata)->color.g, ((t_mydata *)win->mydata)->color.b, SDL_ALPHA_OPAQUE);
			draw_elipse(win->ren, rect, 1);
			SDL_SetRenderDrawColor(win->ren, 0, 0, 255, SDL_ALPHA_OPAQUE);
			draw_elipse(win->ren, rect, 0);
		}
		SDL_RenderPresent( win->ren );
	}
}
