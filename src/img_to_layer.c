/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_layer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 02:03:13 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/18 02:59:32 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*img_to_layer(void *ptr_win, void *but)
{
	t_win		*win;
	t_element	*elem;
	t_rect		rect_win;

	win = (t_win *)ptr_win;
	elem = (t_element *)but;
	rect_win = (t_rect){elem->pos.x, elem->pos.y, elem->size.x, elem->size.y};
	draw_text_to_target_tex(win, get_texture_to_win(win, elem->textures->name), 0, &rect_win, NULL);
	delete_element_in_win(win, (t_element *)but);
	return ((t_element *)but);
}
