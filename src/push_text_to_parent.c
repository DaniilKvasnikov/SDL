/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_text_to_parent.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 09:15:18 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/15 09:17:36 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	push_text_to_parent(void *win, void *but, SDL_Event *ev)
{
	t_element *elem;

	elem = (t_element *)but;
	if (elem->parent != NULL)
		((t_element *)elem->parent)->str = elem->str;
	return (1);
}
