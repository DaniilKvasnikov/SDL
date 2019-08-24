/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ptool_win.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 21:23:41 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/24 15:15:02 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

t_win
	*create_ptool_win(t_mydata *mydata, char *name)
{
	t_win		*win;
	t_element	*elem;
	t_element	*img;

	ft_add_win(mydata, win = ft_init_win(mydata, name, (t_rect){0, 100, 100, 480}, SDL_WINDOW_SHOWN, NULL));
	add_element_to_win(win, elem = init_button_to_win((t_rect){0, 0, 50, 50}, "./img/button_1.bmp", win, NULL, &set_draw_type, &active_elem, &button_render));
	img = init_image_to_win((t_rect){elem->rect.x + elem->rect.w / 2 - elem->rect.w / 4, elem->rect.y + elem->rect.h / 2 - elem->rect.h / 4, elem->rect.w / 2, elem->rect.h / 2}, "img/brush.bmp", win, NULL, NULL, NULL, NULL, &button_render);
	elem->int_par = ft_intnew(DRAW_POINT);
	elem->sub_group = add_group_e(elem->sub_group, img, NULL);
	img->parent = elem;
	add_element_to_win(win, elem = init_button_to_win((t_rect){50, 0, 50, 50}, "./img/button_1.bmp", win, NULL, &set_draw_type, &active_elem, &button_render));
	img = init_image_to_win((t_rect){elem->rect.x + elem->rect.w / 2 - elem->rect.w / 4, elem->rect.y + elem->rect.h / 2 - elem->rect.h / 4, elem->rect.w / 2, elem->rect.h / 2}, "img/eraser.bmp", win, NULL, NULL, NULL, NULL, &button_render);
	elem->int_par = ft_intnew(DRAW_ERASER);
	elem->sub_group = add_group_e(elem->sub_group, img, NULL);
	img->parent = elem;
	add_element_to_win(win, elem = init_button_to_win((t_rect){0, 50, 50, 50}, "./img/button_1.bmp", win, NULL, &set_draw_type, &active_elem, &button_render));
	img = init_image_to_win((t_rect){elem->rect.x + elem->rect.w / 2 - elem->rect.w / 4, elem->rect.y + elem->rect.h / 2 - elem->rect.h / 4, elem->rect.w / 2, elem->rect.h / 2}, "img/pencil.bmp", win, NULL, NULL, NULL, NULL, &button_render);
	elem->int_par = ft_intnew(DRAW_LINE);
	elem->sub_group = add_group_e(elem->sub_group, img, NULL);
	img->parent = elem;
	add_element_to_win(win, elem = init_button_to_win((t_rect){50, 50, 50, 50}, "./img/button_1.bmp", win, NULL, &menulist_touch, &active_elem, &dropdownlist_render));
	img = init_image_to_win((t_rect){elem->rect.x + elem->rect.w / 2 - elem->rect.w / 4, elem->rect.y + elem->rect.h / 2 - elem->rect.h / 4, elem->rect.w / 2, elem->rect.h / 2}, "img/figures.bmp", win, NULL, &set_draw_type, NULL, NULL, &button_render);
	elem->sub_group = add_group_e(elem->sub_group, img, NULL);
	img->parent = elem;
	t_element *but1 = init_button_to_win((t_rect){elem->rect.x - elem->rect.w, elem->rect.y + elem->rect.h, elem->rect.w, elem->rect.h}, "./img/button_1.bmp", win, "rect", &set_draw_type, &active_elem, &button_render);
	t_element *but2 = init_button_to_win((t_rect){elem->rect.x - elem->rect.w, elem->rect.y + elem->rect.h * 2, elem->rect.w, elem->rect.h}, "./img/button_1.bmp", win, "elipse", &set_draw_type, &active_elem, &button_render);
	t_element *but3 = init_button_to_win((t_rect){elem->rect.x, elem->rect.y + elem->rect.h, elem->rect.w, elem->rect.h}, "./img/button_1.bmp", win, "rect f", &set_draw_type, &active_elem, &button_render);
	t_element *but4 = init_button_to_win((t_rect){elem->rect.x, elem->rect.y + elem->rect.h * 2, elem->rect.w, elem->rect.h}, "./img/button_1.bmp", win, "elipse f", &set_draw_type, &active_elem, &button_render);
	elem->sub_group = add_group_e(elem->sub_group, but1, NULL);
	but1->parent = elem;
	but1->int_par = ft_intnew(DRAW_RECT);
	elem->sub_group = add_group_e(elem->sub_group, but2, NULL);
	but2->parent = elem;
	but2->int_par = ft_intnew(DRAW_ELIPSE);
	elem->sub_group = add_group_e(elem->sub_group, but3, NULL);
	but3->parent = elem;
	but3->int_par = ft_intnew(DRAW_RECT_FILLED);
	elem->sub_group = add_group_e(elem->sub_group, but4, NULL);
	but4->parent = elem;
	but4->int_par = ft_intnew(DRAW_ELIPSE_FILLED);
	return (win);
}
