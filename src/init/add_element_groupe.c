/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_element_groupe.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 16:19:01 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 16:19:38 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*add_element_groupe(t_element *groupe, t_element *elem)
{
	int			count;
	int			i;
	t_element	**elems;

	count = ui_element_in_groupe(groupe->sub_groupe);
	elems = (t_element **)ui_checkmalloc(malloc(sizeof(t_element *) * (count + 1)), "add new elem");
	i = -1;
	while (groupe->sub_groupe[++i] != NULL)
		elems[i] = groupe->sub_groupe[i];
	elem->parent = groupe;
	elem->rect.x += elem->parent->rect.x;
	elem->rect.y += elem->parent->rect.y;
	elems[i] = elem;
	elems[i + 1] = NULL;
	free(groupe->sub_groupe);
	groupe->sub_groupe = elems;
	return (elem);
}
