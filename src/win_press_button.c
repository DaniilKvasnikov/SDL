/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_press_button.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 15:20:16 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/12 09:14:47 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	win_press_button(t_win *win, SDL_Event *ev, int x, int y)
{
	int		i;
	t_point	*pos;
	t_point	*size;

	i = win->element_count;
	while (--i >= 0)
	{
		pos = &win->elements[i]->pos;
		size = &win->elements[i]->size;
		if (x >= pos->x && x <= (pos->x + size->x)
			&& y >= pos->y && y <= (pos->y + size->y))
		{
			if (win->elements[i]->element_pressed != NULL)
				win->elements[i]->element_pressed(win, win->elements[i], ev);
			return ;
		}
	}
}