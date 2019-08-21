/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_keyboard_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 16:41:40 by gamerd            #+#    #+#             */
/*   Updated: 2019/08/21 09:59:31 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

static int
	ctrl_c_v(t_mydata *mydata, SDL_Event *ev, t_win *win)
{
	int ctrl =  ((t_mydata *)mydata)->keyboardState[SDL_SCANCODE_LCTRL];
	int c = ev->key.keysym.scancode == SDL_SCANCODE_C;
	int c_status = ((t_mydata *)mydata)->keyboardState[SDL_SCANCODE_C];
	int v = ev->key.keysym.scancode == SDL_SCANCODE_V;
	int v_status = ((t_mydata *)mydata)->keyboardState[SDL_SCANCODE_V];
	if (ev->type == SDL_KEYDOWN && ctrl != 0)
	{
		if (c_status && ((t_mydata *)mydata)->ctrl_c == 0)
		{
			if (((t_win *)win)->ctrl_c != NULL)
				((t_win *)win)->ctrl_c(win, ev);
			((t_mydata *)mydata)->ctrl_c = 1;
		}
		if (v_status && ((t_mydata *)mydata)->ctrl_v == 0)
		{
			if (((t_win *)win)->ctrl_v != NULL)
				((t_win *)win)->ctrl_v(win, ev);
			((t_mydata *)mydata)->ctrl_v = 1;
		}
		return (1);
	}
	if (ev->type == SDL_KEYUP)
	{
		if (c)
			((t_mydata *)mydata)->ctrl_c = 0;
		if (v)
			((t_mydata *)mydata)->ctrl_v = 0;
	}
	return (0);
}

void
	ft_run_keyboard_fun(t_mydata *mydata, SDL_Event *ev)
{
	t_win *win;

	win = ft_get_win_from_id(mydata, ev->window.windowID);
	if (win == NULL)
		return ;
	if (mydata->keyboardState[SDL_SCANCODE_ESCAPE])
		exit(0);
	if(ev->type == SDL_WINDOWEVENT && ev->window.event == SDL_WINDOWEVENT_CLOSE)
	{
		if (win->fun_close)
			win->fun_close(win);
		ft_delete_win(mydata, win->window_id);
	}
	if (!ctrl_c_v(mydata, ev, win) && win->button_press != NULL)
	{
		win->button_press(mydata, win, ev);
	}
}
