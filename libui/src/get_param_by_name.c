/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param_by_name.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyabaturin <ilyabaturin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 09:57:19 by ilyabaturin       #+#    #+#             */
/*   Updated: 2019/08/27 09:59:17 by ilyabaturin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	*get_param_by_name(t_param **params, char *str)
{
	int	i;

	i = -1;
	while (params[++i] != NULL)
		if (ft_strcmp(params[i]->name, str) == 0)
			return (params[i]->par);
	return (NULL);
}
