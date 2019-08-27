/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_param_by_name.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyabaturin <ilyabaturin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:49:38 by ilyabaturin       #+#    #+#             */
/*   Updated: 2019/08/27 16:50:28 by ilyabaturin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	*set_param_by_name(t_param **params, char *str, void *new_param)
{
	int	i;

	i = -1;
	while (params[++i] != NULL)
		if (ft_strcmp(params[i]->name, str) == 0)
			return (params[i]->par = new_param);
	return (NULL);
}
