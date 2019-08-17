/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menulist_touch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 10:53:51 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/17 13:19:32 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*menulist_touch(void *win, void *but, SDL_Event *ev, t_point_int *mouse)
{
	t_element	*elem;
	t_win		*ptr_win;

	ptr_win = (t_win *)win;
	if (is_parent_active_elem(ptr_win->active_element, (t_element *)but) &&
		((t_element *)but)->sub_group &&
		(elem = groupe_touch(((t_element *)but), ptr_win, ev, mouse)) != NULL)
		return (elem);
	if (!chech_input_mouse(but, mouse))
		return (0);
	return ((t_element *)but);
}
