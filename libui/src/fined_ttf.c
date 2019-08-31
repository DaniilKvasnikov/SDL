/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fined_ttf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 17:12:06 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/31 11:07:59 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	fined_ttf(t_sdl_data *data, char *name)
{
	int	i;

	i = -1;
	while (data->ttfs[++i] != NULL)
		if (ft_strcmp(data->ttfs[i]->name, name) == 0)
			return (1);
	return (0);
}
