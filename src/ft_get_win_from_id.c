/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_win_from_id.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamerd <gamerd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 17:14:51 by gamerd            #+#    #+#             */
/*   Updated: 2019/07/19 17:16:28 by gamerd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_win
	*ft_get_win_from_id(t_mydata *mydata, int id)
{
	int	i;

	i = -1;
	while (++i < mydata->win_count)
		if (mydata->wins[i]->window_id == id)
			return (mydata->wins[i]);
	return (0);
}