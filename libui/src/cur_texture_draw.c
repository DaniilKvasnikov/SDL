/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cur_texture_draw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 11:11:30 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/26 11:14:46 by rrhaenys         ###   ########.fr       */
/*                                                                            SDL_QueryTexture(source, NULL, NULL, &w, &h);*/
/* ************************************************************************** */

#include "ft_sdl.h"

static t_point
	recalc(t_point *old, t_rect *rect, float delta)
{
	return ((t_point){
		(old->x - rect->x) / delta,
		(old->y - rect->y) / delta
	});
}

void
	cur_texture_draw(t_win *win, int num_layer)
{
	SDL_RendererFlip	flip;
	int					w;
	int					h;
	t_point	mouse_down = recalc(&win->mouse_down, &win->win_rect, win->scale);
	SDL_SetRenderTarget(win->ren, win->layers[num_layer]->texture);
	if (win->sdl_data->draw_type == DRAW_TEXTURE && win->cur_texture)
	{
		SDL_QueryTexture(win->cur_texture->tex, NULL, NULL, &w, &h);
		t_rect rect = (t_rect){mouse_down.x - w / 2, mouse_down.y - h / 2, w, h};
		flip = flip_t_rect(&rect);
		SDL_Rect sdl_rect = t_rect_to_sdl_rect(&rect);
		texture_render_rect(win, win->cur_texture->tex, NULL, &sdl_rect, flip);
	}
	SDL_SetRenderTarget(win->ren, NULL);
}
