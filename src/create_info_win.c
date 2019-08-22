/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_info_win.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 20:47:36 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/22 12:39:10 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

t_win
	*create_info_win(t_mydata *mydata, char *name)
{
	t_win		*win;
	t_element	*text;
	ft_add_win(mydata, win = ft_init_win(mydata, name, (t_rect){840, 100, 240, 480}, SDL_WINDOW_SHOWN, &ft_button_press));
	t_element *line_thickness = add_element_to_win(win, init_textline((t_rect){0,0, 240, 50}, "./img/button_1.bmp", win, ft_strdup("1"), &element_touch, &textline_input_num, &active_elem, &button_render));
	line_thickness->int_par = 1;
	text = init_text_to_win((t_rect){line_thickness->pos.x, line_thickness->pos.y, 100, line_thickness->size.y}, win, "par:", NULL, NULL, &text_render);
	line_thickness->sub_group = add_group_to_elem(line_thickness, text, NULL);
	t_element *slider_red = add_element_to_win(win, init_sliders_to_win((t_rect){0, 50, 240, 50}, "img/button_1.bmp", "img/unchecked_checkbox.bmp", win, &element_touch, &sliders_pressed, &active_elem, &sliders_render));
	t_element *slider_green = add_element_to_win(win, init_sliders_to_win((t_rect){0, 100, 240, 50}, "img/button_1.bmp", "img/unchecked_checkbox.bmp", win, &element_touch, &sliders_pressed, &active_elem, &sliders_render));
	t_element *slider_blue = add_element_to_win(win, init_sliders_to_win((t_rect){0, 150, 240, 50}, "img/button_1.bmp", "img/unchecked_checkbox.bmp", win, &element_touch, &sliders_pressed, &active_elem, &sliders_render));
	t_element *color = add_element_to_win(win, init_button_to_win((t_rect){0, 200, 240, 50}, NULL, win, NULL, NULL, NULL, &button_render));
	color->color_border = (t_rgba_char){255, 0, 0, 0};
	color->color = (t_rgba_char){0, 255, 0, 0};
	add_pair_int_to_win(win, init_pair_of_int(&slider_red->int_par, &color->color.r, 0));
	add_pair_int_to_win(win, init_pair_of_int(&slider_green->int_par, &color->color.g, 0));
	add_pair_int_to_win(win, init_pair_of_int(&slider_blue->int_par, &color->color.b, 0));
	add_pair_int_to_win(win, init_pair_of_int(&slider_red->int_par, &mydata->color.r, 0));
	add_pair_int_to_win(win, init_pair_of_int(&slider_green->int_par, &mydata->color.g, 0));
	add_pair_int_to_win(win, init_pair_of_int(&slider_blue->int_par, &mydata->color.b, 0));
	return (win);
}
