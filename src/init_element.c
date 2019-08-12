/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:59:08 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/12 17:14:34 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_element
	*init_element(t_rect rect, char *path_tex1, char *path_tex2, t_win *win, char *str,
					int (*element_touch)(void *win, void *but, SDL_Event *ev),
					int (*element_pressed)(void *win, void *but, SDL_Event *ev),
					int (*draw)(void *win, void *elem))
{
	t_element	*button;
	t_texture	*texture1;
	t_texture	*texture2;

	if ((button = (t_element *)malloc(sizeof(t_element))) == NULL)
		return NULL;
	button->pos = (t_point){rect.x, rect.y};
	button->size = (t_point){rect.w, rect.h};
	if (path_tex1 != NULL)
	{
		if ((texture1 = get_texture_to_win(win, path_tex1)) == NULL)
			exit(1);
		button->texture1 = texture1->tex;
	}
	else
		button->texture1 = NULL;
	if (path_tex2 != NULL)
	{
		if ((texture2 = get_texture_to_win(win, path_tex2)) == NULL)
			exit(1);
		button->texture2 = texture2->tex;
	}
	else
		button->texture2 = NULL;
	button->num_tex = 0;
	button->element_touch = element_touch;
	button->element_pressed = element_pressed;
	button->str = str;
	button->draw = draw;
	return (button);
}
