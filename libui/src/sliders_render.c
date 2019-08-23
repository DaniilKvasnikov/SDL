/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sliders_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 19:37:43 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/23 20:33:00 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	sliders_render(t_win *win, t_element *elem)
{
	t_win		*ptr_win;
	SDL_Rect	rect;

	ptr_win = (t_win *)win;
	if (elem->textures_count >= 2)
		texture_render(ptr_win, elem, elem->textures[0].tex);
	else if (elem->color)
	{
		SDL_Rect sdl_rect = t_rect_to_sdl_rect(&elem->rect);
		int	i = -1;
		while (++i < elem->rect.w)
		{
			SDL_SetRenderDrawColor(ptr_win->ren,
				elem->color->r * i / (float)elem->rect.w,
				elem->color->g * i / (float)elem->rect.w,
				elem->color->b * i / (float)elem->rect.w, SDL_ALPHA_OPAQUE);
			SDL_RenderDrawLine(ptr_win->ren, elem->rect.x + i, elem->rect.y, elem->rect.x + i, elem->rect.y + elem->rect.h);
		}
	}
	rect = (SDL_Rect){elem->rect.x - elem->rect.h / 4 + elem->rect.w * (*elem->float_par), elem->rect.y, elem->rect.h / 2, elem->rect.h};
	if (elem->textures_count >= 2)
		texture_render_rect(win, elem->textures[1].tex, NULL, &rect, SDL_FLIP_NONE);
	else if (elem->textures_count >= 1)
		texture_render_rect(win, elem->textures[0].tex, NULL, &rect, SDL_FLIP_NONE);
	return (0);
}
