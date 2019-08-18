/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:14:56 by gamerd            #+#    #+#             */
/*   Updated: 2019/08/18 17:07:44 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int main(int argc, char **argv)
{
	t_mydata	*mydata;

	if((mydata = init_mydata()) == NULL)
		exit(1);
	if (ft_sdl_init() != 0)
		exit(1);
	t_win *main;
	ft_add_win(mydata, main = ft_init_win(mydata, "Main", (t_rect){100, 100, 640, 480}, SDL_WINDOW_SHOWN));
	main->ctrl_c = ctrl_c_win;
	main->ctrl_v = ctrl_v_win;

	add_element_to_win(mydata->wins[0], init_image_to_win((t_rect){50, 25, 100, 100}, "./img/cat.bmp", mydata->wins[0], &element_touch, &image_pressed, &active_elem, &img_to_layer, &button_render));

	t_element *menulist = add_element_to_win(mydata->wins[0], init_menulist_to_win((t_rect){0, 0, 100, 50}, "./img/button_1.bmp", mydata->wins[0], "File", &menulist_touch, &active_elem, &dropdownlist_render));
	
	t_element *img = init_image_to_win((t_rect){menulist->pos.x + menulist->size.x / 10, menulist->pos.y + menulist->size.y / 4, menulist->size.x / 5, menulist->size.y / 2}, "./img/cat.bmp", mydata->wins[0], NULL, NULL, NULL, NULL, &button_render);
	menulist->sub_group = add_group_e(menulist->sub_group, img, NULL);
	img->parent = menulist;
	t_element *but1 = init_button_to_win((t_rect){menulist->pos.x, menulist->pos.y + menulist->size.y, menulist->size.x, menulist->size.y}, "./img/button_1.bmp", mydata->wins[0], "Button1", &element_touch, NULL, &button_render);
	t_element *but2 = init_button_to_win((t_rect){menulist->pos.x, menulist->pos.y + menulist->size.y * 2, menulist->size.x, menulist->size.y}, "./img/button_1.bmp", mydata->wins[0], "Button2", &element_touch, NULL, &button_render);
	menulist->sub_group = add_group_e(menulist->sub_group, but1, NULL);
	but1->parent = menulist;
	menulist->sub_group = add_group_e(menulist->sub_group, but2, NULL);
	but2->parent = menulist;
	
	t_element *winlist = add_element_to_win(mydata->wins[0], init_menulist_to_win((t_rect){100, 0, 100, 50}, "./img/button_1.bmp", mydata->wins[0], "Windows", &menulist_touch, &active_elem, &dropdownlist_render));
	
	t_element *winlist_sub = init_menulist_to_win((t_rect){winlist->pos.x, winlist->pos.y + winlist->size.y, winlist->size.x, winlist->size.y}, "./img/button_1.bmp", mydata->wins[0], "Sub", &menulist_touch, &active_elem, &dropdownlist_render);
	winlist->sub_group = add_group_e(winlist->sub_group, winlist_sub, NULL);
	winlist_sub->parent = winlist;

	t_element *but3 = init_button_to_win((t_rect){winlist_sub->pos.x + winlist_sub->size.x, winlist_sub->pos.y, winlist_sub->size.x, winlist_sub->size.y}, "./img/button_1.bmp", mydata->wins[0], "Button3", &element_touch, NULL, &button_render);
	winlist_sub->sub_group = add_group_e(winlist_sub->sub_group, but3, NULL);
	but3->parent = winlist_sub;
	t_element *img2 = init_image_to_win((t_rect){but3->pos.x + but3->size.x / 10, but3->pos.y + but3->size.y / 4, but3->size.x / 5, but3->size.y / 2}, "./img/cat.bmp", mydata->wins[0], NULL, NULL, NULL, NULL, &button_render);
	but3->sub_group = add_group_e(but3->sub_group, img2, NULL);
	img2->parent = but3;
	
	t_rect rect_win = (t_rect){300, 0, 300, 300};
	draw_text_to_target_tex(mydata->wins[0], get_texture_to_win(mydata->wins[0], "./img/cat.bmp"), 0, &rect_win, NULL);
	rect_win = (t_rect){200, 0, 100, 100};
	draw_text_to_target_tex(mydata->wins[0], get_texture_to_win(mydata->wins[0], "./img/cat.bmp"), 0, &rect_win, NULL);

	// add_element_to_win(mydata->wins[0], init_button_to_win((t_rect){0, 0, 100, 50}, "./img/button_1.bmp", mydata->wins[0], "butt1", &element_touch, &active_elem, &button_render));
	// add_element_to_win(mydata->wins[0], init_button_to_win((t_rect){0, 50, 100, 50}, "./img/button_1.bmp", mydata->wins[0], "butt2", &element_touch, &active_elem, &button_render));
	// add_element_to_win(mydata->wins[0], init_checkbox_to_win((t_rect){200, 200, 50, 50}, "img/unchecked_checkbox.bmp", "img/checked_checkbox.bmp", mydata->wins[0], &checkbox_touch, &active_elem, &checkbox_render));
	// add_element_to_win(mydata->wins[0], init_checkbox_to_win((t_rect){200, 250, 50, 50}, "img/unchecked_checkbox.bmp", "img/checked_checkbox.bmp", mydata->wins[0], &checkbox_touch, &active_elem, &checkbox_render));

	// t_element *radiobutton1 = add_element_to_win(mydata->wins[0], init_checkbox_to_win((t_rect){250, 200, 50, 50}, "img/unchecked_checkbox.bmp", "img/checked_checkbox.bmp", mydata->wins[0], &radiobutton_touch, &active_elem, &checkbox_render));
	// t_element *radiobutton2 = add_element_to_win(mydata->wins[0], init_checkbox_to_win((t_rect){250, 250, 50, 50}, "img/unchecked_checkbox.bmp", "img/checked_checkbox.bmp", mydata->wins[0], &radiobutton_touch, &active_elem, &checkbox_render));

	// mydata->wins[0]->groupe = add_group_e(mydata->wins[0]->groupe, radiobutton1, &gr_cheacker);
	// mydata->wins[0]->groupe = add_group_e(mydata->wins[0]->groupe, radiobutton2, NULL);

	// t_element *sliders = add_element_to_win(mydata->wins[0], init_sliders_to_win((t_rect){0, 300, 200, 50}, "./img/button_1.bmp", "img/unchecked_checkbox.bmp", mydata->wins[0], &element_touch, &sliders_pressed, &active_elem, &sliders_render));
	// t_element *progress_bar = add_element_to_win(mydata->wins[0], init_progressbar((t_rect){200, 0, 200, 100}, "./img/button_1.bmp", "./img/cat.bmp", mydata->wins[0], &progressbar_render));
	// add_element_to_win(mydata->wins[0], init_textline((t_rect){400, 0, 200, 100}, "./img/button_1.bmp", mydata->wins[0], ft_strdup("Input:"), &element_touch, &textline_keyboard, &active_elem, &button_render));

	// char	**strs = ft_strsplit("1 2 3 4 5", ' ');
	// add_element_to_win(mydata->wins[0], init_dropdownlist_to_win((t_rect){0, 100, 100, 50}, "./img/button_1.bmp", mydata->wins[0], strs, NULL, &dropdownlist_touch, &active_elem, NULL, &dropdownlist_render, &button_render));
	run_main_loop(mydata);
	ft_destroy_wins(mydata);
	free(mydata);
	SDL_Quit();

	return EXIT_SUCCESS;
}