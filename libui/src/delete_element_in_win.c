/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_element_in_win.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 02:08:20 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/18 02:10:55 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*delete_element_in_win(t_win *win, t_element *element)
{
	t_element	**ptr;
	int			i;
	int			j;

	ptr = win->elements;
	win->elements = (t_element **)malloc(sizeof(t_element *) * win->element_count);
	i = -1;
	j = -1;
	while (++i < win->element_count)
		if (ptr[i] != element)
			win->elements[++j] = ptr[i];
	win->element_count = j + 1;
	if (ptr != NULL)
		free(ptr);
	return (element);
}
