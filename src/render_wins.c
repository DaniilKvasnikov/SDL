/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:10:34 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/18 01:07:39 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	render_wins(t_mydata *mydata)
{
	int			i;
	int			j;
	
	i = -1;
	while (++i < mydata->win_count)
	{
		SDL_RenderClear( mydata->wins[i]->ren );
		texture_render_rect(mydata->wins[i], mydata->wins[i]->texTarget, NULL, NULL);
		j = -1;
		while (++j < mydata->wins[i]->element_count)
			if (mydata->wins[i]->elements[j]->draw != NULL)
				mydata->wins[i]->elements[j]->draw(mydata->wins[i], mydata->wins[i]->elements[j]);
		SDL_RenderPresent( mydata->wins[i]->ren );
	}
}
