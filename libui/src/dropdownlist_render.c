/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dropdownlist_render.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 08:53:13 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/23 20:33:00 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

static void
	groupe_draw_notouch(t_win *win, t_group_e *group)
{
	int	i;

	i = -1;
	while (++i < group->count)
	{
		if (((t_element *)group->elements[i])->element_touch == NULL && ((t_element *)group->elements[i])->draw)
			((t_element *)group->elements[i])->draw(win, ((t_element *)group->elements[i]));
	}
}

int
	dropdownlist_render(t_win *win, t_element *elem)
{
	t_win		*ptr_win;
	
	ptr_win = (t_win *)win;
	if (elem->textures_count >= 1)
		texture_render(ptr_win, elem, elem->textures[0].tex);
	if (is_parent_active_elem(ptr_win->active_element, elem)
		&& elem->sub_group != NULL)
		groupe_draw(ptr_win, elem->sub_group);
	if (elem->sub_group != NULL)
		groupe_draw_notouch(ptr_win, elem->sub_group);
	if (elem->str != NULL)
		render_text(ptr_win, elem, elem->str);
	return (0);
}
