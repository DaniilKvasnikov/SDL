/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fined_win_by_name.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 11:52:16 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 11:53:45 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	fined_win_by_name(char *name)
{
	int	i;

	i = -1;
	while (g_sdl_data->wins[++i] != NULL)
		if (ft_strcmp(g_sdl_data->wins[i]->name, name) == 0)
			return (1);
	return (0);
}
