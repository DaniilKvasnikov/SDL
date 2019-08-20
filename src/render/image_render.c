/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 17:20:00 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/20 16:43:30 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

static void
	borders(SDL_Renderer *ren, t_element *elem)
{
		int	delta_x;
		int	delta_y;

		delta_x = 10 * (1 - 2 * (elem->size.x < 0));
		delta_y = 10 * (1 - 2 * (elem->size.y < 0));
		SDL_SetRenderDrawColor(ren, 255, 255, 0, SDL_ALPHA_OPAQUE);
		SDL_Rect sdl_rec = t_rect_to_sdl_rect(&(t_rect){elem->pos.x, elem->pos.y, elem->size.x, elem->size.y});
		SDL_RenderDrawRect(ren, &sdl_rec);
		sdl_rec = t_rect_to_sdl_rect(&(t_rect){elem->pos.x, elem->pos.y, delta_x, delta_y});
		SDL_RenderDrawRect(ren, &sdl_rec);
		sdl_rec = t_rect_to_sdl_rect(&(t_rect){elem->pos.x + elem->size.x - delta_x, elem->pos.y + elem->size.y - delta_y, delta_x, delta_y});
		SDL_RenderDrawRect(ren, &sdl_rec);
}

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
		borders(((t_win *)win)->ren, ptr_elem);
	return (0);
}
