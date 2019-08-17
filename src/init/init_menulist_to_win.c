/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_menulist_to_win.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 08:22:13 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/17 03:39:13 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*init_menulist_to_win(t_rect rect, char *path_tex, t_win *win, char **strs,
		t_element *(*button_pressed)(void *win, void *but, SDL_Event *ev, t_point_int *mouse),
		t_element *(*active_elem)(void *ptr_win, void *buf),
		int (*draw)(void *win, void *elem),
		int (*draw_elem)(void *win, void *elem))
{
	int	i;
	t_element *element_new = init_element(rect, path_tex, NULL, win, "MENU", button_pressed, NULL, NULL, draw);
	element_new->active_elem = active_elem;
	t_element *button;
	i = -1;
	while (strs[++i] != NULL)
	{
		button = init_dropdownlist_to_win((t_rect){rect.x + rect.w * i, rect.y + rect.h, rect.w, rect.h}, path_tex, win, strs, strs[i], button_pressed, active_elem, active_elem, draw, draw_elem);
		button->parent = element_new;
		element_new->sub_group = add_group_e(element_new->sub_group, button, NULL);
	}
	return (element_new);
}
