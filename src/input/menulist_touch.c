/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menulist_touch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 10:53:51 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/23 20:33:00 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*menulist_touch(t_win *win, t_element *elem, SDL_Event *ev, t_point_int *mouse)
{
	t_element	*tmp_elem;
	t_win		*ptr_win;

	ptr_win = (t_win *)win;
	if (is_parent_active_elem(ptr_win->active_element, elem) &&
		elem->sub_group &&
		(tmp_elem = groupe_touch(elem, ptr_win, ev, mouse)) != NULL)
		return (tmp_elem);
	if (!chech_input_mouse(elem, mouse))
		return (0);
	return (elem);
}
