/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   progressbar_render.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 08:02:23 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/23 20:33:00 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	progressbar_render(t_win *win, t_element *elem)
{
	t_win		*ptr_win;
	SDL_Rect	src;
	SDL_Rect	dst;
	int			w;
	int			h;

	ptr_win = (t_win *)win;
	if (elem->textures_count >= 1)
		texture_render(ptr_win, elem, elem->textures[0].tex);
	src = t_rect_to_sdl_rect(&elem->rect);
	if (elem->textures_count >= 2)
	{
		SDL_QueryTexture(elem->textures[1].tex, NULL, NULL, &w, &h);
		dst = (SDL_Rect){0, 0, w * (*elem->float_par), h};
		texture_render_rect(win, elem->textures[1].tex, &dst, &src, SDL_FLIP_NONE);
	}
	return (0);
}
