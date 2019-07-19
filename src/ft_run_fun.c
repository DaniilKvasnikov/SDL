/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_fun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamerd <gamerd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 15:58:11 by gamerd            #+#    #+#             */
/*   Updated: 2019/07/19 16:19:56 by gamerd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	ft_run_fun(t_mydata *mydata, int id, void (*fun)(t_mydata *mydata, int id))
{
	int	i;

	i = -1;
	while (++i < mydata->win_count)
		if (mydata->wins[i]->window_id == id)
			fun(mydata, id);
}