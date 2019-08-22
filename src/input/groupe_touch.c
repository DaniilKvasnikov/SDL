/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   groupe_touch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 09:27:15 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/22 14:10:44 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*groupe_touch(t_element *elem, void *win, SDL_Event *ev, t_point_int *mouse)
{
	int			i;
	t_element	*tmp;

	i = -1;
	if (elem->sub_group != NULL)
		while (++i < elem->sub_group->count)
		{
			if (((t_element *)elem->sub_group->elements[i])->element_touch)
			{
				tmp = ((t_element *)elem->sub_group->elements[i])->element_touch(win, elem->sub_group->elements[i], ev, mouse);
				if (tmp != NULL)
				{
					*elem->int_par = i + 1;
					return (tmp);
				}
			}
		}
	return (NULL);
}
