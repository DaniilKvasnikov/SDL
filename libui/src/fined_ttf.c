/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fined_ttf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 17:12:06 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 17:12:48 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	fined_ttf(char *name)
{
	int	i;

	i = -1;
	while (g_sdl_data->ttfs[++i] != NULL)
		if (ft_strcmp(g_sdl_data->ttfs[i]->name, name) == 0)
			return (1);
	return (0);
}
