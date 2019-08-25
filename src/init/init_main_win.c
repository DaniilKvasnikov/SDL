/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 11:30:30 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 12:25:29 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

void
	init_main_win(char *name)
{
	t_win	*win;

	win = ui_init_win(ft_strdup(name), (t_rect){200, 200, 640, 480},
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE, &main_win_fun);
	ui_add_win(win);
}
