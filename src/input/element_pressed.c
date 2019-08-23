/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_pressed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 15:23:53 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/23 20:33:00 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*element_pressed(t_win *win, t_element *elem, SDL_Event *ev, t_point_int *mouse)
{
	if (!chech_input_mouse(elem, mouse))
		return (NULL);
	ft_putendl("Button pressed");
	return (elem);
}
