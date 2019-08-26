/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 12:20:18 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/26 20:22:16 by rrhaenys         ###   ########.fr       */
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
			SDL_GetMouseState(&g_sdl_data->mouse.x, &g_sdl_data->mouse.y);
			active_win = get_active_win(&ev);
			if (is_event_close_win(&ev))
				destroy_win(active_win);
			if (ev.type == SDL_QUIT || ui_wins_count() == 1 || touch_esc(&ev))
				run = 0;
			if (active_win != NULL)
				ft_printf("%d %d %d %d %f\n",
					active_win->win_rect.x, active_win->win_rect.y,
					active_win->win_rect.w, active_win->win_rect.h, active_win->scale);
			if (active_win == NULL)
				;
			else if(ev.type == SDL_MOUSEWHEEL)
			{
				ft_printf("wheel %d %d\n", ev.wheel.x, ev.wheel.y);
				if (active_win->mouse_muve_scrole && g_sdl_data->draw_type == NO_DRAW)
					active_win->mouse_muve_scrole(active_win, (t_point){ev.wheel.x, ev.wheel.y});
			}
			else if (ev.type == SDL_MOUSEBUTTONUP)
				mousebuttonup_win(active_win, &ev);
			else if (ev.type == SDL_MOUSEBUTTONDOWN)
				mousebuttondown_win(active_win, &ev);
			else if (ev.type == SDL_MOUSEMOTION)
				mousebuttonmove_win(active_win, &ev);
		}
		ft_update_win_surface();
	}
}
