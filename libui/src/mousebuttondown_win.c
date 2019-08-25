/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousebuttondown_win.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 13:09:06 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 15:10:07 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	mousebuttondown_win(t_win *win, SDL_Event *event)
{
	int			i;
	t_element	*elem;

	i = -1;
	while (win->elements[++i])
	{
		elem = win->elements[i];
		if (elem->active &&
			chech_input_mouse(elem, &g_sdl_data->mouse))
		{
			if (elem->mouse_down)
				elem->mouse_down(elem, event);
			return ;
		}
	}
}
