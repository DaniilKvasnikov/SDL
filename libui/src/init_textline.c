/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 08:48:00 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/21 17:30:09 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*init_textline(t_rect rect, char *path_tex1, t_win *win, char *str,
		t_element *(*element_touch)(void *win, void *but, SDL_Event *ev, t_point_int *mouse),
		int (*keyboard_press)(void *win, void *but, char *char_input),
		t_element *(*active_elem)(void *ptr_win, void *buf),
		int (*draw)(void *win, void *elem))
{
	t_element *elem;

	elem = init_element(rect, path_tex1, NULL, win, str, element_touch, NULL, keyboard_press, draw);
	elem->active_elem = active_elem;
	return (elem);
}
