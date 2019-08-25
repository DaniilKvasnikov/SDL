/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fined_element_by_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 13:43:40 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 13:45:18 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	fined_element_by_name(t_win *win, char *name)
{
	int	i;

	i = -1;
	while (win->elements[++i] != NULL)
		if (ft_strcmp(win->elements[i]->name, name) == 0)
			return (1);
	return (0);
}
