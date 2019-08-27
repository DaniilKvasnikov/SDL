/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scroll_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyabaturin <ilyabaturin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 10:32:18 by ilyabaturin       #+#    #+#             */
/*   Updated: 2019/08/27 10:49:07 by ilyabaturin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	scroll_draw(t_element *elem, t_win *win)
{
	t_texture			*texture;
	SDL_Rect			sdl_rect;
	SDL_RendererFlip	flip;
	t_rect				rect;

	int			i;
	if (elem->active == 0)
		return (0);
	if ((texture = get_texture_by_name(win, elem->texture_name)) != NULL)
		texture_render(win, elem, texture->tex);
	if ((texture = get_texture_by_name(win, "box")) != NULL)
	{
		float *f = get_param_by_name(elem->params, "par");
		if (f != NULL)
		{
			rect = (t_rect){elem->rect.x + (*f) * (elem->rect.w - elem->rect.h / 2),
							elem->rect.y, elem->rect.h / 2, elem->rect.h};
			flip = flip_t_rect(&rect);
			sdl_rect = t_rect_to_sdl_rect(&rect);
			texture_render_rect(win, texture->tex, NULL, &sdl_rect, flip);
		}
	}
	i = -1;
	while (elem->draw_sub_groupe[++i])
		if (elem->draw_sub_groupe[i]->draw)
			elem->draw_sub_groupe[i]->draw(elem->draw_sub_groupe[i], win);
	i = -1;
	while (elem->sub_groupe[++i])
		if (elem->sub_groupe[i]->active && elem->sub_groupe[i]->draw)
			elem->sub_groupe[i]->draw(elem->sub_groupe[i], win);
	return (1);
}
