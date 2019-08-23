/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sliders_to_win.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 19:30:02 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/23 19:03:28 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*init_sliders_to_win(t_rect rect, char *path_tex1, char *path_tex2, t_win *win, int *int_par, float *float_par,
		t_element *(*element_touch)(void *win, struct s_element *elem, SDL_Event *ev, t_point_int *mouse),
		t_element *(*element_pressed)(void *win, struct s_element *elem, SDL_Event *ev, t_point_int *mouse),
		t_element *(*active_elem)(void *ptr_win, struct s_element *elem),
		int (*draw)(void *win, struct s_element *elem))
{
	t_element *elem;

	elem = init_element(rect, path_tex1, path_tex2, win, NULL, int_par, float_par, element_touch, element_pressed, NULL, draw);
	elem->active_elem = active_elem;
	return (elem);
}
