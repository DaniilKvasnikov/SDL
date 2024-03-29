/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyabaturin <ilyabaturin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 12:58:29 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/29 09:18:15 by ilyabaturin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

static void
	add_buttons_figures(t_element *button, t_win *win)
{
	t_element *but;
	t_element *image;

	but = ui_init_element(ft_intnew(0), "figure1", (t_rect){0, 150, 50, 50}, win, "button1", NULL, NULL, NULL,
						NULL, &image_draw, &set_drawtype_rect, NULL, NULL, NULL, NULL);
	add_element_to_win(win, but);
	image = ui_init_element(ft_intnew(1), "text_rect_image", (t_rect){10, 10, 30, 30}, win, NULL, NULL,
						ft_colornew((t_color){255, 0, 0, 255}), "rect",
						NULL, &render_text, NULL, NULL, NULL, NULL, NULL);
	image->ttf = get_ttf_by_name("standart", 14);
	add_element_draw_to_win(but, image);
	add_param_to_elem(button, "btn1", but);

	but = ui_init_element(ft_intnew(0), "figure2", (t_rect){50, 150, 50, 50}, win, "button1", NULL, NULL, NULL,
						NULL, &image_draw, &set_drawtype_rectfilled, NULL, NULL, NULL, NULL);
	add_element_to_win(win, but);
	image = ui_init_element(ft_intnew(1), "text_rect_image", (t_rect){10, 10, 30, 30}, win, NULL, NULL,
						ft_colornew((t_color){255, 0, 0, 255}), "rectfil",
						NULL, &render_text, NULL, NULL, NULL, NULL, NULL);
	image->ttf = get_ttf_by_name("standart", 14);
	add_element_draw_to_win(but, image);
	add_param_to_elem(button, "btn2", but);

	but = ui_init_element(ft_intnew(0), "figure3", (t_rect){0, 200, 50, 50}, win, "button1", NULL, NULL, NULL,
						NULL, &image_draw, &set_drawtype_elipse, NULL, NULL, NULL, NULL);
	add_element_to_win(win, but);
	image = ui_init_element(ft_intnew(1), "text_sphere_image", (t_rect){10, 10, 30, 30}, win, NULL, NULL,
						ft_colornew((t_color){255, 0, 0, 255}), "sphere",
						NULL, &render_text, NULL, NULL, NULL, NULL, NULL);
	image->ttf = get_ttf_by_name("standart", 14);
	add_element_draw_to_win(but, image);
	add_param_to_elem(button, "btn3", but);

	but = ui_init_element(ft_intnew(0), "figure4", (t_rect){50, 200, 50, 50}, win, "button1", NULL, NULL, NULL,
						NULL, &image_draw, &set_drawtype_elipsefilled, NULL, NULL, NULL, NULL);
	add_element_to_win(win, but);
	image = ui_init_element(ft_intnew(1), "text_sphere_fil_image", (t_rect){10, 10, 30, 30}, win, NULL, NULL,
						ft_colornew((t_color){255, 0, 0, 255}), "spherefil",
						NULL, &render_text, NULL, NULL, NULL, NULL, NULL);
	image->ttf = get_ttf_by_name("standart", 14);
	add_element_draw_to_win(but, image);
	add_param_to_elem(button, "btn4", but);
}

