/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:10:34 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/06 19:41:48 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	render_wins(t_mydata *mydata)
{
	int	i;
	int	j;

	i = -1;
	while (++i < mydata->win_count)
	{
		SDL_RenderClear( mydata->wins[i]->ren );
		j = -1;
		while (++j < mydata->wins[i]->buttons_count)
		{
			SDL_RenderCopy( mydata->wins[i]->ren, mydata->wins[i]->buttons[j]->texture, NULL, &mydata->wins[i]->buttons[j]->rect );
		}
		SDL_RenderPresent( mydata->wins[i]->ren );
	}
}
