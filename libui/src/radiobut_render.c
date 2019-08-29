/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radiobut_render.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyabaturin <ilyabaturin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 08:43:49 by ilyabaturin       #+#    #+#             */
/*   Updated: 2019/08/29 09:21:25 by ilyabaturin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int
	radiobut_render(t_element *elem, t_win *win)
{
	t_texture			*texture;
	SDL_Rect			sdl_rect;
	SDL_RendererFlip	flip;
	t_rect				rect;
	int			i;
	if (*elem->active == 0)
		return (0);
	if ((texture = get_texture_by_name(win, elem->texture_name)) != NULL)
		texture_render(win, elem, texture->tex);
	i = -1;
	while (elem->draw_sub_groupe[++i])
		if (elem->draw_sub_groupe[i]->draw)
			elem->draw_sub_groupe[i]->draw(elem->draw_sub_groupe[i], win);
	i = -1;
	while (elem->sub_groupe[++i])
		if (*elem->sub_groupe[i]->active && elem->sub_groupe[i]->draw)
			elem->sub_groupe[i]->draw(elem->sub_groupe[i], win);
	int			*status;
	status = get_param_by_name(elem->params, "status");
	t_texture *box;
	if (status != NULL)
	{
		if (*status == 1)
			box = (t_texture *)get_param_by_name(elem->params, "active");
		else
			box = (t_texture *)get_param_by_name(elem->params, "deactive");
		if (box != NULL)
		{
			rect = (t_rect){elem->rect.x, elem->rect.y, elem->rect.h, elem->rect.h};
			flip = flip_t_rect(&rect);
			sdl_rect = t_rect_to_sdl_rect(&rect);
			texture_render_rect(win, box->tex, NULL, &sdl_rect, flip);
		}
	}
	return (1);
}
