/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_init_element.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyabaturin <ilyabaturin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 13:37:26 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/09/04 09:04:35 by ilyabaturin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*ui_init_element(int *active, char *name, t_rect rect, t_win *win, char *texture_name,
					t_element *parent, t_color *color, char *str, t_ttf *ttf,
					int (*draw)(t_element *elem, t_win *win),
					t_element *(*mouse_down)(t_element *elem, SDL_Event *ev),
					t_element *(*mouse_move)(t_element *elem, SDL_Event *ev),
					t_element *(*mouse_up)(t_element *elem, SDL_Event *ev),
					int (*keyboard_down)(t_element *elem, SDL_Event *ev),
					t_element *(*active_other)(t_element *elem, t_element *new))
{
	t_element	*elem;

	if (fined_element_by_name(win, name))
		ui_fotal_error(name, "element duplicate", __LINE__, __FILE__);
	elem = (t_element *)ui_checkmalloc(malloc(sizeof(t_element)), "elem init", __LINE__, __FILE__);
	elem->active = active;
	elem->name = ft_strdup(name);
	elem->rect = rect;
	elem->win = win;
	elem->last_delta_mouse = (t_point){0, 0};
	elem->draw_sub_groupe = (t_element **)ui_checkmalloc(malloc(sizeof(t_element *)), "draw_sub_groupe", __LINE__, __FILE__);
	elem->draw_sub_groupe[0] = NULL;
	elem->sub_groupe = (t_element **)ui_checkmalloc(malloc(sizeof(t_element *)), "sub_groupe", __LINE__, __FILE__);
	elem->sub_groupe[0] = NULL;
	elem->parent = parent;
	elem->color = color;
	elem->str = str;
	elem->ttf = ttf;
	elem->params = (t_param **)ui_checkmalloc(malloc(sizeof(t_param *)), "params", __LINE__, __FILE__);
	elem->params[0] = NULL;
	elem->texture_name = texture_name;
	elem->draw = draw;
	elem->mouse_down = mouse_down;
	elem->mouse_move = mouse_move;
	elem->mouse_up = mouse_up;
	elem->keyboard_down = keyboard_down;
	elem->active_other = active_other;
	return (elem);
}
