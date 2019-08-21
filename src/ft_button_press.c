/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_button_press.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 17:01:14 by gamerd            #+#    #+#             */
/*   Updated: 2019/08/21 09:59:44 by rrhaenys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sdl.h"

void
	ft_button_press(void *mydata, void *win, SDL_Event *ev)
{
	if (((t_win *)win)->active_element != NULL && ((t_win *)win)->active_element->keyboard_press != NULL)
	{
		textline_keyboard(win, ((t_win *)win)->active_element, ev,
			((t_win *)win)->active_element->keyboard_press);
	}
}