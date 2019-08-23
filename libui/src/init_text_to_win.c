/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_text_to_win.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 17:07:26 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/23 20:33:00 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*init_text_to_win(t_rect rect, t_win *win, char *str,
		t_element *(*element_touch)(t_win *win, t_element *elem, SDL_Event *ev, t_point_int *mouse),
		t_element *(*button_pressed)(t_win *win, t_element *elem, SDL_Event *ev, t_point_int *mouse),
		int (*draw)(t_win *win, t_element *elem))
{
	t_element *elem;

	elem = init_element(rect, NULL, NULL, win, str, NULL, NULL, button_pressed, NULL, NULL, draw);
	return (elem);
}
