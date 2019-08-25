/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_by_name.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 14:09:32 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 14:12:09 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_texture
	*get_texture_by_name(t_win *win, char *texture_name)
{
	int	i;

	i = -1;
	while (win->textures[++i] != NULL)
		if (ft_strcmp(win->textures[i]->name, texture_name) == 0)
			return (win->textures[i]);
	return (NULL);
}
