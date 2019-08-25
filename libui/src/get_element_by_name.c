/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_element_by_name.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 16:34:25 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 16:35:30 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*get_element_by_name(t_win *win, char *name)
{
	int	i;

	i = -1;
	while (win->elements[++i] != NULL)
		if (ft_strcmp(win->elements[i]->name, name) == 0)
			return (win->elements[i]);
	return (NULL);
}
