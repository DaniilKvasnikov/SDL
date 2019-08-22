/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:59:08 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/22 15:43:10 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*init_element(t_rect rect, char *path_tex1, char *path_tex2, t_win *win,
					char *str, int *int_par, float *float_par,
					t_element *(*element_touch)(void *win, void *but, SDL_Event *ev, t_point_int *mouse),
					t_element *(*element_pressed)(void *win, void *but, SDL_Event *ev, t_point_int *mouse),
					int (*keyboard_press)(void *win, void *but, char *char_input),
					int (*draw)(void *win, void *elem))
{
	t_element	*element;
	t_texture	*texture1;
	t_texture	*texture2;

	if ((element = (t_element *)malloc(sizeof(t_element))) == NULL)
		return NULL;
	element->rect = rect;
	element->textures_count = 0;
	if (path_tex1 != NULL)
	{
		if ((texture1 = get_texture_to_win(win, path_tex1)) == NULL)
			exit(1);
		element = add_texture_to_elem(element, texture1);
	}
	if (path_tex2 != NULL)
	{
		if ((texture2 = get_texture_to_win(win, path_tex2)) == NULL)
			exit(1);
		element = add_texture_to_elem(element, texture2);
	}
	element->element_touch = element_touch;
	element->element_pressed = element_pressed;
	element->keyboard_press = keyboard_press;
	element->str = str;
	element->draw = draw;
	element->int_par = int_par;
	element->float_par = float_par;
	element->sub_group = NULL;
	element->parent = NULL;
	element->active_elem = NULL;
	element->deactive_elem = NULL;
	element->type = 0;
	element->color = NULL;
	element->color_border = NULL;
	return (element);
}
