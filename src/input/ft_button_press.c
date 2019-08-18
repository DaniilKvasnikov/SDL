/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_button_press.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 17:01:14 by gamerd            #+#    #+#             */
/*   Updated: 2019/08/18 04:04:06 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	ft_button_press(void *mydata, void *win, SDL_Event *ev)
{
	int ctrl =  ((t_mydata *)mydata)->keyboardState[SDL_SCANCODE_LCTRL];
	int c = ev->key.keysym.scancode == SDL_SCANCODE_C;
	int c_status = ((t_mydata *)mydata)->keyboardState[SDL_SCANCODE_C];
	int v = ev->key.keysym.scancode == SDL_SCANCODE_V;
	int v_status = ((t_mydata *)mydata)->keyboardState[SDL_SCANCODE_V];
	if (ev->type == SDL_KEYDOWN && ctrl)
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
	}
	if (ev->type == SDL_KEYUP)
	{
		if (c)
			((t_mydata *)mydata)->ctrl_c = 0;
		if (v)
			((t_mydata *)mydata)->ctrl_v = 0;
	}
	// else if (ev->type == SDL_KEYDOWN && ctrl && v && ((t_mydata *)mydata)->ctrl_v == 0)
	// 	ft_printf("scancod v %d %d\n", ctrl, v);
	// ft_printf("scancode %d\n", ev->key.keysym.scancode);
	if (((t_win *)win)->active_element != NULL && ((t_win *)win)->active_element->keyboard_press != NULL)
		((t_win *)win)->active_element->keyboard_press(win, ((t_win *)win)->active_element, ev);
	if(((t_mydata *)mydata)->keyboardState[SDL_SCANCODE_ESCAPE] ||
		(ev->type == SDL_WINDOWEVENT && ev->window.event == SDL_WINDOWEVENT_CLOSE))
	{
		while (((t_mydata *)mydata)->keyboardState[SDL_SCANCODE_ESCAPE])
			SDL_PumpEvents();
		int seve_screen = save_screenshot_bmp("screen.bmp", ((t_win *)win)->win, ((t_win *)win)->ren);
		ft_printf("seve_screen = %d\n", seve_screen);
		ft_delete_win((t_mydata *)mydata, ((t_win *)win)->window_id);
	}
}