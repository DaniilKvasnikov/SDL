/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 12:23:29 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 17:56:00 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	destroy_win(t_win *win)
{
	int		i;
	int		j;
	t_win	**wins;

	wins = (t_win **)ui_checkmalloc(malloc(sizeof(t_win *) * (ui_wins_count() - 1)), "destroy win", __LINE__, __FILE__);
	i = -1;
	j = -1;
	while (g_sdl_data->wins[++i] != NULL)
		if (g_sdl_data->wins[i] != win)
			wins[++j] = g_sdl_data->wins[i];
	wins[++j] = NULL;
	g_sdl_data->wins = wins;
	SDL_DestroyRenderer(win->ren);
	SDL_DestroyWindow(win->win);
	free_if_not_null(win->name);
	i = -1;
	while (win->elements[++i] != NULL)
	{
		destroy_element(win->elements[i]);
	}
	i = -1;
	while (win->layers[++i] != NULL)
	{
		destroy_layer(win->layers[i]);
	}
	i = -1;
	while (win->textures[++i] != NULL)
	{
		destroy_texture(win->textures[i]);
	}
	free_if_not_null(win);
}
