/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkbox_render.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 20:17:54 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/23 19:17:31 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	groupe_draw_notouch(t_win *win, t_group_e *group)
{
	int	i;

	i = -1;
	while (++i < group->count)
	{
		if (((t_element *)group->elements[i])->element_touch == NULL &&
			((t_element *)group->elements[i])->draw != NULL)
			((t_element *)group->elements[i])->draw(win, ((t_element *)group->elements[i]));
	}
}

int
	checkbox_render(void *win, t_element *elem)
{
	t_win		*ptr_win;

	ptr_win = (t_win *)win;
	if (*elem->int_par == 0 && elem->textures_count >= 1)
		texture_render(ptr_win, elem, elem->textures[0].tex);
	else if (*elem->int_par == 1 && elem->textures_count >= 2)
		texture_render(ptr_win, elem, elem->textures[1].tex);
	if (elem->str != NULL)
		render_text(ptr_win, elem, elem->str);
	if (*elem->int_par == 1 && elem->sub_group != NULL)
		groupe_draw(ptr_win, elem->sub_group);
	if (elem->sub_group != NULL)
		groupe_draw_notouch(ptr_win, elem->sub_group);
	return (0);
}
