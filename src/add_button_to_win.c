/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_button_to_win.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 08:57:13 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/12 08:57:30 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	add_button_to_win(t_rect rect, char *path_tex, t_win *win, char *str,
		int (*button_pressed)(void *win, void *but, SDL_Event *ev))
{
	t_button	**ptr;
	int			i;

	win->buttons_count++;
	if (win->buttons_count == 1)
	{
		win->buttons = (t_button **)malloc(sizeof(t_button *));
		win->buttons[0] = init_button(rect, path_tex, win, str, button_pressed);
	}
	else
	{
		ptr = win->buttons;
		win->buttons = (t_button **)malloc(sizeof(t_button *) * win->buttons_count);
		i = -1;
		while (++i < (win->buttons_count - 1))
			win->buttons[i] = ptr[i];
		win->buttons[i] = init_button(rect, path_tex, win, str, button_pressed);
		free(ptr);
	}
}
