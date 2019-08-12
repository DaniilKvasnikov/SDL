/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sliders_to_win.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 19:30:02 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/12 20:02:04 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*add_sliders_to_win(t_rect rect, char *path_tex1, char *path_tex2, t_win *win,
		int (*element_touch)(void *win, void *but, SDL_Event *ev),
		int (*element_pressed)(void *win, void *but, SDL_Event *ev, t_point_int *mouse),
		int (*draw)(void *win, void *elem))
{
	return (add_element_to_win(win, init_element(rect, path_tex1, path_tex2, win, NULL, element_touch, element_pressed, draw)));
}

