/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:14:56 by gamerd            #+#    #+#             */
/*   Updated: 2019/08/15 09:18:43 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int main(int argc, char **argv)
{
	t_mydata	*mydata;

	if((mydata = init_mydata()) == NULL)
		exit(1);
	if (ft_sdl_init(SDL_INIT_EVERYTHING) != 0)
		exit(1);
	ft_add_win(mydata, ft_init_win(mydata, "Main", (t_rect){100, 100, 640, 480},
		SDL_WINDOW_SHOWN));
	ft_add_win(mydata, ft_init_win(mydata, "Dop", (t_rect){740, 100, 100, 100},
		SDL_WINDOW_SHOWN | SDL_WINDOW_ALWAYS_ON_TOP));

	add_button_to_win((t_rect){0, 0, 100, 50}, "./img/button_1.bmp", mydata->wins[0], "butt1", &element_touch, &button_render);
	add_button_to_win((t_rect){0, 50, 100, 50}, "./img/button_1.bmp", mydata->wins[0], "butt2", &element_touch, &button_render);
	add_image_to_win((t_rect){50, 25, 100, 100}, "./img/cat.bmp", mydata->wins[0], &button_render);
	add_checkbox_to_win((t_rect){200, 200, 50, 50}, "img/unchecked_checkbox.bmp", "img/checked_checkbox.bmp", mydata->wins[0], &checkbox_touch, &checkbox_render);
	add_checkbox_to_win((t_rect){200, 250, 50, 50}, "img/unchecked_checkbox.bmp", "img/checked_checkbox.bmp", mydata->wins[0], &checkbox_touch, &checkbox_render);

	add_dropdownlist_to_win((t_rect){0, 100, 100, 50}, "./img/button_1.bmp", mydata->wins[0], "list", &dropdownlist_touch, &dropdownlist_render);

	t_element *radiobutton1 = add_checkbox_to_win((t_rect){250, 200, 50, 50}, "img/unchecked_checkbox.bmp", "img/checked_checkbox.bmp", mydata->wins[0], &radiobutton_touch, &checkbox_render);
	t_element *radiobutton2 = add_checkbox_to_win((t_rect){250, 250, 50, 50}, "img/unchecked_checkbox.bmp", "img/checked_checkbox.bmp", mydata->wins[0], &radiobutton_touch, &checkbox_render);

	mydata->wins[0]->groupe = add_group_e(mydata->wins[0]->groupe, radiobutton1, &gr_cheacker);
	mydata->wins[0]->groupe = add_group_e(mydata->wins[0]->groupe, radiobutton2, NULL);

	t_element *sliders = add_sliders_to_win((t_rect){100, 300, 100, 50}, "./img/button_1.bmp", "img/unchecked_checkbox.bmp", mydata->wins[0], &element_touch, &sliders_pressed, &sliders_render);
	t_element *progress_bar = add_progressbar((t_rect){200, 0, 200, 100}, "./img/button_1.bmp", "./img/cat.bmp", mydata->wins[0], &progressbar_render);
	add_textline((t_rect){400, 0, 200, 100}, "./img/button_1.bmp", mydata->wins[0], &element_touch, &textline_keyboard, &button_render);

	SDL_Event	ev;
	int			run;

	run = 1;
	while (run == 1)
	{
		render_wins(mydata);
		while (SDL_PollEvent(&ev) != 0)
		{
			SDL_PumpEvents();
			ft_run_mouse_fun(mydata, &ev);
			ft_run_keyboard_fun(mydata, ev);
			if (mydata->win_count == 0 || ev.type == 256)
				run = 0;
			progress_bar->float_par = sliders->float_par;
		}
		ft_update_win_surface(mydata);
	}

	ft_destroy_wins(mydata);
	free(mydata);
	SDL_Quit();

	return EXIT_SUCCESS;
}