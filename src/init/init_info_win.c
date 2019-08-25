/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 12:58:29 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 17:31:20 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

void
	init_info_win(char *name)
{
	t_win		*win;
	t_element	*elem;
	t_element	*image;
	t_element	*but;

	ui_add_win(win = ui_init_win(ft_strdup(name), (t_rect){100, 200, 100, 480},
		SDL_WINDOW_SHOWN, &info_win_fun));
	add_texture_to_win(win, "img/button_1.bmp", "button1");
	add_texture_to_win(win, "img/brush.bmp", "brush");
	add_texture_to_win(win, "img/eraser.bmp", "eraser");
	add_texture_to_win(win, "img/pencil.bmp", "line");
	add_texture_to_win(win, "img/figures.bmp", "figures");
	elem = ui_init_element(1, "button1", (t_rect){0, 0, 50, 50}, win, "button1", NULL, NULL, NULL,
						NULL, &image_draw, &set_drawtype_point, NULL, NULL, NULL, NULL);
	add_element_to_win(win, elem);
	image = ui_init_element(1, "brush_image", (t_rect){10, 10, 30, 30}, win, "brush", NULL, NULL, NULL,
						NULL, &image_draw, NULL, NULL, NULL, NULL, NULL);
	add_element_draw_to_win(elem, image);
	elem = ui_init_element(1, "button2", (t_rect){50, 0, 50, 50}, win, "button1", NULL, NULL, NULL,
						NULL, &image_draw, &set_drawtype_eraser, NULL, NULL, NULL, NULL);
	add_element_to_win(win, elem);
	image = ui_init_element(1, "eraser_image", (t_rect){10, 10, 30, 30}, win, "eraser", NULL, NULL, NULL,
						NULL, &image_draw, NULL, NULL, NULL, NULL, NULL);
	add_element_draw_to_win(elem, image);
	elem = ui_init_element(1, "button3", (t_rect){0, 50, 50, 50}, win, "button1", NULL, NULL, NULL,
						NULL, &image_draw, &set_drawtype_line, NULL, NULL, NULL, NULL);
	add_element_to_win(win, elem);
	image = ui_init_element(1, "line_image", (t_rect){10, 10, 30, 30}, win, "line", NULL, NULL, NULL,
						NULL, &image_draw, NULL, NULL, NULL, NULL, NULL);
	add_element_draw_to_win(elem, image);
	elem = ui_init_element(1, "button4", (t_rect){50, 50, 50, 50}, win, "button1", NULL, NULL, NULL,
						NULL, &image_draw, &set_active_btn_figs, NULL, NULL, NULL, NULL);
	add_element_to_win(win, elem);
	image = ui_init_element(1, "figures_image", (t_rect){10, 10, 30, 30}, win, "figures", NULL, NULL, NULL,
						NULL, &image_draw, NULL, NULL, NULL, NULL, NULL);
	add_element_draw_to_win(elem, image);
	elem = ui_init_element(0, "button5", (t_rect){0, 100, 50, 50}, win, "button1", NULL, NULL, NULL,
						NULL, &image_draw, &set_drawtype_rect, NULL, NULL, NULL, NULL);
	add_element_to_win(win, elem);
	image = ui_init_element(1, "text_rect_image", (t_rect){10, 10, 30, 30}, win, NULL, NULL,
						ft_colornew((t_color){255, 0, 0, 255}), "rect",
						NULL, &render_text, NULL, NULL, NULL, NULL, NULL);
	image->ttf = get_ttf_by_name("standart14");
	add_element_draw_to_win(elem, image);
}
