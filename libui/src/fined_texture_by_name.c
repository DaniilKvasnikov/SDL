/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fined_texture_by_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 14:26:44 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 14:28:42 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	fined_texture_by_name(t_win *win, char *name)
{
	int	i;

	i = -1;
	while (win->textures[++i] != NULL)
		if (ft_strcmp(win->textures[i]->name, name) == 0)
			return (1);
	return (0);
}
