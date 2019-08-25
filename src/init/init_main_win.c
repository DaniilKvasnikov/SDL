/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 11:30:30 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 14:37:15 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

void
	init_main_win(char *name)
{
	t_win		*win;
	t_element	*elem;

	ui_add_win(win = ui_init_win(ft_strdup(name), (t_rect){200, 200, 640, 480},
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE, &main_win_fun));
	add_texture_to_win(win, "img/cat.bmp", "cat");
	add_element_to_win(win, elem = ui_init_element(1, "image1",
						(t_rect){0, 0, 100, 100}, win, "cat", NULL, NULL, NULL,
						NULL, &image_draw, NULL, NULL, NULL, NULL, NULL));
}
