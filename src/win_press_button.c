/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_press_button.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 15:20:16 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/16 10:25:36 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	win_press_button(t_win *win, SDL_Event *ev, int x, int y)
{
	int			i;
	t_element	*tmp;

	i = win->element_count;
	while (--i >= 0)
	{
		if (win->elements[i]->element_touch != NULL)
		{
			if ((tmp = win->elements[i]->element_touch(win, win->elements[i], ev, &(t_point_int){x, y})) != NULL)
			{
				win->active_element = tmp;
				return ;
			}
		}
	}
	ft_printf("Not touch\n");
	win->active_element = NULL;
}