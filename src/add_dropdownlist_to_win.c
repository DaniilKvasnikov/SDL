/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_dropdownlist_to_win.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 12:20:00 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/15 12:22:34 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*add_dropdownlist_to_win(t_rect rect, char *path_tex, t_win *win, char **strs,
		int (*button_pressed)(void *win, void *but, SDL_Event *ev, t_point_int *mouse),
		int (*draw)(void *win, void *elem))
{
	int	i;
	t_element *element_new = add_element_to_win(win, init_element(rect, path_tex, NULL, win, NULL, button_pressed, NULL, NULL, draw));
	t_element *button;
	i = -1;
	while (strs[++i] != NULL)
	{
		button = init_element((t_rect){rect.x, rect.y + rect.h * (i + 1), rect.w, rect.h}, path_tex, NULL, win, strs[i], &element_touch, NULL, NULL, draw);
		button->parent = element_new;
		element_new->sub_group = add_group_e(element_new->sub_group, button, NULL);
	}
	return (element_new);
}
