/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_info_win.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 20:47:36 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/22 17:14:27 by rrhaenys         ###   ########.fr       */
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
	t_element *line_thickness = add_element_to_win(win, init_textline((t_rect){0,0, 240, 50}, "./img/button_1.bmp", win, ft_strdup("1"), &element_touch, &textline_input_num, &active_elem, &button_render));
	line_thickness->int_par = ft_intnew(1);
	text = init_text_to_win((t_rect){line_thickness->rect.x, line_thickness->rect.y, 100, line_thickness->rect.h}, win, "par:", NULL, NULL, &text_render);
	line_thickness->sub_group = add_group_to_elem(line_thickness, text, NULL);
	t_element *checkbox1 = add_element_to_win(win, init_checkbox_to_win((t_rect){0, 50, 50, 50}, "img/unchecked_checkbox.bmp", "img/checked_checkbox.bmp", win, ft_intnew(1), ft_floatnew(0.0), &radiobutton_touch, &active_elem, &checkbox_render));
	t_element *checkbox2 = add_element_to_win(win, init_checkbox_to_win((t_rect){0, 100, 50, 50}, "img/unchecked_checkbox.bmp", "img/checked_checkbox.bmp", win, ft_intnew(0), ft_floatnew(0.0), &radiobutton_touch, &active_elem, &checkbox_render));
	win->groupe = add_group_e(win->groupe, checkbox1, &gr_cheacker);
	win->groupe = add_group_e(win->groupe, checkbox2, NULL);

	
	t_element *slider_red = add_element_to_win(win, init_sliders_to_win((t_rect){0, 150, 240, 50}, NULL, "img/unchecked_checkbox.bmp", win, ft_intnew(255), ft_floatnew(1.0f), &element_touch, &sliders_pressed, &active_elem, &sliders_render));
	t_element *slider_green = add_element_to_win(win, init_sliders_to_win((t_rect){0, 200, 240, 50}, NULL, "img/unchecked_checkbox.bmp", win, ft_intnew(255), ft_floatnew(1.0f), &element_touch, &sliders_pressed, &active_elem, &sliders_render));
	t_element *slider_blue = add_element_to_win(win, init_sliders_to_win((t_rect){0, 250, 240, 50}, NULL, "img/unchecked_checkbox.bmp", win, ft_intnew(255), ft_floatnew(1.0f), &element_touch, &sliders_pressed, &active_elem, &sliders_render));
	t_element *color = add_element_to_win(win, init_button_to_win((t_rect){0, 300, 240, 50}, NULL, win, NULL, NULL, NULL, &button_render));
	color->color_border = &mydata->color_border;
	color->color = &mydata->color;
	connect_color(slider_red, slider_green, slider_blue, mydata->curr_color);
	return (win);
}
