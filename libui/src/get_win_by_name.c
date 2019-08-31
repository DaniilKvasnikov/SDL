/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_win_by_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 12:46:35 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/31 11:18:55 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_win
	*get_win_by_name(t_sdl_data *data, char *name)
{
	int	i;

	i = -1;
	while (data->wins[++i] != NULL)
		if (ft_strcmp(data->wins[i]->name, name) == 0)
			return (data->wins[i]);
	return (NULL);
}
