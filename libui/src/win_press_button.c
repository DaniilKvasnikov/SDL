/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_press_button.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 15:20:16 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/18 20:53:22 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	win_press_button(t_win *win, SDL_Event *ev, int x, int y)
{
	int			i;
	t_element	*tmp;
	t_element	*last_active;

	i = win->element_count;
	last_active = win->active_element;
	while (--i >= 0)
	{
		if (win->elements[i]->element_touch != NULL)
		{
			if ((tmp = win->elements[i]->element_touch(win, win->elements[i], ev, &(t_point_int){x, y})) != NULL)
			{
				if (last_active != tmp)
				{
					if (last_active && last_active->deactive_elem)
						last_active->deactive_elem(win, last_active);
					last_active = tmp;
				}
				if (tmp->active_elem != NULL)
					tmp->active_elem(win, tmp);
				else
					win->active_element = NULL;
				return ;
			}
		}
	}
	if (last_active != NULL && last_active->deactive_elem)
		last_active->deactive_elem(win, last_active);
	ft_printf("Not touch\n");
	win->active_element = NULL;
}