void
	init_ptool_win(char *name)
{
	t_win		*win;
	t_element	*elem;
	t_element	*image;
	t_element	*but;
	t_element	*figures;

	ui_add_win(win = ui_init_win(ft_strdup(name), (t_rect){100, 200, 100, 480},
		SDL_WINDOW_SHOWN, &info_win_fun, NULL));
	add_texture_to_win(win, "img/button_1.bmp", "button1", BMP);
	add_texture_to_win(win, "img/brush.bmp", "brush", BMP);
	add_texture_to_win(win, "img/eraser.bmp", "eraser", BMP);
	add_texture_to_win(win, "img/pencil.bmp", "line", BMP);
	add_texture_to_win(win, "img/figures.bmp", "figures", BMP);
	add_texture_to_win(win, "img/cat.bmp", "cat", BMP);
	add_texture_to_win(win, "img/cat2.png", "cat2", PNG);
	add_texture_to_win(win, "img/cat3.jpg", "cat3", JPG);
	elem = ui_init_element(ft_intnew(1), "button_hand", (t_rect){0, 0, 50, 50}, win, "button1", NULL, NULL, NULL,
						NULL, &image_draw, &set_drawtype_nodraw, NULL, NULL, NULL, NULL);
	add_element_to_win(win, elem);
	image = ui_init_element(ft_intnew(1), "text_nodraw", (t_rect){10, 10, 30, 30}, win, NULL, NULL,
						ft_colornew((t_color){255, 0, 0, 255}), "hand",
						NULL, &render_text, NULL, NULL, NULL, NULL, NULL);
	image->ttf = get_ttf_by_name("standart", 14);
	add_element_draw_to_win(elem, image);
	elem = ui_init_element(ft_intnew(1), "button1", (t_rect){0, 50, 50, 50}, win, "button1", NULL, NULL, NULL,
						NULL, &image_draw, &set_drawtype_point, NULL, NULL, NULL, NULL);
	add_element_to_win(win, elem);
	image = ui_init_element(ft_intnew(1), "brush_image", (t_rect){10, 10, 30, 30}, win, "brush", NULL, NULL, NULL,
						NULL, &image_draw, NULL, NULL, NULL, NULL, NULL);
	add_element_draw_to_win(elem, image);
	elem = ui_init_element(ft_intnew(1), "button2", (t_rect){50, 50, 50, 50}, win, "button1", NULL, NULL, NULL,
						NULL, &image_draw, &set_drawtype_eraser, NULL, NULL, NULL, NULL);
	add_element_to_win(win, elem);
	image = ui_init_element(ft_intnew(1), "eraser_image", (t_rect){10, 10, 30, 30}, win, "eraser", NULL, NULL, NULL,
						NULL, &image_draw, NULL, NULL, NULL, NULL, NULL);
	add_element_draw_to_win(elem, image);
	elem = ui_init_element(ft_intnew(1), "button3", (t_rect){0, 100, 50, 50}, win, "button1", NULL, NULL, NULL,
						NULL, &image_draw, &set_drawtype_line, NULL, NULL, NULL, NULL);
	add_element_to_win(win, elem);
	image = ui_init_element(ft_intnew(1), "line_image", (t_rect){10, 10, 30, 30}, win, "line", NULL, NULL, NULL,
						NULL, &image_draw, NULL, NULL, NULL, NULL, NULL);
	add_element_draw_to_win(elem, image);

	figures = ui_init_element(ft_intnew(1), "button4", (t_rect){50, 100, 50, 50}, win, "button1", NULL, NULL, NULL,
						NULL, &image_draw, &set_active_btn_figs, NULL, NULL, NULL, &unset_drawtype);
	add_element_to_win(win, figures);
	image = ui_init_element(ft_intnew(1), "figures_image", (t_rect){10, 10, 30, 30}, win, "figures", NULL, NULL, NULL,
						NULL, &image_draw, NULL, NULL, NULL, NULL, NULL);
	add_element_draw_to_win(figures, image);

	add_buttons_figures(figures, win);

	elem = ui_init_element(ft_intnew(1), "button5", (t_rect){0, 150, 50, 50}, win, "cat", NULL, NULL, NULL,
						NULL, &image_draw, &set_drawtype_texture, NULL, NULL, NULL, NULL);
	add_element_to_win(win, elem);

	elem = ui_init_element(ft_intnew(1), "button6", (t_rect){50, 150, 50, 50}, win, "cat2", NULL, NULL, NULL,
						NULL, &image_draw, &set_drawtype_texture, NULL, NULL, NULL, NULL);
	add_element_to_win(win, elem);

	elem = ui_init_element(ft_intnew(1), "button7", (t_rect){0, 200, 50, 50}, win, "cat3", NULL, NULL, NULL,
						NULL, &image_draw, &set_drawtype_texture, NULL, NULL, NULL, NULL);
	add_element_to_win(win, elem);
}
