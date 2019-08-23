/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 17:20:00 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/23 20:33:00 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	button_render(t_win *win, t_element *elem)
{
	t_win		*ptr_win;
	
	ptr_win = (t_win *)win;
	if (elem->textures_count >= 1)
		texture_render(ptr_win, elem, elem->textures[0].tex);
	else
	{
		SDL_Rect sdl_rect = t_rect_to_sdl_rect(&elem->rect);
		 if (elem->color)
		{
			SDL_SetRenderDrawColor(ptr_win->ren, elem->color->r, elem->color->g, elem->color->b, SDL_ALPHA_OPAQUE);
		SDL_RenderFillRect(ptr_win->ren, &sdl_rect);
		}
		if (elem->color_border)
		{
			SDL_SetRenderDrawColor(ptr_win->ren, elem->color_border->r, elem->color_border->g, elem->color_border->b, SDL_ALPHA_OPAQUE);
			SDL_RenderDrawRect(ptr_win->ren, &sdl_rect);
		}
	}
	if (elem->sub_group != NULL)
		groupe_draw(ptr_win, elem->sub_group);
	if (elem->str != NULL)
		render_text(ptr_win, elem, elem->str);
	return (0);
}
