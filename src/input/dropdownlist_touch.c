/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dropdownlist_touch.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 09:19:01 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/15 10:09:23 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	dropdownlist_touch(void *win, void *but, SDL_Event *ev, t_point_int *mouse)
{
	if (!chech_input_mouse(but, mouse))
		return (0);
	ft_putendl("dropdownlist touch");
	return (1);
}
