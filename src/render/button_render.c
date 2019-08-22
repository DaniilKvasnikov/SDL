/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 17:20:00 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/22 15:45:26 by rrhaenys         ###   ########.fr       */
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
	else
	{
		SDL_Rect sdl_rect = t_rect_to_sdl_rect(&ptr_elem->rect);
		 if (ptr_elem->color)
		{
			SDL_SetRenderDrawColor(ptr_win->ren, ptr_elem->color->r, ptr_elem->color->g, ptr_elem->color->b, SDL_ALPHA_OPAQUE);
		SDL_RenderFillRect(ptr_win->ren, &sdl_rect);
		}
		if (ptr_elem->color_border)
		{
			SDL_SetRenderDrawColor(ptr_win->ren, ptr_elem->color_border->r, ptr_elem->color_border->g, ptr_elem->color_border->b, SDL_ALPHA_OPAQUE);
			SDL_RenderDrawRect(ptr_win->ren, &sdl_rect);
		}
	}
	if (ptr_elem->sub_group != NULL)
		groupe_draw(ptr_win, ptr_elem->sub_group);
	if (ptr_elem->str != NULL)
		render_text(ptr_win, ptr_elem, ptr_elem->str);
	return (0);
}
