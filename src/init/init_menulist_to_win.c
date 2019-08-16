/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_menulist_to_win.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 08:22:13 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/16 09:06:04 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*init_menulist_to_win(t_rect rect, char *path_tex, t_win *win, char **strs,
		t_element *(*button_pressed)(void *win, void *but, SDL_Event *ev, t_point_int *mouse),
		int (*draw)(void *win, void *elem),
		int (*draw_elem)(void *win, void *elem))
{
	int	i;
	t_element *element_new = init_element(rect, path_tex, NULL, win, "MENU", button_pressed, NULL, NULL, draw);
	t_element *button;
	i = -1;
	while (strs[++i] != NULL)
	{
		button = init_dropdownlist_to_win((t_rect){rect.x, rect.y + rect.h * (i + 1), rect.w, rect.h}, path_tex, win, strs, "sub", button_pressed, draw, draw_elem);
		button->parent = element_new;
		element_new->sub_group = add_group_e(element_new->sub_group, button, NULL);
	}
	return (element_new);
}
