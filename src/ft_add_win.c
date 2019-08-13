/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:58:47 by gamerd            #+#    #+#             */
/*   Updated: 2019/08/13 10:43:23 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_win
	*ft_add_win(t_mydata *mydata, t_win *new_win)
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