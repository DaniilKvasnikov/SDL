/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 20:02:26 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/22 13:17:23 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

t_win
	*create_main(t_mydata *mydata, char *name)
{
	t_win		*main;
	ft_add_win(mydata, main = ft_init_win(mydata, name, (t_rect){200, 100, 640, 480}, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE, &ft_button_press));
	main->fun_close = &main_close;
	main->ctrl_c = ctrl_c_win;
	main->ctrl_v = ctrl_v_win;

	add_element_to_win(main, init_image_to_win((t_rect){50, 25, 100, 100}, "./img/cat.bmp", main, &element_touch, &image_pressed, &active_elem, &img_to_layer, &image_render));

	t_element *menulist = add_element_to_win(main, init_menulist_to_win((t_rect){0, 0, 100, 50}, "./img/button_1.bmp", main, "File", &menulist_touch, &active_elem, &dropdownlist_render));
	
	
	t_element *img = init_image_to_win((t_rect){menulist->rect.x + menulist->rect.w / 10, menulist->rect.y + menulist->rect.h / 4, menulist->rect.w / 5, menulist->rect.h / 2}, "./img/cat.bmp", main, NULL, NULL, NULL, NULL, &button_render);
	menulist->sub_group = add_group_e(menulist->sub_group, img, NULL);
	img->parent = menulist;
	t_element *but1 = init_button_to_win((t_rect){menulist->rect.x, menulist->rect.y + menulist->rect.h, menulist->rect.w, menulist->rect.h}, "./img/button_1.bmp", main, "Button1", &element_touch, NULL, &button_render);
	t_element *but2 = init_button_to_win((t_rect){menulist->rect.x, menulist->rect.y + menulist->rect.h * 2, menulist->rect.w, menulist->rect.h}, "./img/button_1.bmp", main, "Button2", &element_touch, NULL, &button_render);
	menulist->sub_group = add_group_e(menulist->sub_group, but1, NULL);
	but1->parent = menulist;
	menulist->sub_group = add_group_e(menulist->sub_group, but2, NULL);
	but2->parent = menulist;
	
	t_element *winlist = add_element_to_win(main, init_menulist_to_win((t_rect){100, 0, 100, 50}, "./img/button_1.bmp", main, "Windows", &menulist_touch, &active_elem, &dropdownlist_render));
	
	t_element *winlist_sub = init_menulist_to_win((t_rect){winlist->rect.x, winlist->rect.y + winlist->rect.h, winlist->rect.w, winlist->rect.h}, "./img/button_1.bmp", main, "Sub", &menulist_touch, &active_elem, &dropdownlist_render);
	winlist->sub_group = add_group_e(winlist->sub_group, winlist_sub, NULL);
	winlist_sub->parent = winlist;

	t_element *but3 = init_button_to_win((t_rect){winlist_sub->rect.x + winlist_sub->rect.w, winlist_sub->rect.y, winlist_sub->rect.w, winlist_sub->rect.h}, "./img/button_1.bmp", main, "Button3", &element_touch, NULL, &button_render);
	winlist_sub->sub_group = add_group_e(winlist_sub->sub_group, but3, NULL);
	but3->parent = winlist_sub;
	t_element *img2 = init_image_to_win((t_rect){but3->rect.x + but3->rect.w / 10, but3->rect.y + but3->rect.h / 4, but3->rect.w / 5, but3->rect.h / 2}, "./img/cat.bmp", main, NULL, NULL, NULL, NULL, &button_render);
	but3->sub_group = add_group_e(but3->sub_group, img2, NULL);
	img2->parent = but3;
	
	t_rect rect_win = (t_rect){300, 0, 300, 300};
	draw_text_to_target_tex(main, get_texture_to_win(main, "./img/cat.bmp"), 2, &rect_win, NULL);
	rect_win = (t_rect){200, 0, 100, 100};
	draw_text_to_target_tex(main, get_texture_to_win(main, "./img/cat.bmp"), 2, &rect_win, NULL);
	return (main);
}