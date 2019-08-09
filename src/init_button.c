/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_button.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:59:08 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/09 16:25:32 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

t_button
	*init_button(SDL_Rect rect, char *path_tex, t_win *win,
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
	return (button);
}

void
	add_button_to_win(SDL_Rect rect, char *path_tex, t_win *win,
		int (*button_pressed)(void *win, void *but, SDL_Event *ev))
{
	t_button	**ptr;
	int			i;

	win->buttons_count++;
	if (win->buttons_count == 1)
	{
		win->buttons = (t_button **)malloc(sizeof(t_button *));
		win->buttons[0] = init_button(rect, path_tex, win, button_pressed);
	}
	else
	{
		ptr = win->buttons;
		win->buttons = (t_button **)malloc(sizeof(t_button *) * win->buttons_count);
		i = -1;
		while (++i < (win->buttons_count - 1))
			win->buttons[i] = ptr[i];
		win->buttons[i] = init_button(rect, path_tex, win, button_pressed);
		free(ptr);
	}
}