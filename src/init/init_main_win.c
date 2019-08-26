/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 11:30:30 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/26 14:59:57 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

void
	init_main_win(char *name)
{
	t_win		*win;
	t_element	*elem;
	t_element	*text;

	ui_add_win(win = ui_init_win(ft_strdup(name), (t_rect){200, 200, 640, 480},
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE, &main_win_fun));
	add_layers(win, "main");
	add_texture_to_win(win, "img/cat.bmp", "cat", BMP);
	add_texture_to_win(win, "img/button_1.bmp", "button1", BMP);
	elem = ui_init_element(1, "btn_clear", (t_rect){0, 0, 50, 50}, win, "button1", NULL, NULL, NULL,
						NULL, &image_draw, &clear_cur_layer, NULL, NULL, NULL, NULL);
	add_element_to_win(win, elem);
	text = ui_init_element(1, "text_clear", (t_rect){10, 10, 30, 30}, win, NULL, NULL,
						ft_colornew((t_color){255, 0, 0, 255}), "clear",
						NULL, &render_text, NULL, NULL, NULL, NULL, NULL);
	text->ttf = get_ttf_by_name("standart", 14);
	add_element_draw_to_win(elem, text);

	elem = ui_init_element(1, "btn_save", (t_rect){50, 0, 50, 50}, win, "button1", NULL, NULL, NULL,
						NULL, &image_draw, &btn_save_file, NULL, NULL, NULL, NULL);
	add_element_to_win(win, elem);
	text = ui_init_element(1, "text_save", (t_rect){10, 10, 30, 30}, win, NULL, NULL,
						ft_colornew((t_color){255, 0, 0, 255}), "save",
						NULL, &render_text, NULL, NULL, NULL, NULL, NULL);
	text->ttf = get_ttf_by_name("standart", 14);
	add_element_draw_to_win(elem, text);
}
