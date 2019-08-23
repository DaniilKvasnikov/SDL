/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sliders_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 19:37:43 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/23 16:20:44 by rrhaenys         ###   ########.fr       */
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
	if (ptr_elem->textures_count >= 2)
		texture_render(ptr_win, ptr_elem, ptr_elem->textures[0].tex);
	else if (ptr_elem->color)
	{
		SDL_Rect sdl_rect = t_rect_to_sdl_rect(&ptr_elem->rect);
		int	i = -1;
		while (++i < ptr_elem->rect.w)
		{
			SDL_SetRenderDrawColor(ptr_win->ren,
				ptr_elem->color->r * i / (float)ptr_elem->rect.w,
				ptr_elem->color->g * i / (float)ptr_elem->rect.w,
				ptr_elem->color->b * i / (float)ptr_elem->rect.w, SDL_ALPHA_OPAQUE);
			SDL_RenderDrawLine(ptr_win->ren, ptr_elem->rect.x + i, ptr_elem->rect.y, ptr_elem->rect.x + i, ptr_elem->rect.y + ptr_elem->rect.h);
		}
	}
	rect = (SDL_Rect){ptr_elem->rect.x - ptr_elem->rect.h / 4 + ptr_elem->rect.w * (*ptr_elem->float_par), ptr_elem->rect.y, ptr_elem->rect.h / 2, ptr_elem->rect.h};
	if (ptr_elem->textures_count >= 2)
		texture_render_rect(win, ptr_elem->textures[1].tex, NULL, &rect, SDL_FLIP_NONE);
	else if (ptr_elem->textures_count >= 1)
		texture_render_rect(win, ptr_elem->textures[0].tex, NULL, &rect, SDL_FLIP_NONE);
	return (0);
}
