/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_main_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 17:06:25 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/20 12:55:38 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	run_main_loop(t_mydata *mydata)
{	
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
			ft_run_keyboard_fun(mydata, &ev);
			if (mydata->win_count == 0 || ev.type == SDL_QUIT)
				run = 0;
		}
		ft_update_win_surface(mydata);
	}
}