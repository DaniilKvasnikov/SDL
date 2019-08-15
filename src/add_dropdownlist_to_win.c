/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_dropdownlist_to_win.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 12:20:00 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/15 09:25:59 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*add_dropdownlist_to_win(t_rect rect, char *path_tex, t_win *win, char *str,
		int (*button_pressed)(void *win, void *but, SDL_Event *ev, t_point_int *mouse),
		int (*draw)(void *win, void *elem))
{
	t_element *element_new = add_element_to_win(win, init_element(rect, path_tex, NULL, win, NULL, button_pressed, NULL, NULL, draw));
	t_element *button;
	button = init_element((t_rect){rect.x, rect.y + rect.h * 1, rect.w, rect.h}, path_tex, NULL, win, str, button_pressed, NULL, NULL, draw);
	button->parent = element_new;
	element_new->sub_group = add_group_e(element_new->sub_group, button, NULL);
	button = init_element((t_rect){rect.x, rect.y + rect.h * 2, rect.w, rect.h}, path_tex, NULL, win, str, button_pressed, NULL, NULL, draw);
	button->parent = element_new;
	element_new->sub_group = add_group_e(element_new->sub_group, button, NULL);
	return (element_new);
}
