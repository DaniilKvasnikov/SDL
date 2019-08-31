/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_settings_win.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 08:45:47 by ilyabaturin       #+#    #+#             */
/*   Updated: 2019/08/31 11:39:32 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

static void
	add_color_info(t_win *win, int *rad)
{
	t_element	*button;
	button = ui_init_element(rad, "red_line", (t_rect){0, 150, 300, 50}, win, "button1", NULL, NULL, NULL,
						NULL, &scroll_draw, &empty_down, &corr_param_scroll, NULL, NULL, NULL);
	add_element_to_win(win, button);
	add_param_to_elem(button, "par", ft_floatnew(1.0f));
	
	button = ui_init_element(rad, "green_line", (t_rect){0, 200, 300, 50}, win, "button1", NULL, NULL, NULL,
						NULL, &scroll_draw, &empty_down, &corr_param_scroll, NULL, NULL, NULL);
	add_element_to_win(win, button);
	add_param_to_elem(button, "par", ft_floatnew(1.0f));
	
	button = ui_init_element(rad, "blue_line", (t_rect){0, 250, 300, 50}, win, "button1", NULL, NULL, NULL,
						NULL, &scroll_draw, &empty_down, &corr_param_scroll, NULL, NULL, NULL);
	add_element_to_win(win, button);
	add_param_to_elem(button, "par", ft_floatnew(1.0f));
	
	button = ui_init_element(rad, "color_example", (t_rect){0, 300, 300, 50}, win, "button1", NULL, NULL, NULL,
						NULL, &image_draw, &empty_down, NULL, NULL, &input_border_size, NULL);
	add_element_to_win(win, button);
}

void
	init_settings_win(t_sdl_data *data, char *name)
{
	t_win		*win;
	t_element	*button;
	t_element	*elem;
	t_element	*text;
	int			*rad;

	ui_add_win(win = ui_init_win(data, ft_strdup(name), (t_rect){840, 200, 300, 480},
		SDL_WINDOW_SHOWN, &main_mouse_muve_left, &mouse_muve_scrole));
	add_texture_to_win(win, "img/cat.bmp", "cat", BMP);
	add_texture_to_win(win, "img/button_1.bmp", "button1", BMP);
	add_texture_to_win(win, "img/checked_checkbox.bmp", "box", BMP);
	add_texture_to_win(win, "img/unchecked_checkbox.bmp", "unbox", BMP);

	button = ui_init_element(ft_intnew(1), "file", (t_rect){0, 0, 300, 50}, win, "button1", NULL, NULL, NULL,
						NULL, &image_draw, &empty_down, NULL, NULL, &input_border_size, NULL);
	add_element_to_win(win, button);
	text = ui_init_element(ft_intnew(1), "text_save", (t_rect){10, 10, 70, 30}, win, NULL, NULL,
						ft_colornew((t_color){255, 0, 0, 255}), "Border size:",
						NULL, &render_text, NULL, NULL, NULL, NULL, NULL);
	text->ttf = get_ttf_by_name(data, "standart", 14);
	add_element_draw_to_win(button, text);
	text = ui_init_element(ft_intnew(1), "text_save", (t_rect){90, 10, 200, 30}, win, NULL, NULL,
						ft_colornew((t_color){255, 0, 0, 255}), ft_strdup("1234567890"),
						NULL, &render_text, NULL, NULL, NULL, NULL, NULL);
	text->ttf = get_ttf_by_name(win->sdl_data, "standart", 14);
	add_element_draw_to_win(button, text);
	add_param_to_elem(button, "text", text);

	button = ui_init_element(ft_intnew(1), "color", (t_rect){0, 50, 300, 50}, win, "button1", NULL, NULL, NULL,
						NULL, &radiobut_render, &radio_buton_down, NULL, NULL, &input_border_size, NULL);
	add_element_to_win(win, button);
	add_param_to_elem(button, "active", get_texture_by_name(win, "box"));
	add_param_to_elem(button, "deactive", get_texture_by_name(win, "unbox"));
	add_param_to_elem(button, "status", rad = ft_intnew(1));
	add_param_to_elem(button, "tag", "radio1");

	button = ui_init_element(ft_intnew(1), "color_border", (t_rect){0, 100, 300, 50}, win, "button1", NULL, NULL, NULL,
						NULL, &radiobut_render, &radio_buton_down, NULL, NULL, &input_border_size, NULL);
	add_element_to_win(win, button);
	add_param_to_elem(button, "active", get_texture_by_name(win, "box"));
	add_param_to_elem(button, "deactive", get_texture_by_name(win, "unbox"));
	add_param_to_elem(button, "status", rad = ft_intnew(0));
	add_param_to_elem(button, "tag", "radio1");

	add_color_info(win, rad);
}
