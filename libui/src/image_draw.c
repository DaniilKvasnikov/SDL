/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 13:56:43 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 16:41:32 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	image_draw(t_element *elem, t_win *win)
{
	t_texture	*texture;
	int			i;
	if (elem->active == 0)
		return (0);
	if ((texture = get_texture_by_name(win, elem->texture_name)) != NULL)
		texture_render(win, elem, texture->tex);
	i = -1;
	while (elem->draw_sub_groupe[++i])
		if (elem->draw_sub_groupe[i]->draw)
			elem->draw_sub_groupe[i]->draw(elem->draw_sub_groupe[i], win);
	i = -1;
	while (elem->sub_groupe[++i])
		if (elem->sub_groupe[i]->active && elem->sub_groupe[i]->draw)
			elem->sub_groupe[i]->draw(elem->sub_groupe[i], win);
	return (1);
}
