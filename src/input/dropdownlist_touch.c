/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dropdownlist_touch.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 09:19:01 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/16 09:27:27 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*dropdownlist_touch(void *win, void *but, SDL_Event *ev, t_point_int *mouse)
{
	t_element	*elem;
	t_win		*ptr_win;

	ptr_win = (t_win *)win;
	ft_putendl("dropdownlist touch 1");
	if (is_parent_active_elem(ptr_win->active_element, (t_element *)but) &&
		((t_element *)but)->sub_group &&
		(elem = groupe_touch(((t_element *)but), win, ev, mouse)) != NULL)
		return (elem);
	ft_putendl("dropdownlist touch 2");
	if (!chech_input_mouse(but, mouse))
		return (0);
	return ((t_element *)but);
}
