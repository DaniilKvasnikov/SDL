/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_win_by_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 12:46:35 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/26 12:47:31 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_win
	*get_win_by_name(char *name)
{
	int	i;

	i = -1;
	while (g_sdl_data->wins[++i] != NULL)
		if (ft_strcmp(g_sdl_data->wins[i]->name, name) == 0)
			return (g_sdl_data->wins[i]);
	return (NULL);
}
