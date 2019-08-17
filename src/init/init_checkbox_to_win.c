/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_checkbox_to_win.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 09:48:23 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/17 04:38:51 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*init_checkbox_to_win(t_rect rect, char *path_tex1, char *path_tex2, t_win *win,
		t_element *(*button_pressed)(void *win, void *but, SDL_Event *ev, t_point_int *mouse),
		t_element *(*active_elem)(void *ptr_win, void *buf),
		int (*draw)(void *win, void *elem))
{
	t_element *elem;

	elem = init_element(rect, path_tex1, path_tex2, win, NULL, button_pressed, NULL, NULL, draw);
	elem->active_elem = active_elem;
	return (elem);
}
