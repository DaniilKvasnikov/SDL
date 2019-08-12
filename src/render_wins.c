/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:10:34 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/12 17:12:34 by rrhaenys         ###   ########.fr       */
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
		while (++j < mydata->wins[i]->element_count)
		{
			if (mydata->wins[i]->elements[j]->num_tex == 0)
				texture_render(mydata->wins[i], mydata->wins[i]->elements[j], mydata->wins[i]->elements[j]->texture1);
			else if (mydata->wins[i]->elements[j]->num_tex == 1)
				texture_render(mydata->wins[i], mydata->wins[i]->elements[j], mydata->wins[i]->elements[j]->texture2);
			if (mydata->wins[i]->elements[j]->str != NULL)
				render_text(mydata->wins[i], mydata->wins[i]->elements[j], mydata->wins[i]->elements[j]->str);
		}
		SDL_RenderPresent( mydata->wins[i]->ren );
	}
}
