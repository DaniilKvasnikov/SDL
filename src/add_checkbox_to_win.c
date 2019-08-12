/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_checkbox_to_win.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 09:48:23 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/12 09:49:06 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	add_checkbox_to_win(t_rect rect, char *path_tex1, char *path_tex2, t_win *win, char *str,
		int (*button_pressed)(void *win, void *but, SDL_Event *ev))
{
	t_element	**ptr;
	int			i;

	win->element_count++;
	if (win->element_count == 1)
	{
		win->elements = (t_element **)malloc(sizeof(t_element *));
		win->elements[0] = init_element(rect, path_tex1, path_tex2, win, str, button_pressed);
	}
	else
	{
		ptr = win->elements;
		win->elements = (t_element **)malloc(sizeof(t_element *) * win->element_count);
		i = -1;
		while (++i < (win->element_count - 1))
			win->elements[i] = ptr[i];
		win->elements[i] = init_element(rect, path_tex1, path_tex2, win, str, button_pressed);
		free(ptr);
	}
}
