/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkbox_render.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 20:17:54 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/23 09:58:34 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	checkbox_render(void *win, void *elem)
{
	t_win		*ptr_win;
	t_element	*ptr_elem;

	ptr_win = (t_win *)win;
	ptr_elem = (t_element *)elem;
	if (*ptr_elem->int_par == 0 && ptr_elem->textures_count >= 1)
		texture_render(ptr_win, ptr_elem, ptr_elem->textures[0].tex);
	else if (*ptr_elem->int_par == 1 && ptr_elem->textures_count >= 2)
		texture_render(ptr_win, ptr_elem, ptr_elem->textures[1].tex);
	if (ptr_elem->str != NULL)
		render_text(ptr_win, ptr_elem, ptr_elem->str);
	if (*ptr_elem->int_par == 1 && ptr_elem->sub_group != NULL)
		groupe_draw(ptr_win, ptr_elem->sub_group);
	return (0);
}
