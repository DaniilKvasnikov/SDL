/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_button_press.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 17:01:14 by gamerd            #+#    #+#             */
/*   Updated: 2019/08/13 09:07:11 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	ft_button_press(void *mydata, void *win, SDL_Event *ev)
{
	if (((t_win *)win)->active_element != NULL && ((t_win *)win)->active_element->keyboard_press != NULL)
		((t_win *)win)->active_element->keyboard_press(win, ((t_win *)win)->active_element, ev);
	if(((t_mydata *)mydata)->keyboardState[SDL_SCANCODE_ESCAPE])
	{
		while (((t_mydata *)mydata)->keyboardState[SDL_SCANCODE_ESCAPE])
			SDL_PumpEvents();
		ft_delete_win((t_mydata *)mydata, ((t_win *)win)->window_id);
	}
}