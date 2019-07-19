/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamerd <gamerd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 16:09:55 by gamerd            #+#    #+#             */
/*   Updated: 2019/07/19 16:22:01 by gamerd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	ft_delete_win(t_mydata *mydata, int id)
{
	int		i;
	int		j;

	if (mydata->wins[0]->window_id == id)
	{
		ft_destroy_win(mydata->wins[0]);
		mydata->win_count--;
		mydata->wins++;
		return ;
	}
	i = -1;
	while (++i < mydata->win_count)
	{
		if (mydata->wins[i]->window_id == id)
		{
			ft_destroy_win(mydata->wins[i]);
			j = i;
			while (++j < mydata->win_count)
				mydata->wins[j - 1] = mydata->wins[j];
			mydata->win_count--;
			return ;
		}
	}
}