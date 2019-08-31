/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ttf_by_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 17:22:35 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/31 11:15:59 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_ttf
	*get_ttf_by_name(t_sdl_data *data, char *name, int size)
{
	int	i;

	i = -1;
	while (data->ttfs[++i] != NULL)
		if (ft_strcmp(data->ttfs[i]->name, name) == 0 && data->ttfs[i]->size == size)
			return (data->ttfs[i]);
	return (NULL);
}
