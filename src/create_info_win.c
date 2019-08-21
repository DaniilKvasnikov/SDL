/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_info_win.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 20:47:36 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/21 18:08:34 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

t_win
	*create_info_win(t_mydata *mydata, char *name)
{
	t_win		*win;
	t_element	*text;
	ft_add_win(mydata, win = ft_init_win(mydata, name, (t_rect){840, 100, 240, 480}, SDL_WINDOW_SHOWN, &ft_button_press));
	t_element *line_thickness = add_element_to_win(win, init_textline((t_rect){0,0, 240, 50}, "./img/button_1.bmp", win, ft_strdup(""), &element_touch, &textline_input_num, &active_elem, &button_render));
	text = init_text_to_win((t_rect){line_thickness->pos.x, line_thickness->pos.y, 100, line_thickness->size.y}, win, "par:", NULL, NULL, &text_render);
	line_thickness->sub_group = add_group_to_elem(line_thickness, text, NULL);
	return (win);
}
