/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:10:34 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/20 17:23:02 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

static void
	draw_elipse(SDL_Renderer *ren, t_rect field)
{
	int		x;
	int		y;
	int		r;
	int		rr;
	int		x0;
	int		h;
	int		w;
	int		hh;
	int		ww;
	int		wwhh;

	h = field.h / 2;
	w = field.w / 2;
	hh = h * h;
	ww = w * w;
	wwhh = ww * hh;
	x = -1;
	r = ft_max_int(field.w, field.h) / 2;
	if (r == 0)
		return ;
	rr = r * r;
	x = -w - 1;
	while (++x <= w)
	{
		y = -h - 1;
		while (++y <= h)
		{
			if (x * x * hh + y * y * ww <= wwhh)
				SDL_RenderDrawPoint(ren, field.x + field.w / 2 + x, field.y + field.h / 2 + y);
		}
	}
}

void
	render_wins(t_mydata *mydata)
{
	int			i;
	int			j;
	SDL_Rect	rect;
	t_win		*win;
	
	i = -1;
	while (++i < mydata->win_count)
	{
		win = mydata->wins[i];
		SDL_RenderClear( win->ren );
		j = -1;
		while (++j < win->layers.count)
			texture_render_rect(win, win->layers.textures[j], NULL, NULL, SDL_FLIP_NONE);
		j = -1;
		while (++j < win->element_count)
			if (win->elements[j]->draw != NULL)
				win->elements[j]->draw(win, win->elements[j]);
		SDL_SetRenderDrawColor(win->ren, 255, 255, 255, SDL_ALPHA_OPAQUE);
		if (win->cur_mouse.x != win->lst_mouse.x ||
			win->cur_mouse.y != win->lst_mouse.y)
		SDL_RenderDrawLine(win->ren, win->lst_mouse.x, win->lst_mouse.y, win->cur_mouse.x, win->cur_mouse.y);
		t_rect rect = (t_rect){win->lst_mouse.x, win->lst_mouse.y, win->cur_mouse.x - win->lst_mouse.x, win->cur_mouse.y - win->lst_mouse.y};
		SDL_Rect sdl_rect = t_rect_to_sdl_rect(&rect);
		SDL_RenderDrawRect(win->ren, &sdl_rect);
		flip_t_rect(&rect);
		draw_elipse(win->ren, rect);
		SDL_RenderPresent( win->ren );
	}
}
