/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_group_to_elem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 18:01:34 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/23 20:34:57 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_group_e
	*add_group_to_elem(t_element *parent, t_element *elem,
				int (*gr_cheacker)(t_group_e *group, t_element *elem))
{
	t_group_e	*groupe;

	parent->sub_group = add_group_e(parent->sub_group, elem, gr_cheacker);
	elem->parent = parent;
	return (parent->sub_group);
}
