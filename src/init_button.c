/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_button.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:59:08 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/12 09:00:17 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_button
	*init_button(t_rect rect, char *path_tex, t_win *win, char *str,
					int (*button_pressed)(void *win, void *but, SDL_Event *ev))
{
	t_button	*button;
	t_texture	*texture;

	if ((button = (t_button *)malloc(sizeof(t_button))) == NULL)
		return NULL;
	button->pos = (t_point){rect.x, rect.y};
	button->size = (t_point){rect.w, rect.h};
	if ((texture = get_texture_to_win(win, path_tex)) == NULL)
		exit(1);
	button->texture = texture->tex;
	button->button_pressed = button_pressed;
	button->str = str;
	return (button);
}
