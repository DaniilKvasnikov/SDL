/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamerd <gamerd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:58:47 by gamerd            #+#    #+#             */
/*   Updated: 2019/07/19 13:05:07 by gamerd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	ft_add_win(t_mydata *mydata, t_win *new_win)
{
	int		index;
	t_win	**new_wins;

	new_wins = (t_win **)malloc(sizeof(t_win *) * (++mydata->win_count));
	index = -1;
	while (++index < (mydata->win_count - 1))
		new_wins[index] = mydata->wins[index];
	new_wins[index] = new_win;
	if (mydata->win_count > 1)
		free(mydata->wins);
	mydata->wins = new_wins;
}