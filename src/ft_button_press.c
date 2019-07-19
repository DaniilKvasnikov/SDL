/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_button_press.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamerd <gamerd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 17:01:14 by gamerd            #+#    #+#             */
/*   Updated: 2019/07/19 19:16:41 by gamerd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	ft_button_press(void *mydata, void *win)
{
	if(((t_mydata *)mydata)->keyboardState[SDL_SCANCODE_ESCAPE])
	{
		while (((t_mydata *)mydata)->keyboardState[SDL_SCANCODE_ESCAPE])
			SDL_PumpEvents();
		ft_delete_win((t_mydata *)mydata, ((t_win *)win)->window_id);
	}
	else if(((t_mydata *)mydata)->keyboardState[SDL_SCANCODE_W])
	{
		ft_init_texture((t_win *)win, "./img/cat.bmp");
	}
}