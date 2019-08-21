/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_info_win.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 20:47:36 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/21 09:11:33 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

t_win
	*create_info_win(t_mydata *mydata, char *name)
{
	t_win	*win;
	ft_add_win(mydata, win = ft_init_win(mydata, name, (t_rect){840, 100, 240, 480}, SDL_WINDOW_SHOWN, &ft_button_press));
	t_element *line_thickness = init_textline((t_rect){0,0, 240, 50}, "./img/button_1.bmp", win, ft_strdup("line: "), &element_touch, &textline_input, &active_elem, &button_render);
	add_element_to_win(win, line_thickness);
	return (win);
}
