/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_win_surface.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamerd <gamerd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 15:25:25 by gamerd            #+#    #+#             */
/*   Updated: 2019/07/19 15:26:28 by gamerd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	ft_update_win_surface(t_mydata *mydata)
{
	int	i;

	i = -1;
	while (++i < mydata->win_count)
		SDL_UpdateWindowSurface(mydata->wins[i]->win);
}