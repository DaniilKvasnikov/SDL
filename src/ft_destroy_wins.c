/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_wins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamerd <gamerd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 13:10:56 by gamerd            #+#    #+#             */
/*   Updated: 2019/07/19 13:12:31 by gamerd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	ft_destroy_win(t_mydata *mydata)
{
	int	i;

	i = -1;
	while (++i < mydata->win_count)
	{
		SDL_DestroyRenderer(mydata->wins[i]->ren);
		SDL_DestroyWindow(mydata->wins[i]->win);
	}
}
