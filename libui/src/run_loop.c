/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyabaturin <ilyabaturin@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 12:20:18 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/28 09:13:34 by ilyabaturin      ###   ########.fr       */
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
			if (active_win == NULL)
				;
			else if(ev.type == SDL_MOUSEWHEEL)
			{
				ft_printf("wheel %d %d\n", ev.wheel.x, ev.wheel.y);
				if (active_win->mouse_muve_scrole)
					active_win->mouse_muve_scrole(active_win, (t_point){ev.wheel.x, ev.wheel.y});
			}
			else if (ev.type == SDL_MOUSEBUTTONUP)
				mousebuttonup_win(active_win, &ev);
			else if (ev.type == SDL_MOUSEBUTTONDOWN)
				mousebuttondown_win(active_win, &ev);
			else if (ev.type == SDL_MOUSEMOTION)
				mousebuttonmove_win(active_win, &ev);
			else
			{
				if (active_win && active_win->active_elem && active_win->active_elem->keyboard_down)
					active_win->active_elem->keyboard_down(active_win->active_elem, &ev);
			}
		}
		ft_update_win_surface();
	}
}
