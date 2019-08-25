/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 12:58:29 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 15:12:43 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

void
	init_info_win(char *name)
{
	t_win		*win;
	t_element	*elem;

	ui_add_win(win = ui_init_win(ft_strdup(name), (t_rect){100, 200, 100, 480},
		SDL_WINDOW_SHOWN, &info_win_fun));
	add_texture_to_win(win, "img/button_1.bmp", "button1");
	elem = ui_init_element(1, "button1", (t_rect){0, 0, 50, 50}, win, "button1", NULL, NULL, NULL,
						NULL, &image_draw, &set_drawtype_brush, NULL, NULL, NULL, NULL);
	add_element_to_win(win, elem);
}
