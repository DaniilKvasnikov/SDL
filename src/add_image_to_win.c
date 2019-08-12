/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_image_to_win.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 08:59:19 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/12 09:02:12 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	add_image_to_win(t_rect rect, char *path_tex, t_win *win)
{
	t_button	**ptr;
	int			i;

	win->buttons_count++;
	if (win->buttons_count == 1)
	{
		win->buttons = (t_button **)malloc(sizeof(t_button *));
		win->buttons[0] = init_button(rect, path_tex, win, NULL, NULL);
	}
	else
	{
		ptr = win->buttons;
		win->buttons = (t_button **)malloc(sizeof(t_button *) * win->buttons_count);
		i = -1;
		while (++i < (win->buttons_count - 1))
			win->buttons[i] = ptr[i];
		win->buttons[i] = init_button(rect, path_tex, win, NULL, NULL);
		free(ptr);
	}
}
