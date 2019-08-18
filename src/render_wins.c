/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:10:34 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/18 16:16:12 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

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
		while (++j < mydata->wins[i]->layers.count)
			texture_render_rect(mydata->wins[i], mydata->wins[i]->layers.textures[j], NULL, NULL);
		j = -1;
		while (++j < mydata->wins[i]->element_count)
			if (mydata->wins[i]->elements[j]->draw != NULL)
				mydata->wins[i]->elements[j]->draw(mydata->wins[i], mydata->wins[i]->elements[j]);
		if (mydata->wins[i]->active_element && mydata->wins[i]->tex_active_elem)
		{
			ft_putstr("tex_active_elem\n");
			rect = (SDL_Rect){mydata->wins[i]->active_element->pos.x, mydata->wins[i]->active_element->pos.y, mydata->wins[i]->active_element->size.x, mydata->wins[i]->active_element->size.y};
			texture_render_rect(mydata->wins[i], mydata->wins[i]->tex_active_elem, NULL, &rect);
		}
		SDL_RenderPresent( mydata->wins[i]->ren );
	}
}
