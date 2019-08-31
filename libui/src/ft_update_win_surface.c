/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_win_surface.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 14:40:40 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/31 11:14:10 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	ft_update_win_surface(t_sdl_data *data)
{
	int	i;

	i = -1;
	while (data->wins[++i])
	{
		SDL_RenderPresent(data->wins[i]->ren);
		SDL_UpdateWindowSurface(data->wins[i]->win);
	}
}
