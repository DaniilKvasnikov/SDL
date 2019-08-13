/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_textline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 08:48:00 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/13 08:51:25 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*add_textline(t_rect rect, char *path_tex1, t_win *win,
		int (*element_touch)(void *win, void *but, SDL_Event *ev),
		int (*keyboard_press)(void *win, void *but, SDL_Event *ev),
		int (*draw)(void *win, void *elem))
{
	return (add_element_to_win(win, init_element(rect, path_tex1, NULL, win, NULL, element_touch, NULL, keyboard_press, draw)));
}
