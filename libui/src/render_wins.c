/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:10:34 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/24 14:51:17 by rrhaenys         ###   ########.fr       */
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
		SDL_SetRenderDrawColor(win->ren, mydata->back_color.r, mydata->back_color.g, mydata->back_color.b, SDL_ALPHA_OPAQUE);
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
			draw_elements(win, mydata->draw_type, 2);
		SDL_RenderPresent( win->ren );
	}
}
