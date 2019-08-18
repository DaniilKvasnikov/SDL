/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_texture_to_win.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 14:04:49 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/09 14:23:11 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	add_texture_to_win(t_win *win, char *path)
{
	int			i;
	t_texture	*textures;

	textures = (t_texture *)malloc(sizeof(t_texture) * (win->textures_count + 1));
	if (textures == NULL)
		exit(1);
	i = -1;
	while (++i < win->textures_count)
		textures[i] = win->textures[i];
	textures[i].tex = loadTexture(path, win);
	textures[i].name = path;
	if (win->textures_count > 0)
		free(win->textures);
	win->textures_count++;
	win->textures = textures;
}