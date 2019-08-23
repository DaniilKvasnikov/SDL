/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkbox_touch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 09:51:39 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/23 19:29:13 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*checkbox_touch(void *win, t_element *elem, SDL_Event *ev, t_point_int *mouse)
{
	if (!chech_input_mouse(elem, mouse))
		return (0);
	if (*elem->int_par == 0)
		*elem->int_par = 1;
	else if (*elem->int_par == 1)
		*elem->int_par = 0;
	return (elem);
}
