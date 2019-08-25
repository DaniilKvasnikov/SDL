/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_active_win.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 12:35:48 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 12:49:37 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_win
	*get_active_win(SDL_Event *event)
{
	int	id;
	int	i;

	i = -1;
	id = event->window.windowID;
	while (g_sdl_data->wins[++i] != NULL)
		if (g_sdl_data->wins[i]->id == id)
			return (g_sdl_data->wins[i]);
	return (NULL);
}
