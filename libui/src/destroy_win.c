/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyabaturin <ilyabaturin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 12:23:29 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/27 13:44:58 by ilyabaturin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	destroy_win(t_win *win)
{
	int		i;
	int		j;
	t_win	**wins;

	if (win == NULL)
		return ;
	wins = (t_win **)ui_checkmalloc(malloc(sizeof(t_win *) * (ui_wins_count() - 1)), "destroy win", __LINE__, __FILE__);
	i = -1;
	j = -1;
	while (g_sdl_data->wins[++i] != NULL)
		if (g_sdl_data->wins[i] != win)
			wins[++j] = g_sdl_data->wins[i];
	wins[++j] = NULL;
	g_sdl_data->wins = wins;
	if (win->ren)
		SDL_DestroyRenderer(win->ren);
	if (win->win)
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
