/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radiobutton_touch.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 11:24:23 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/22 14:10:51 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*radiobutton_touch(void *win, void *but, SDL_Event *ev, t_point_int *mouse)
{
	t_element	*elem;

	if (!chech_input_mouse(but, mouse))
		return (0);
	elem = (t_element *)but;
	if (*elem->int_par == 0)
		*elem->int_par = 1;
	return (elem);
}
