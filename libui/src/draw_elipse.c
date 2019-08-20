/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_elipse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 18:22:01 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/20 18:22:14 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

static void
	draw_elipse_full(SDL_Renderer *ren, t_rect field)
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


static void
	draw_elipse_sin(SDL_Renderer *ren, t_rect field)
{
	int		w = field.w / 2;
	int		h = field.h / 2;
	if (w == 0 || h == 0)
		return ;
	int		r = field.w / 2;
	double	wh = (double)h / (double)w;
	int		cx = field.x + field.w / 2;
	int		cy = field.y + field.h / 2;
	double	len = M_PI * (w + h);
	double step = 2.0f * M_PI / len;
	double theta = -step;
	while ((theta = theta + step) < 2.0f * M_PI)
	{
		double x = cx + r * cos(theta);
		double y = cy - wh * r * sin(theta);
		SDL_RenderDrawPoint(ren, x, y);
	}
}


void
	draw_elipse(SDL_Renderer *ren, t_rect field, int full)
{
	if (full == 1)
		draw_elipse_full(ren, field);
	if (full == 0)
		draw_elipse_sin(ren, field);
}
