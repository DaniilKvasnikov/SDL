/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_settings_win.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyabaturin <ilyabaturin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 08:45:47 by ilyabaturin       #+#    #+#             */
/*   Updated: 2019/08/27 10:50:38 by ilyabaturin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

void
	init_settings_win(char *name)
{
	t_win		*win;
	t_element	*button;
	t_element	*elem;
	t_element	*text;

	ui_add_win(win = ui_init_win(ft_strdup(name), (t_rect){840, 200, 300, 480},
		SDL_WINDOW_SHOWN, &main_mouse_muve_left, &mouse_muve_scrole));
	add_texture_to_win(win, "img/cat.bmp", "cat", BMP);
	add_texture_to_win(win, "img/button_1.bmp", "button1", BMP);
	add_texture_to_win(win, "img/unchecked_checkbox.bmp", "box", BMP);

	button = ui_init_element(1, "file", (t_rect){0, 0, 300, 50}, win, "button1", NULL, NULL, NULL,
						NULL, &image_draw, &empty_down, NULL, NULL, &input_border_size, NULL);
	add_element_to_win(win, button);
	text = ui_init_element(1, "text_save", (t_rect){10, 10, 70, 30}, win, NULL, NULL,
						ft_colornew((t_color){255, 0, 0, 255}), "Border size:",
						NULL, &render_text, NULL, NULL, NULL, NULL, NULL);
	text->ttf = get_ttf_by_name("standart", 14);
	add_element_draw_to_win(button, text);
	text = ui_init_element(1, "text_save", (t_rect){90, 10, 200, 30}, win, NULL, NULL,
						ft_colornew((t_color){255, 0, 0, 255}), ft_strdup("1234567890"),
						NULL, &render_text, NULL, NULL, NULL, NULL, NULL);
	text->ttf = get_ttf_by_name("standart", 14);
	add_element_draw_to_win(button, text);
	add_param_to_elem(button, "text", text);

	button = ui_init_element(1, "red_line", (t_rect){0, 50, 300, 50}, win, "button1", NULL, NULL, NULL,
						NULL, &scroll_draw, &empty_down, &corr_param_scroll, NULL, NULL, NULL);
	add_element_to_win(win, button);
	add_param_to_elem(button, "par", ft_floatnew(1.0f));
}
