/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_touch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:48:53 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/17 04:33:05 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*element_touch(void *win, void *but, SDL_Event *ev, t_point_int *mouse)
{
	if (!chech_input_mouse(but, mouse))
		return (0);
	ft_printf("Element touch %s\n", ((t_element *)but)->str);
	return ((t_element *)but);
}
