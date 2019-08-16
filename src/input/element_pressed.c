/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_pressed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 15:23:53 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/16 08:38:20 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*element_pressed(void *win, void *but, SDL_Event *ev, t_point_int *mouse)
{
	if (!chech_input_mouse(but, mouse))
		return (NULL);
	ft_putendl("Button pressed");
	return ((t_element *)but);
}
