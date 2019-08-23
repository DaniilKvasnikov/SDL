/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_info_win.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 20:47:36 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/23 16:22:22 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

static void
	connect_color(t_element *red, t_element *green, t_element *blue, t_rgba_int *color)
{
	red->int_par = &color->r;
	green->int_par = &color->g;
	blue->int_par = &color->b;
}

t_win
	*create_info_win(t_mydata *mydata, char *name)
{
	t_win		*win;
	t_element	*text;
	ft_add_win(mydata, win = ft_init_win(mydata, name, (t_rect){840, 100, 240, 480}, SDL_WINDOW_SHOWN, &ft_button_press));
	t_element *line_thickness = add_element_to_win(win, init_textline((t_rect){0,0, 240, 30}, "./img/button_1.bmp", win, ft_strdup("1"), &element_touch, &textline_input_num, &active_elem, &button_render));
	line_thickness->int_par = ft_intnew(1);
	text = init_text_to_win((t_rect){line_thickness->rect.x, line_thickness->rect.y, 50, line_thickness->rect.h}, win, "par:", NULL, NULL, &text_render);
	line_thickness->sub_group = add_group_to_elem(line_thickness, text, NULL);
	t_element *checkbox1 = add_element_to_win(win, init_checkbox_to_win((t_rect){0, 30, 30, 30}, "img/unchecked_checkbox.bmp", "img/checked_checkbox.bmp", win, ft_intnew(1), ft_floatnew(0.0), &radiobutton_touch, &active_elem, &checkbox_render));
	t_element *checkbox2 = add_element_to_win(win, init_checkbox_to_win((t_rect){0, 60, 30, 30}, "img/unchecked_checkbox.bmp", "img/checked_checkbox.bmp", win, ft_intnew(0), ft_floatnew(0.0), &radiobutton_touch, &active_elem, &checkbox_render));
	win->groupe = add_group_e(win->groupe, checkbox1, &gr_cheacker);
	win->groupe = add_group_e(win->groupe, checkbox2, NULL);
	text = init_text_to_win((t_rect){checkbox1->rect.x + checkbox1->rect.w, checkbox1->rect.y, 50, checkbox1->rect.h}, win, "color", NULL, NULL, &text_render);
	checkbox1->sub_group = add_group_to_elem(checkbox1, text, NULL);
	text = init_text_to_win((t_rect){checkbox2->rect.x + checkbox2->rect.w * 2, checkbox2->rect.y, 50, checkbox2->rect.h}, win, "color_border", NULL, NULL, &text_render);
	checkbox2->sub_group = add_group_to_elem(checkbox2, text, NULL);
	win->groupe = add_group_e(win->groupe, checkbox2, &gr_cheacker);
	win->groupe = add_group_e(win->groupe, checkbox2, NULL);

	t_element *slider_red = init_sliders_to_win((t_rect){0, 90, 240, 30}, NULL, "img/unchecked_checkbox.bmp", win, ft_intnew(255), ft_floatnew(1.0f), &element_touch, &sliders_pressed, &active_elem, &sliders_render);
	t_element *slider_green = init_sliders_to_win((t_rect){0, 120, 240, 30}, NULL, "img/unchecked_checkbox.bmp", win, ft_intnew(255), ft_floatnew(1.0f), &element_touch, &sliders_pressed, &active_elem, &sliders_render);
	t_element *slider_blue = init_sliders_to_win((t_rect){0, 150, 240, 30}, NULL, "img/unchecked_checkbox.bmp", win, ft_intnew(255), ft_floatnew(1.0f), &element_touch, &sliders_pressed, &active_elem, &sliders_render);
	slider_red->color = ft_rgba_int_new((t_rgba_int){255, 0, 0, 0});
	slider_green->color = ft_rgba_int_new((t_rgba_int){0, 255, 0, 0});
	slider_blue->color = ft_rgba_int_new((t_rgba_int){0, 0, 255, 0});

	t_element *color = init_button_to_win((t_rect){0, 180, 240, 30}, NULL, win, NULL, &void_touch, NULL, &button_render);
	color->color = &mydata->color;
	connect_color(slider_red, slider_green, slider_blue, &mydata->color);

	checkbox1->sub_group = add_group_to_elem(checkbox1, slider_red, NULL);
	checkbox1->sub_group = add_group_to_elem(checkbox1, slider_green, NULL);
	checkbox1->sub_group = add_group_to_elem(checkbox1, slider_blue, NULL);
	checkbox1->sub_group = add_group_to_elem(checkbox1, color, NULL);

	t_element *slider_border_red = init_sliders_to_win((t_rect){0, 90, 240, 30}, NULL, "img/unchecked_checkbox.bmp", win, ft_intnew(255), ft_floatnew(1.0f), &element_touch, &sliders_pressed, &active_elem, &sliders_render);
	t_element *slider_border_green = init_sliders_to_win((t_rect){0, 120, 240, 30}, NULL, "img/unchecked_checkbox.bmp", win, ft_intnew(255), ft_floatnew(1.0f), &element_touch, &sliders_pressed, &active_elem, &sliders_render);
	t_element *slider_border_blue = init_sliders_to_win((t_rect){0, 150, 240, 30}, NULL, "img/unchecked_checkbox.bmp", win, ft_intnew(255), ft_floatnew(1.0f), &element_touch, &sliders_pressed, &active_elem, &sliders_render);

	slider_border_red->color = ft_rgba_int_new((t_rgba_int){255, 0, 0, 0});
	slider_border_green->color = ft_rgba_int_new((t_rgba_int){0, 255, 0, 0});
	slider_border_blue->color = ft_rgba_int_new((t_rgba_int){0, 0, 255, 0});

	t_element *color_border = init_button_to_win((t_rect){0, 180, 240, 30}, NULL, win, NULL, &void_touch, NULL, &button_render);
	color_border->color = &mydata->color_border;
	connect_color(slider_border_red, slider_border_green, slider_border_blue, &mydata->color_border);

	checkbox2->sub_group = add_group_to_elem(checkbox2, slider_border_red, NULL);
	checkbox2->sub_group = add_group_to_elem(checkbox2, slider_border_green, NULL);
	checkbox2->sub_group = add_group_to_elem(checkbox2, slider_border_blue, NULL);
	checkbox2->sub_group = add_group_to_elem(checkbox2, color_border, NULL);
	return (win);
}
