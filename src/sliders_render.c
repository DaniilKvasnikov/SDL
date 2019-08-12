/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sliders_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 19:37:43 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/12 20:13:20 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	sliders_render(void *win, void *elem)
{
	t_win		*ptr_win;
	t_element	*ptr_elem;
	SDL_Rect	rect;

	ptr_win = (t_win *)win;
	ptr_elem = (t_element *)elem;
	texture_render(ptr_win, ptr_elem, ptr_elem->texture1);
	rect = (SDL_Rect){.x = ptr_elem->pos.x - ptr_elem->size.y / 4 + ptr_elem->size.x * ptr_elem->float_par, .y = ptr_elem->pos.y, .w = ptr_elem->size.y / 2, .h = ptr_elem->size.y};
	texture_render_rect(win, elem, ptr_elem->texture2, &rect);
	return (0);
}
