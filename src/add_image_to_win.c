/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_image_to_win.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 08:59:19 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/12 09:26:52 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	add_image_to_win(t_rect rect, char *path_tex, t_win *win)
{
	t_element	**ptr;
	int			i;

	win->element_count++;
	if (win->element_count == 1)
	{
		win->elements = (t_element **)malloc(sizeof(t_element *));
		win->elements[0] = init_element(rect, path_tex, NULL, win, NULL, NULL);
	}
	else
	{
		ptr = win->elements;
		win->elements = (t_element **)malloc(sizeof(t_element *) * win->element_count);
		i = -1;
		while (++i < (win->element_count - 1))
			win->elements[i] = ptr[i];
		win->elements[i] = init_element(rect, path_tex, NULL, win, NULL, NULL);
		free(ptr);
	}
}
