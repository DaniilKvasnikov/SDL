/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_menulist_to_win.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 08:22:13 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/23 20:33:00 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*init_menulist_to_win(t_rect rect, char *path_tex, t_win *win, char *str,
		t_element *(*button_pressed)(t_win *win, t_element *elem, SDL_Event *ev, t_point_int *mouse),
		t_element *(*active_elem)(t_win *win, t_element *elem),
		int (*draw)(t_win *win, t_element *elem))
{
	t_element *element_new = init_element(rect, path_tex, NULL, win, str, NULL, NULL, button_pressed, NULL, NULL, draw);
	element_new->active_elem = active_elem;
	return (element_new);
}
