/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 12:20:18 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 13:24:12 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	run_loop(void)
{
	SDL_Event	ev;
	int			run;
	t_win		*active_win;

	run = 1;
	while (run == 1)
	{
		draw_wins();
		while (SDL_PollEvent(&ev) != 0)
		{
			SDL_PumpEvents();
			active_win = get_active_win(&ev);
			if (is_event_close_win(&ev))
				destroy_win(active_win);
			if (ev.type == SDL_QUIT || ui_wins_count() == 1 || touch_esc(&ev))
				run = 0;
			if (ev.type == SDL_MOUSEBUTTONUP)
				mousebuttonup_win(active_win, &ev);
			else if (ev.type == SDL_MOUSEBUTTONDOWN)
				mousebuttondown_win(active_win, &ev);
			else if (ev.type == SDL_MOUSEMOTION)
				mousebuttonmove_win(active_win, &ev);
		}
	}
}
