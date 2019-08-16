/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_button_to_win.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 08:57:13 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/16 08:35:15 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*init_button_to_win(t_rect rect, char *path_tex, t_win *win, char *str,
		t_element *(*button_pressed)(void *win, void *but, SDL_Event *ev, t_point_int *mouse),
		int (*draw)(void *win, void *elem))
{
	return (init_element(rect, path_tex, NULL, win, str, button_pressed, NULL, NULL, draw));
}
