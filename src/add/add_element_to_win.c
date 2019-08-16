/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_element_to_win.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 15:17:18 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/16 08:43:02 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*add_element_to_win(t_win *win, t_element *element)
{
	t_element	**ptr;
	int			i;

	ptr = win->elements;
	win->element_count++;
	win->elements = (t_element **)malloc(sizeof(t_element *) * win->element_count);
	i = -1;
	while (++i < (win->element_count - 1))
		win->elements[i] = ptr[i];
	win->elements[win->element_count - 1] = element;
	if (ptr != NULL)
		free(ptr);
	return (element);
}
