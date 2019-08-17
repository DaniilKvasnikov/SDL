/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image_to_win.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 08:59:19 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/17 06:00:53 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*init_image_to_win(t_rect rect, char *path_tex, t_win *win,
						t_element *(*image_touch)(void *win, void *but, SDL_Event *ev, t_point_int *mouse),
						t_element *(*element_pressed)(void *win, void *but, SDL_Event *ev, t_point_int *mouse),
						t_element *(*active_elem)(void *ptr_win, void *buf),
						int (*draw)(void *win, void *elem))
{
	t_element *elem;

	elem = init_element(rect, path_tex, NULL, win, NULL, image_touch, element_pressed, NULL, draw);
	elem->active_elem = active_elem;
	return (elem);
}
