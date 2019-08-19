/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 17:20:00 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/19 09:27:05 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	image_render(void *win, void *elem)
{
	t_win		*ptr_win;
	t_element	*ptr_elem;
	
	ptr_win = (t_win *)win;
	ptr_elem = (t_element *)elem;
	if (ptr_elem->textures_count >= 1)
		texture_render(ptr_win, ptr_elem, ptr_elem->textures[0].tex);
	if (ptr_elem->sub_group != NULL)
		groupe_draw(ptr_win, ptr_elem->sub_group);
	if (ptr_elem->str != NULL)
		render_text(ptr_win, ptr_elem, ptr_elem->str);
	if (ptr_win->active_element == ptr_elem)
	{
		SDL_SetRenderDrawColor(ptr_win->ren, 255, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_Rect sdl_rec = (SDL_Rect){ptr_elem->pos.x, ptr_elem->pos.y,
										ptr_elem->size.x, ptr_elem->size.y};
		SDL_RenderDrawRect(ptr_win->ren, &sdl_rec);
		sdl_rec = (SDL_Rect){ptr_elem->pos.x, ptr_elem->pos.y,
										10, 10};
		SDL_RenderDrawRect(ptr_win->ren, &sdl_rec);
		sdl_rec = (SDL_Rect){ptr_elem->pos.x + ptr_elem->size.x - 10, ptr_elem->pos.y + ptr_elem->size.y - 10,
										10, 10};
		SDL_RenderDrawRect(ptr_win->ren, &sdl_rec);
	}
	return (0);
}
