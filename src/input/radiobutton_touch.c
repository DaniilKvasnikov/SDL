/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radiobutton_touch.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 11:24:23 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/23 10:06:20 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*radiobutton_touch(void *win, void *but, SDL_Event *ev, t_point_int *mouse)
{
	t_element	*elem;

	elem = (t_element *)but;
	if (*elem->int_par == 1 &&
		elem->sub_group != NULL &&
		(elem = groupe_touch(((t_element *)but), win, ev, mouse)) != NULL)
		return (elem);
	if (!chech_input_mouse(but, mouse))
		return (0);
	if (*elem->int_par == 0)
		*elem->int_par = 1;
	return (elem);
}
