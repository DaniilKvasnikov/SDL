/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fined_param_by_name.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 18:48:24 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/31 12:20:49 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	fined_param_by_name(t_param **params, char *name)
{
	int	i;

	i = -1;
	while (params[++i] != NULL)
		if (ft_strcmp(params[i]->name, name) == 0)
			return (1);
	return (0);
}
