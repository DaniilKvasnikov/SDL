/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   progressbar_render.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 08:02:23 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/14 12:03:34 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	progressbar_render(void *win, void *elem)
{
	t_win		*ptr_win;
	t_element	*ptr_elem;
	SDL_Rect	src;
	SDL_Rect	dst;
	int			w;
	int			h;

	ptr_win = (t_win *)win;
	ptr_elem = (t_element *)elem;
	if (ptr_elem->textures_count >= 1)
		texture_render(ptr_win, ptr_elem, ptr_elem->textures[0].tex);
	src = (SDL_Rect){ptr_elem->pos.x, ptr_elem->pos.y, ptr_elem->size.x * ptr_elem->float_par, ptr_elem->size.y};
	if (ptr_elem->textures_count >= 2)
	{
		SDL_QueryTexture(ptr_elem->textures[1].tex, NULL, NULL, &w, &h);
		dst = (SDL_Rect){0, 0, w * ptr_elem->float_par, h};
		texture_render_rect(win, elem, ptr_elem->textures[1].tex, &dst, &src);
	}
	return (0);
}
