/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_text_to_parent.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 09:15:18 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/23 19:24:18 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

t_element
	*push_text_to_parent(void *win, t_element *elem, SDL_Event *ev)
{
	if (elem->parent != NULL)
		((t_element *)elem->parent)->str = elem->str;
	return (elem);
}
