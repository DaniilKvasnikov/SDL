/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_text_to_win.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 17:07:26 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/22 14:18:53 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*init_text_to_win(t_rect rect, t_win *win, char *str,
		t_element *(*element_touch)(void *win, void *but, SDL_Event *ev, t_point_int *mouse),
		t_element *(*button_pressed)(void *win, void *but, SDL_Event *ev, t_point_int *mouse),
		int (*draw)(void *win, void *elem))
{
	t_element *elem;

	elem = init_element(rect, NULL, NULL, win, str, NULL, NULL, button_pressed, NULL, NULL, draw);
	return (elem);
}
