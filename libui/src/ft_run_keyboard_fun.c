/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_keyboard_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 16:41:40 by gamerd            #+#    #+#             */
/*   Updated: 2019/08/13 08:41:01 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	ft_run_keyboard_fun(t_mydata *mydata, SDL_Event ev)
{
	t_win *win;

	win = ft_get_win_from_id(mydata, ev.window.windowID);
	if (win == NULL)
		return ;
	if (win->button_press != NULL)
		win->button_press(mydata, win, &ev);
}