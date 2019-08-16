/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   groupe_touch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 09:27:15 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/16 10:23:54 by rrhaenys         ###   ########.fr       */
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
	{
		if (((tmp = (t_element *)elem->sub_group->elements[i])->element_touch(win, elem->sub_group->elements[i], ev, mouse)) != NULL)
		{
			elem->int_par = i + 1;
			if (tmp->sub_group != NULL)
			{
				if (((t_win *)win)->active_element == tmp)
					return (groupe_touch(tmp, win, ev, mouse));
				else
					return (tmp);
			}
			push_text_to_parent(win, tmp, ev);
			return (tmp);
		}
	}
	return (NULL);
}
