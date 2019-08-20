/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_mouse_fun.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 18:31:03 by gamerd            #+#    #+#             */
/*   Updated: 2019/08/20 18:26:58 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_sdl.h"

void
	draw_elem_to_tex(t_win *win, int num_layer)
{
	ft_putstr("draw_elem_to_tex\n");
	SDL_SetRenderTarget(win->ren, win->layers.textures[num_layer]);
	SDL_RenderDrawLine(win->ren, win->lst_mouse.x, win->lst_mouse.y, win->cur_mouse.x, win->cur_mouse.y);
	t_rect rect = (t_rect){win->lst_mouse.x, win->lst_mouse.y, win->cur_mouse.x - win->lst_mouse.x, win->cur_mouse.y - win->lst_mouse.y};
	SDL_Rect sdl_rect = t_rect_to_sdl_rect(&rect);
	SDL_RenderDrawRect(win->ren, &sdl_rect);
	flip_t_rect(&rect);
	SDL_SetRenderDrawColor(win->ren, 0, 255, 0, SDL_ALPHA_OPAQUE);
	draw_elipse(win->ren, rect, 1);
	SDL_SetRenderDrawColor(win->ren, 0, 0, 255, SDL_ALPHA_OPAQUE);
	draw_elipse(win->ren, rect, 0);
	SDL_SetRenderTarget(win->ren, NULL);
}

void
	ft_run_mouse_fun(t_mydata *mydata, SDL_Event *ev)
{
	t_win 		*win;
	t_point_int	point;

	win = ft_get_win_from_id(mydata, ev->window.windowID);
	if (win == NULL)
		return ;
	if(SDL_GetMouseState(&point.x, &point.y))
	{
		if (ev->type == SDL_MOUSEBUTTONDOWN)
			win_press_button(win, ev, point.x, point.y);
		if (win->active_element != NULL)
		{
			if (win->lst_mouse.x != win->cur_mouse.x || win->lst_mouse.y != win->cur_mouse.y)
				draw_elem_to_tex(win, 2);
			win->lst_mouse = (t_point_int){0, 0};
			win->cur_mouse = (t_point_int){0, 0};
			if (win->active_element->element_pressed != NULL)
				win->active_element->element_pressed(win, win->active_element, ev, &point);
			if (win->groupe != NULL && win->groupe->gr_cheacker != NULL)
				win->groupe->gr_cheacker(win->groupe, win->active_element);
		}
		else
		{
			if (ev->type == SDL_MOUSEBUTTONDOWN)
				win->lst_mouse = point;
			win->cur_mouse = point;
		}
	}
	if (ev->type == SDL_MOUSEBUTTONUP)
	{
		if (win->lst_mouse.x != win->cur_mouse.x || win->lst_mouse.y != win->cur_mouse.y)
			draw_elem_to_tex(win, 2);
		win->lst_mouse = (t_point_int){0, 0};
		win->cur_mouse = (t_point_int){0, 0};
	}
}