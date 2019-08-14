/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 17:20:00 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/14 12:04:01 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	button_render(void *win, void *elem)
{
	t_win		*ptr_win;
	t_element	*ptr_elem;
	
	ptr_win = (t_win *)win;
	ptr_elem = (t_element *)elem;
	if (ptr_elem->textures_count >= 1)
		texture_render(ptr_win, ptr_elem, ptr_elem->textures[0].tex);
	if (ptr_elem->str != NULL)
		render_text(ptr_win, ptr_elem, ptr_elem->str);
	return (0);
}
