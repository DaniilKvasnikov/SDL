/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_by_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyabaturin <ilyabaturin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 08:50:12 by ilyabaturin       #+#    #+#             */
/*   Updated: 2019/08/28 08:52:32 by ilyabaturin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_texture
	*get_texture_by_path(t_win *win, char *texture_path)
{
	int	i;

	i = -1;
	while (win->textures[++i] != NULL)
		if (ft_strcmp(win->textures[i]->path, texture_path) == 0)
			return (win->textures[i]);
	return (NULL);
}
