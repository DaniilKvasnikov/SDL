/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_to_win.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 14:11:20 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/09 14:23:27 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_texture
	*get_texture_to_win(t_win *win, char *path)
{
	int	i;

	i = -1;
	while (++i < win->textures_count)
		if (ft_strcmp(win->textures[i].name, path) == 0)
			return (&win->textures[i]);
	add_texture_to_win(win, path);
	i = -1;
	while (++i < win->textures_count)
		if (ft_strcmp(win->textures[i].name, path) == 0)
			return (&win->textures[i]);
	return (NULL);
}