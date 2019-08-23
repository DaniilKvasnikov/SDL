/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_layer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 02:03:13 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/23 19:53:07 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*img_to_layer(void *ptr_win, t_element *elem)
{
	t_win		*win;
	t_rect		rect_win;

	win = (t_win *)ptr_win;
	rect_win = elem->rect;
	draw_text_to_target_tex(win, get_texture_to_win(win, elem->textures->name), 2, &rect_win, NULL);
	delete_element_in_win(win, elem);
	return (elem);
}
