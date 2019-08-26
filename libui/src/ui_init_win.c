/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_init_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyabaturin <ilyabaturin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 11:31:58 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/26 17:56:20 by ilyabaturin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_win
	*ui_init_win(char *name, t_rect rect, Uint32 flags,
		void (*mouse_muve_left)(t_win *win, t_point delta_mouse),
		void (*mouse_muve_scrole)(t_win *win, t_point delta_mouse))
{
	t_win *win;

	if (fined_win_by_name(name))
		ui_fotal_error(name, "win duplicate", __LINE__, __FILE__);
	win = (t_win *)ui_checkmalloc(malloc(sizeof(t_win)), name, __LINE__, __FILE__);
	win->win = ft_create_win(name, rect, flags);
	win->ren = ft_create_rend(win->win);
	win->name = name;
	win->full = rect;
	win->win_rect = (t_rect){0, 0, rect.w, rect.h};
	win->scale = 1;
	win->id = SDL_GetWindowID(win->win);
	win->elements = (t_element **)ui_checkmalloc(malloc(sizeof(t_element *)), "win->elements", __LINE__, __FILE__);
	win->elements[0] = NULL;
	win->active_elem = NULL;
	win->layers = (t_layer **)ui_checkmalloc(malloc(sizeof(t_layer *)), "win->layers", __LINE__, __FILE__);
	win->layers[0] = NULL;
	win->cur_layer = NULL;
	win->textures = (t_texture **)ui_checkmalloc(malloc(sizeof(t_texture *)), "win->textures", __LINE__, __FILE__);
	win->textures[0] = NULL;
	win->cur_texture = NULL;
	win->mouse_down = (t_point){0, 0};
	win->mouse_muve = (t_point){0, 0};
	win->mouse_muve_left = mouse_muve_left;
	win->mouse_muve_scrole = mouse_muve_scrole;
	return (win);
}
