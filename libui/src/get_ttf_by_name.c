/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ttf_by_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 17:22:35 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 17:47:00 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_ttf
	*get_ttf_by_name(char *name, int size)
{
	int	i;

	i = -1;
	while (g_sdl_data->ttfs[++i] != NULL)
		if (ft_strcmp(g_sdl_data->ttfs[i]->name, name) == 0 && g_sdl_data->ttfs[i]->size == size)
			return (g_sdl_data->ttfs[i]);
	return (NULL);
}
