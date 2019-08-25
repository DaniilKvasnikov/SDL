/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 12:58:29 by rrhaenys          #+#    #+#             */
/*   Updated: 2019/08/25 12:59:49 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_guimp.h"

void
	init_info_win(char *name)
{
	t_win	*win;

	win = ui_init_win(ft_strdup(name), (t_rect){100, 200, 100, 480},
		SDL_WINDOW_SHOWN, &info_win_fun);
	ui_add_win(win);
}
