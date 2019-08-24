/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_draw_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 14:17:01 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/24 14:19:57 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

t_element
	*set_draw_type(t_win *win, t_element *elem, SDL_Event *ev, t_point_int *mouse)
{
	if (!chech_input_mouse(elem, mouse))
		return (0);
	win->mydata->draw_type = *elem->int_par;
	ft_printf("Element touch %s\n", ((t_element *)elem)->str);
	return ((t_element *)elem);
}
