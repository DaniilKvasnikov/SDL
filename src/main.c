/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 12:14:56 by gamerd            #+#    #+#             */
/*   Updated: 2019/08/06 19:41:46 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

int main(int argc, char **argv)
{
	t_mydata	*mydata;
	int			i;

	if (argc == 1)
		return (0);
	if((mydata = (t_mydata *)malloc(sizeof(t_mydata))) == NULL)
		exit(1);
	mydata->win_count = 0;
	mydata->keyboardState = SDL_GetKeyboardState(NULL);
	if (ft_sdl_init() != 0)
		exit(1);
	i = 0;
	while (++i < argc)
		ft_add_win(mydata, ft_init_win(argv[i], (t_point){100, 100}, (t_point){640, 480}, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE));

	add_button_to_win((SDL_Rect){0, 0, 100, 50}, "./img/cat.bmp", mydata->wins[0]);
	add_button_to_win((SDL_Rect){100, 100, 50, 100}, "./img/cat.bmp", mydata->wins[0]);

	SDL_Event	ev;
	int			run;

	run = 1;
	while (run == 1)
	{
		render_wins(mydata);
		while (SDL_PollEvent(&ev) != 0)
		{
			SDL_PumpEvents();
			ft_printf("%d\n", ev.type);
			ft_run_mouse_fun(mydata, ev);
			ft_run_keyboard_fun(mydata, ev);
			if (mydata->win_count == 0 || ev.type == 256)
				run = 0;
		}
		ft_update_win_surface(mydata);
	}

	// SDL_DestroyTexture(mydata->tex);
	ft_destroy_wins(mydata);
	free(mydata);
	SDL_Quit();

	return EXIT_SUCCESS;
}