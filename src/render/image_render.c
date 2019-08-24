/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 17:20:00 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/24 14:55:55 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

static void
	borders(t_win *win, t_element *elem)
{
		int	delta_x;
		int	delta_y;

		delta_x = 10 * (1 - 2 * (elem->rect.w < 0));
		delta_y = 10 * (1 - 2 * (elem->rect.h < 0));
		SDL_SetRenderDrawColor(win->ren, win->mydata->active_border.r, win->mydata->active_border.g, win->mydata->active_border.b, SDL_ALPHA_OPAQUE);
		SDL_Rect sdl_rec = t_rect_to_sdl_rect(&elem->rect);
		SDL_RenderDrawRect(win->ren, &sdl_rec);
		sdl_rec = t_rect_to_sdl_rect(&(t_rect){elem->rect.x, elem->rect.y, delta_x, delta_y});
		SDL_RenderDrawRect(win->ren, &sdl_rec);
		sdl_rec = t_rect_to_sdl_rect(&(t_rect){elem->rect.x + elem->rect.w - delta_x, elem->rect.y + elem->rect.h - delta_y, delta_x, delta_y});
		SDL_RenderDrawRect(win->ren, &sdl_rec);
}

int
	image_render(t_win *win, void *elem)
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
		borders(win, ptr_elem);
	return (0);
}
