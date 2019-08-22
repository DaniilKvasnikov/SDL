/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_pairs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 11:15:21 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/22 11:42:17 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	ft_update_pairs(t_mydata *mydata)
{
	int			i;
	int			j;
	SDL_Rect	rect;
	t_win		*win;
	
	i = -1;
	while (++i < mydata->win_count)
	{
		win = mydata->wins[i];
		j = -1;
		while (++j < win->pairs_int.count)
			ft_update_pair(&win->pairs_int.pairs[j]);
	}
}
