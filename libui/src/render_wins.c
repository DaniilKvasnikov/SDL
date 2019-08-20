/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:10:34 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/20 13:17:27 by rrhaenys         ###   ########.fr       */
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
		SDL_RenderClear( win->ren );
		j = -1;
		while (++j < win->layers.count)
			texture_render_rect(win, win->layers.textures[j], NULL, NULL, SDL_FLIP_NONE);
		j = -1;
		while (++j < win->element_count)
			if (win->elements[j]->draw != NULL)
				win->elements[j]->draw(win, win->elements[j]);
		if (win->cur_mouse.x != win->lst_mouse.x ||
			win->cur_mouse.y != win->lst_mouse.y)
		SDL_RenderDrawLine(win->ren, win->lst_mouse.x, win->lst_mouse.y, win->cur_mouse.x, win->cur_mouse.y);
		SDL_Rect sdl_rect = (SDL_Rect){win->lst_mouse.x, win->lst_mouse.y, win->cur_mouse.x - win->lst_mouse.x, win->cur_mouse.y - win->lst_mouse.y};
		SDL_RenderDrawRect(win->ren, &sdl_rect);
		SDL_RenderPresent( win->ren );
	}
}
