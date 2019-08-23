/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radiobutton_touch.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 11:24:23 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/23 20:33:00 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*radiobutton_touch(t_win *win, t_element *elem, SDL_Event *ev, t_point_int *mouse)
{
	t_element	*tmp_elem;

	if (*elem->int_par == 1 &&
		elem->sub_group != NULL &&
		(tmp_elem = groupe_touch(elem, win, ev, mouse)) != NULL)
		return (tmp_elem);
	if (!chech_input_mouse(elem, mouse))
		return (0);
	if (elem->int_par != NULL && *elem->int_par == 0)
		*elem->int_par = 1;
	return (elem);
}
