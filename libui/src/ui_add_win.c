/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_add_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 12:10:27 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 12:14:24 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_win
	*ui_add_win(t_win *win)
{
	int		count;
	int		i;
	t_win	**wins;

	count = ui_wins_count();
	wins = (t_win **)ui_checkmalloc(malloc(sizeof(t_win *) * (count + 1)), "add new win");
	i = -1;
	while (g_sdl_data->wins[++i] != NULL)
		wins[i] = g_sdl_data->wins[i];
	wins[i] = win;
	wins[i + 1] = NULL;
	free(g_sdl_data->wins);
	g_sdl_data->wins = wins;
	return (win);
}
