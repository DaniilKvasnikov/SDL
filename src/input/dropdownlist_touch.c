/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dropdownlist_touch.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 09:19:01 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/15 12:14:06 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

static int
	groupe_touch(t_group_e *group, void *win, SDL_Event *ev, t_point_int *mouse)
{
	int	i;

	i = -1;
	while (++i < group->count)
		if (chech_input_mouse((t_element *)group->elements[i], mouse))
		{
			push_text_to_parent(win, (t_element *)group->elements[i], ev);
			return (1);
		}
	return (0);
}

int
	dropdownlist_touch(void *win, void *but, SDL_Event *ev, t_point_int *mouse)
{
	ft_putendl("dropdownlist touch 1");
	if (((t_element *)but)->sub_group &&
		groupe_touch(((t_element *)but)->sub_group, win, ev, mouse) == 1)
		return (0);
	ft_putendl("dropdownlist touch 2");
	if (!chech_input_mouse(but, mouse))
		return (0);
	return (1);
}
