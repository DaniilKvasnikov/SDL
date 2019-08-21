/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 17:13:58 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/21 17:14:33 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	text_render(void *win, void *elem)
{
	t_win		*ptr_win;
	t_element	*ptr_elem;
	
	ptr_win = (t_win *)win;
	ptr_elem = (t_element *)elem;
	if (ptr_elem->str != NULL)
		render_text(ptr_win, ptr_elem, ptr_elem->str);
	return (0);
}
