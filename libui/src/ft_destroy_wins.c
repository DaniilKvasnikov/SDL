/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_wins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 13:10:56 by gamerd            #+#    #+#             */
/*   Updated: 2019/08/13 10:45:10 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	ft_destroy_win(t_win *win)
{
	SDL_DestroyRenderer(win->ren);
	SDL_DestroyWindow(win->win);
	free(win);
	win = NULL;
}

void
	ft_destroy_wins(t_mydata *mydata)
{
	int	i;

	i = -1;
	while (++i < mydata->win_count)
		ft_destroy_win(mydata->wins[i]);
	mydata->win_count = 0;
}
