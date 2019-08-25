/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_element_to_groupe.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 15:29:39 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 15:45:10 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*add_element_draw_to_win(t_element *groupe, t_element *elem)
{
	int			count;
	int			i;
	t_element	**elems;

	count = ui_element_in_groupe(groupe->draw_sub_groupe);
	elems = (t_element **)ui_checkmalloc(malloc(sizeof(t_element *) * (count + 1)), "add new elem");
	i = -1;
	while (groupe->draw_sub_groupe[++i] != NULL)
		elems[i] = groupe->draw_sub_groupe[i];
	elem->parent = groupe;
	elem->rect.x += elem->parent->rect.x;
	elem->rect.y += elem->parent->rect.y;
	elems[i] = elem;
	elems[i + 1] = NULL;
	free(groupe->draw_sub_groupe);
	groupe->draw_sub_groupe = elems;
	return (elem);
}
