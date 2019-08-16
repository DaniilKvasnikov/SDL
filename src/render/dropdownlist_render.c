/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dropdownlist_render.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 08:53:13 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/16 09:10:55 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

static void
	groupe_draw(t_win *win, t_group_e *group)
{
	int	i;

	i = -1;
	while (++i < group->count)
	{
		if (((t_element *)group->elements[i])->draw != NULL)
			((t_element *)group->elements[i])->draw(win, ((t_element *)group->elements[i]));
	}
}

int
	dropdownlist_render(void *win, void *elem)
{
	t_win		*ptr_win;
	t_element	*ptr_elem;
	
	ptr_win = (t_win *)win;
	ptr_elem = (t_element *)elem;
	if (ptr_elem->textures_count >= 1)
		texture_render(ptr_win, ptr_elem, ptr_elem->textures[0].tex);
	if (ptr_elem->str != NULL)
		ft_printf("active = %s\n", ptr_elem->str);
	if ((ptr_win->active_element == ptr_elem  || is_parent_active_elem(ptr_win->active_element, ptr_elem))
		&& ptr_elem->sub_group != NULL)
		groupe_draw(ptr_win, ptr_elem->sub_group);
	if (ptr_elem->str != NULL)
		render_text(ptr_win, ptr_elem, ptr_elem->str);
	return (0);
}
