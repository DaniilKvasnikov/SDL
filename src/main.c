/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:14:56 by gamerd            #+#    #+#             */
/*   Updated: 2019/08/09 16:58:43 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int main(int argc, char **argv)
{
	t_mydata	*mydata;
	int			i;

	if (argc == 1)
		return (0);
	if((mydata = init_mydata()) == NULL)
		exit(1);
	if (ft_sdl_init() != 0)
		exit(1);
	i = 0;
	while (++i < argc)
		ft_add_win(mydata, ft_init_win(mydata, argv[i], (t_rect){100, 100, 640, 480}, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE));

	add_button_to_win((t_rect){0, 0, 100, 50}, "./img/cat.bmp", mydata->wins[0], &button_pressed);
	add_button_to_win((t_rect){100, 100, 50, 100}, "./img/cat.bmp", mydata->wins[0], &button_pressed);

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
		}
		ft_update_win_surface(mydata);
	}

	ft_destroy_wins(mydata);
	free(mydata);
	SDL_Quit();

	return EXIT_SUCCESS;
}