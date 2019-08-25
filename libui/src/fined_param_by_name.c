/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fined_param_by_name.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 18:48:24 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 18:49:01 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	fined_param_by_name(t_element *elem, char *name)
{
	int	i;

	i = -1;
	while (elem->params[++i] != NULL)
		if (ft_strcmp(elem->params[i]->name, name) == 0)
			return (1);
	return (0);
}
