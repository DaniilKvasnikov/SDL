/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_elem_by_name.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyabaturin <ilyabaturin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 10:07:09 by ilyabaturin       #+#    #+#             */
/*   Updated: 2019/09/04 10:11:23 by ilyabaturin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*delete_elem_by_name(t_win *win, char *name)
{
	int			count;
	int			i;
	int			j;
	t_element	**elems;

	count = ui_element_count(win);
	elems = (t_element **)ui_checkmalloc(malloc(sizeof(t_element *) * (count - 1)), "delete elem", __LINE__, __FILE__);
	i = -1;
	j = -1;
	while (win->elements[++i] != NULL)
		if (ft_strcmp(win->elements[i]->name, name) != 0)
			elems[++j] = win->elements[i];
	elems[++j] = NULL;
	free(win->elements);
	win->elements = elems;
	return (elems[0]);
}
