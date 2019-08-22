/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   progressbar_render.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 08:02:23 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/22 15:19:29 by rrhaenys         ###   ########.fr       */
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
	src = t_rect_to_sdl_rect(&ptr_elem->rect);
	if (ptr_elem->textures_count >= 2)
	{
		SDL_QueryTexture(ptr_elem->textures[1].tex, NULL, NULL, &w, &h);
		dst = (SDL_Rect){0, 0, w * (*ptr_elem->float_par), h};
		texture_render_rect(win, elem, &dst, &src, SDL_FLIP_NONE);
	}
	return (0);
}
