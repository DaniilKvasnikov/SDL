/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ptool_win.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 21:23:41 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/18 22:19:00 by rrhaenys         ###   ########.fr       */
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
	add_element_to_win(win, elem = init_button_to_win((t_rect){0, 0, 50, 50}, "./img/button_1.bmp", win, NULL, NULL, NULL, &button_render));
	img = init_image_to_win((t_rect){elem->pos.x + elem->size.x / 2 - elem->size.x / 4, elem->pos.y + elem->size.y / 2 - elem->size.y / 4, elem->size.x / 2, elem->size.y / 2}, "img/brush.bmp", win, NULL, NULL, NULL, NULL, &button_render);
	elem->sub_group = add_group_e(elem->sub_group, img, NULL);
	img->parent = elem;
	add_element_to_win(win, elem = init_button_to_win((t_rect){50, 0, 50, 50}, "./img/button_1.bmp", win, NULL, NULL, NULL, &button_render));
	img = init_image_to_win((t_rect){elem->pos.x + elem->size.x / 2 - elem->size.x / 4, elem->pos.y + elem->size.y / 2 - elem->size.y / 4, elem->size.x / 2, elem->size.y / 2}, "img/eraser.bmp", win, NULL, NULL, NULL, NULL, &button_render);
	elem->sub_group = add_group_e(elem->sub_group, img, NULL);
	img->parent = elem;
	add_element_to_win(win, elem = init_button_to_win((t_rect){0, 50, 50, 50}, "./img/button_1.bmp", win, NULL, NULL, NULL, &button_render));
	img = init_image_to_win((t_rect){elem->pos.x + elem->size.x / 2 - elem->size.x / 4, elem->pos.y + elem->size.y / 2 - elem->size.y / 4, elem->size.x / 2, elem->size.y / 2}, "img/pencil.bmp", win, NULL, NULL, NULL, NULL, &button_render);
	elem->sub_group = add_group_e(elem->sub_group, img, NULL);
	img->parent = elem;
	add_element_to_win(win, elem = init_button_to_win((t_rect){50, 50, 50, 50}, "./img/button_1.bmp", win, NULL, NULL, NULL, &button_render));
	img = init_image_to_win((t_rect){elem->pos.x + elem->size.x / 2 - elem->size.x / 4, elem->pos.y + elem->size.y / 2 - elem->size.y / 4, elem->size.x / 2, elem->size.y / 2}, "img/figures.bmp", win, NULL, NULL, NULL, NULL, &button_render);
	elem->sub_group = add_group_e(elem->sub_group, img, NULL);
	img->parent = elem;
	return (win);
}
