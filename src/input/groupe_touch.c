/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   groupe_touch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 09:27:15 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/16 09:27:30 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*groupe_touch(t_element *elem, void *win, SDL_Event *ev, t_point_int *mouse)
{
	int			i;
	t_element	*tmp;

	i = -1;
	while (++i < elem->sub_group->count)
		if (chech_input_mouse((t_element *)elem->sub_group->elements[i], mouse))
		if (((tmp = (t_element *)elem->sub_group->elements[i])->element_touch(win, elem->sub_group->elements[i], ev, mouse)) != NULL)
		{
			elem->int_par = i + 1;
			push_text_to_parent(win, tmp, ev);
			if (tmp->sub_group != NULL)
				return (tmp);
			return (NULL);
		}
	return (NULL);
}
