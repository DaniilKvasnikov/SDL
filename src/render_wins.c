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
		while (++j < mydata->wins[i]->buttons_count)
		{
			rect = (SDL_Rect){mydata->wins[i]->buttons[j]->pos.x, mydata->wins[i]->buttons[j]->pos.y,
				mydata->wins[i]->buttons[j]->size.x, mydata->wins[i]->buttons[j]->size.y};
			SDL_RenderCopy( mydata->wins[i]->ren, mydata->wins[i]->buttons[j]->texture, NULL, &rect );
		}
		SDL_RenderPresent( mydata->wins[i]->ren );
	}
}
