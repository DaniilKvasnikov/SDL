/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_init_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 11:31:58 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 12:37:39 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_win
	*ui_init_win(char *name, t_rect rect, Uint32 flags,
		void (*win_fun)(t_win *win, SDL_Event *ev))
{
	t_win *win;

	if (fined_win_by_name(name))
		ui_fotal_error(name, "win duplicate");
	win = (t_win *)ui_checkmalloc(malloc(sizeof(t_win)), name);
	win->win = ft_create_win(name, rect, flags);
	win->ren = ft_create_rend(win->win);
	win->name = name;
	win->rect = rect;
	win->id = SDL_GetWindowID(win->win);
	win->elements = (t_element **)ui_checkmalloc(malloc(sizeof(t_element *)), "win->elements");
	win->elements[0] = NULL;
	win->active_elem = NULL;
	win->layers = (t_layer **)ui_checkmalloc(malloc(sizeof(t_layer *)), "win->layers");
	win->layers[0] = NULL;
	win->cur_layer = NULL;
	win->textures = (t_texture **)ui_checkmalloc(malloc(sizeof(t_texture *)), "win->textures");
	win->textures[0] = NULL;
	win->cur_texture = NULL;
	win->mouse_down = (t_point){0, 0};
	win->mouse_muve = (t_point){0, 0};
	win->win_fun = win_fun;
	return (win);
}
