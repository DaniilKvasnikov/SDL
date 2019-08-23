/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_touch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:48:53 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/23 19:24:57 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*element_touch(void *win, t_element *elem, SDL_Event *ev, t_point_int *mouse)
{
	if (!chech_input_mouse(elem, mouse))
		return (0);
	((t_element *)elem)->last_delta =
		(t_point_int){
			mouse->x - ((t_element *)elem)->rect.x,
			mouse->y - ((t_element *)elem)->rect.y};
	ft_printf("Element touch %s\n", ((t_element *)elem)->str);
	return ((t_element *)elem);
}
