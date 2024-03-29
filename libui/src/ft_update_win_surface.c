/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_win_surface.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 14:40:40 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 15:42:41 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	ft_update_win_surface(void)
{
	int	i;

	i = -1;
	while (g_sdl_data->wins[++i])
	{
		SDL_RenderPresent(g_sdl_data->wins[i]->ren);
		SDL_UpdateWindowSurface(g_sdl_data->wins[i]->win);
	}
}
