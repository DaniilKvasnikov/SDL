/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 11:30:30 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/26 13:43:11 by rrhaenys         ###   ########.fr       */
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
	add_texture_to_win(win, "img/cat.bmp", "cat", BMP);
	add_texture_to_win(win, "img/button_1.bmp", "button1", BMP);
	elem = ui_init_element(1, "btn_clear", (t_rect){0, 0, 50, 50}, win, "button1", NULL, NULL, NULL,
						NULL, &image_draw, &clear_cur_layer, NULL, NULL, NULL, NULL);
	add_element_to_win(win, elem);
	add_layers(win, "main");
}
