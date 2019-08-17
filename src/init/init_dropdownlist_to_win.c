/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dropdownlist_to_win.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 12:20:00 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/17 11:41:38 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*init_dropdownlist_to_win(t_rect rect, char *path_tex, t_win *win, char **strs, char *str, t_point_int delta,
		t_element *(*button_pressed)(void *win, void *but, SDL_Event *ev, t_point_int *mouse),
		t_element *(*active_elem)(void *ptr_win, void *buf),
		t_element *(*active_sub_elem)(void *ptr_win, void *buf),
		int (*draw)(void *win, void *elem),
		int (*draw_elem)(void *win, void *elem))
{
	int	i;
	t_element *element_new = init_element(rect, path_tex, NULL, win, str, button_pressed, NULL, NULL, draw);
	element_new->active_elem = active_elem;
	t_element *button;
	i = -1;
	while (strs[++i] != NULL)
	{
		button = init_element((t_rect){rect.x + delta.x, rect.y + delta.y + rect.h * i, rect.w, rect.h}, path_tex, NULL, win, strs[i], &element_touch, NULL, NULL, draw_elem);
		button->active_elem = active_sub_elem;
		button->parent = element_new;
		element_new->sub_group = add_group_e(element_new->sub_group, button, NULL);
	}
	return (element_new);
}
