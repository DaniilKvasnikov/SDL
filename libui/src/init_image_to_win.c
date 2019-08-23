/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image_to_win.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 08:59:19 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/23 19:03:07 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*init_image_to_win(t_rect rect, char *path_tex, t_win *win,
						t_element *(*image_touch)(void *win, struct s_element *elem, SDL_Event *ev, t_point_int *mouse),
						t_element *(*element_pressed)(void *win, struct s_element *elem, SDL_Event *ev, t_point_int *mouse),
						t_element *(*active_elem)(void *ptr_win, struct s_element *elem),
						t_element *(*deactive_elem)(void *ptr_win, struct s_element *elem),
						int (*draw)(void *win, struct s_element *elem))
{
	t_element *elem;

	elem = init_element(rect, path_tex, NULL, win, NULL, NULL, NULL, image_touch, element_pressed, NULL, draw);
	elem->active_elem = active_elem;
	elem->deactive_elem = deactive_elem;
	return (elem);
}
