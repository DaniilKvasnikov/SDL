/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_element_to_win.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 13:58:35 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 17:55:46 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*add_element_to_win(t_win *win, t_element *elem)
{
	int			count;
	int			i;
	t_element	**elems;

	count = ui_element_count(win);
	elems = (t_element **)ui_checkmalloc(malloc(sizeof(t_element *) * (count + 1)), "add new elem", __LINE__, __FILE__);
	i = -1;
	while (win->elements[++i] != NULL)
		elems[i] = win->elements[i];
	elems[i] = elem;
	elems[i + 1] = NULL;
	free(win->elements);
	win->elements = elems;
	return (elem);
}
