/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_keyboard_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamerd <gamerd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 16:41:40 by gamerd            #+#    #+#             */
/*   Updated: 2019/07/20 13:51:48 by gamerd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	ft_run_keyboard_fun(t_mydata *mydata, SDL_Event ev)
{
	t_win *win;

	// ft_printf("type %d\n", ev.type);
	// if (ev.type == SDL_QUIT)
	// 	ft_printf("id %d exit\n", ev.window.windowID);
	// else
	// 	ft_printf("id %d other\n", ev.window.windowID);
	win = ft_get_win_from_id(mydata, ev.window.windowID);
	if (win == NULL)
		return ;
	// ft_printf("id %d\n", ev.window.windowID);
	if (win->button_press != NULL)
		win->button_press(mydata, win, &ev);
}