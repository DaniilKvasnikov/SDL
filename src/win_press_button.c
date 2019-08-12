/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_press_button.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 15:20:16 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/12 09:05:04 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	win_press_button(t_win *win, SDL_Event *ev, int x, int y)
{
	int		i;
	t_point	*pos;
	t_point	*size;

	i = win->buttons_count;
	while (--i >= 0)
	{
		pos = &win->buttons[i]->pos;
		size = &win->buttons[i]->size;
		if (x >= pos->x && x <= (pos->x + size->x)
			&& y >= pos->y && y <= (pos->y + size->y))
		{
			if (win->buttons[i]->button_pressed != NULL)
				win->buttons[i]->button_pressed(win, win->buttons[i], ev);
			return ;
		}
	}
}